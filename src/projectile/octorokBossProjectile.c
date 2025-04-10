#include "entity.h"
#include "collision.h"
#include "enemy.h"
#include "functions.h"
#include "projectile.h"

void OctorokBossProjectile_Action2(Entity*);

extern void (*const OctorokBossProjectile_Functions[])(Entity*);
extern void (*const OctorokBossProjectile_Actions[])(Entity*);
extern const u8 gUnk_08129ADC[];

enum OctorokBossProjectileType {
    TYPE0, // rock
    TYPE1, // rock fragment
    TYPE2,
    TYPE3 // falling stones
};

void OctorokBossProjectile(Entity* this) {
    OctorokBossProjectile_Functions[GetNextFunction(this)](this);
}

void OctorokBossProjectile_OnTick(Entity* this) {
    OctorokBossProjectile_Actions[this->action](this);
}

void OctorokBossProjectile_Init(Entity* this) {
    u32 uVar1;
    u32 uVar2;

    this->action = 1;

    switch (this->type) {
        case 0:
            LinearMoveAngle(this, 0x4800, this->direction);
            this->speed = 0x200;
            this->timer = 0;
            this->subtimer = this->direction;
            this->field_0x78.HWORD = 300;
            InitAnimationForceUpdate(this, 0);
            break;
        case 1:
            this->spriteRendering.b3 = 3;
            this->spritePriority.b0 = 6;
            this->speed = (Random() & 0x1ff) + 0x200;
            this->zVelocity = (Random() & 0x1fff) + Q_16_16(1.5);
            uVar1 = (((u8)Random() & 7) - 4);
            this->direction -= uVar1;
            *(u32*)&this->field_0x78 = 600;
            LinearMoveAngle(this, this->speed, this->direction);
            InitializeAnimation(this, 4);
            break;
        case 2:
            if ((Random() & 1) != 0) {
                this->direction = (Random() & 7) + this->direction;
            } else {
                this->direction = this->direction - (Random() & 7);
            }
            this->speed = 0x200;
            this->timer = 48;
            LinearMoveAngle(this, 0x5000, this->direction);
            InitializeAnimation(this, 5);
            break;
        case 3:
            CopyPosition(&gPlayerEntity, this);
            this->z.WORD = Q_16_16(-160.0);
            this->x.HALF.HI += 0x60;
            this->y.HALF.HI += 0x40;
            this->x.HALF.HI -= (s32)Random() % 0xc0;
            uVar2 = Random() & 0x7f;
            this->y.HALF.HI -= uVar2;
            InitializeAnimation(this, 0);
            break;
    }

    SoundReq(SFX_1B5);
}

void OctorokBossProjectile_Action1(Entity* this) {
    u32 index;

    switch (this->type) {
        case 0:
            if (this->parent->action == 2) {
                DeleteThisEntity();
            }
            if ((this->type2 == 0) && ((this->contactFlags & 0x80) != 0)) {
                if ((this->contactFlags & 0x7f) == 0) {
                    OctorokBossProjectile_Action2(this);
                }
                this->direction = this->knockbackDirection << 3;
                this->speed = 0x400;
                this->type2 = 1;
                this->timer = 0;
                COLLISION_OFF(this);
            }
            if (sub_0806FC80(this, this->parent, 0x40) != 0) {
                if (this->type2 == 0) {
                    this->direction ^= 0x80;
                    this->speed = 0x400;
                } else {
                    this->parent->health--;
                    this->parent->iframes = 0x1e;
                    if (this->parent->field_0x7c.BYTES.byte0 != 0) {
                        this->parent->knockbackDuration = 0x18;
                        this->parent->knockbackSpeed = 0x200;
                        this->parent->knockbackDirection = this->direction >> 3;
                    }
                    SoundReq(SFX_BOSS_HIT);
                    OctorokBossProjectile_Action2(this);
                }
            }
            UpdateAnimationSingleFrame(this);
            this->field_0x78.HWORD--;
            LinearMoveAngle(this, this->speed, this->direction);
            CalculateEntityTileCollisions(this, this->direction >> 3, 0);
            if ((this->collisions & (COL_WEST_ANY | COL_EAST_ANY)) != COL_NONE) {
                this->direction = -this->direction;
            }
            if ((this->collisions & (COL_NORTH_ANY | COL_SOUTH_ANY)) != COL_NONE) {
                this->direction = -this->direction ^ 0x80;
            }
            if (this->direction == this->subtimer) {
                return;
            }
            SoundReq(SFX_164);
            if (this->field_0x78.HWORD == 0) {
                this->timer = 4;
            } else {
                this->timer++;
            }

            this->subtimer = this->direction;
            if (this->timer < 2) {
                return;
            }
            for (index = 0; index < 3; ++index) {
                this->child = CreateProjectileWithParent(this, OCTOROK_BOSS_PROJECTILE, 1);
                if (this->child != NULL) {
                    this->child->parent = this->parent;
                    this->child->direction = this->direction + gUnk_08129ADC[index];
                    CopyPosition(this, this->child);
                }
            }
            OctorokBossProjectile_Action2(this);
            break;
        case 1:
            if (this->parent->action == 2) {
                OctorokBossProjectile_Action2(this);
            }
            GetNextFrame(this);
            if (GravityUpdate(this, Q_8_8(24.0)) != 0) {
                CalculateEntityTileCollisions(this, this->direction >> 3, 0);
                if (this->collisions == COL_NONE) {
                    LinearMoveAngle(this, (s32)this->speed, (u32)this->direction);
                } else {
                    OctorokBossProjectile_Action2(this);
                }
            }
            if (*(u32*)&this->field_0x78 < 0x1e) {
                if ((*(u32*)&this->field_0x78 & 7) != 0) {
                    this->spriteSettings.draw = 1;
                } else {
                    this->spriteSettings.draw = 0;
                }
            }
            if (--*(u32*)&this->field_0x78 == -1) {
                OctorokBossProjectile_Action2(this);
            }
            if ((this->contactFlags & 0x80) == 0) {
                return;
            }
            OctorokBossProjectile_Action2(this);
            break;
        case 2:
            GetNextFrame(this);
            if (this->timer-- != 0) {
                LinearMoveAngle(this, this->speed, this->direction);
                return;
            }
            if (this->child != NULL) {
                this->child->timer = 1;
            }
            DeleteThisEntity();
            break;
        case 3:
            if (GravityUpdate(this, Q_8_8(24.0)) != 0) {
                return;
            }
            CreateFx(this, FX_ROCK, 0);
            DeleteThisEntity();
            break;
    }
}

void OctorokBossProjectile_Action2(Entity* this) {
    CreateFx(this, FX_ROCK, 0);
    DeleteThisEntity();
}

void (*const OctorokBossProjectile_Functions[])(Entity*) = {
    OctorokBossProjectile_OnTick, OctorokBossProjectile_OnTick, DeleteEntity, DeleteEntity, DeleteEntity,
};
void (*const OctorokBossProjectile_Actions[])(Entity*) = {
    OctorokBossProjectile_Init,
    OctorokBossProjectile_Action1,
    OctorokBossProjectile_Action2,
};
const u8 gUnk_08129ADC[] = {
    0,
    224,
    32,
    0,
};
