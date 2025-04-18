/**
 * @file itemOnGround.c
 * @ingroup Objects
 *
 * @brief Item On Ground object
 */
#include "collision.h"
#include "entity.h"
#include "flags.h"
#include "functions.h"
#include "global.h"
#include "hitbox.h"
#include "item.h"
#include "itemMetaData.h"
#include "object.h"
#include "player.h"
#include "sound.h"

void sub_08081150(Entity*);
u8 sub_0808147C(u32);
void sub_080814A4(Entity*);
u32 sub_080814C0(Entity*);
void sub_08081500(Entity*);
void sub_0808153C(Entity*);
void sub_08081598(Entity*);
void sub_080813BC(Entity*);
void sub_080810FC(Entity*);
void ItemOnGround_Init(Entity*);
void ItemOnGround_Action1(Entity*);
void ItemOnGround_Action2(Entity*);
void ItemOnGround_Action3(Entity*);
void ItemOnGround_Action4(Entity*);
void sub_080810A8(Entity*);
void sub_080810FC(Entity*);
void sub_08081150(Entity*);
void sub_08081134(Entity*);
void sub_08081188(Entity*);
void sub_080811AC(Entity*);
void sub_080811C8(Entity*);
void sub_080811D8(Entity*);
void sub_08081248(Entity*);
void sub_0808126C(Entity*);
void sub_0808127C(Entity*);
void nullsub_113(Entity*);
void sub_080812A0(Entity*);
void sub_080812A8(Entity*);
void sub_080812E8(Entity*);
void nullsub_510(Entity*);
void sub_080813D4(Entity*);
void sub_080813E8(Entity*);
void sub_080813F0(Entity*);
bool32 CheckShouldPlayItemGetCutscene(Entity*);

typedef struct {
    u8 unk0[2];
    u16 sfx;
    u8 unk4;
    u8 unk5[3];
} Unk_0811E84C;

void ItemOnGround(Entity* this) {
    static void (*const ItemOnGround_Actions[])(Entity*) = {
        ItemOnGround_Init, ItemOnGround_Action1, ItemOnGround_Action2, ItemOnGround_Action3, ItemOnGround_Action4,
    };
    if (this->contactFlags & 0x80) {
        switch (this->contactFlags & 0x7F) {
            case 20:
                this->action = 3;
                COLLISION_OFF(this);
                this->spriteSettings.draw = 1;
                this->collisionFlags |= 0x10;
                this->child = this->contactedEntity;
                break;
            case 0:
            case 1:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 30:
                sub_08081598(this);
                break;
        }
    }

    if (sub_0806F520(this)) {
        sub_080813BC(this);
    } else {
        ItemOnGround_Actions[this->action](this);
    }

    if (this->type == 0x5C) {
        gRoomVars.field_0x4++;
    }

    sub_08080CB4(this);
}

void ItemOnGround_Init(Entity* this) {
    static void (*const gUnk_0811E7E8[])(Entity*) = {
        sub_080810A8, sub_080810FC, sub_08081150, sub_08081134, sub_08081188, sub_080810A8,
        sub_080810A8, sub_080811AC, sub_080811C8, sub_080811D8, sub_080810A8,
    };
    if (this->field_0x86.HWORD && CheckFlags(this->field_0x86.HWORD)) {
        DeleteThisEntity();
    }

    if (this->type != ITEM_FAIRY) {
        this->spriteSettings.draw = 1;
        this->spritePriority.b1 = 3;
        this->spriteSettings.shadow = 0;
        this->hitType = 7;
        this->collisionFlags = 0x47;
        this->hurtType = 0x44;
        this->health = 0xFF;
        this->hitbox = (Hitbox*)&gUnk_080FD1A8;
        switch (this->type) {
            case ITEM_SHELLS:
            case ITEM_RUPEE1:
            case ITEM_RUPEE5:
            case ITEM_RUPEE20:
            case ITEM_RUPEE50:
            case ITEM_RUPEE100:
            case ITEM_KINSTONE:
            case ITEM_BOMBS5:
            case ITEM_ARROWS5:
            case ITEM_HEART:
                this->flags2 = 0x17;
                break;
            default:
                this->flags2 = 0x11;
                break;
        }

        this->field_0x68.HALF.HI = this->timer;
        this->field_0x6a.HALF.LO = 0;
        this->field_0x6c.HWORD = 0;
        this->field_0x68.HALF.LO = 0;
        this->timer = 0;
        SetDefaultPriority(this, PRIO_NO_BLOCK);
        this->gustJarFlags = sub_0808147C(this->type);
        gUnk_0811E7E8[this->field_0x68.HALF.HI](this);
    } else {
        Entity* entity = CreateObject(FAIRY, 0x60, 0);
        if (entity != NULL) {
            entity->timer = 0;
            if (this->timer == 1) {
                entity->type2 = 2;
            }
            CopyPosition(this, entity);
            DeleteThisEntity();
        }
    }
}

void sub_080810A8(Entity* this) {
    this->action = 1;
    sub_080814A4(this);
    if (this->direction & 0x80) {
        this->direction &= 0x1F;
        if (this->speed == 0) {
            this->speed = 0x100;
        }
    } else {
        this->direction |= 0xFF;
    }

    if (this->zVelocity == 0) {
        this->zVelocity = Q_16_16(1.875);
    }

    if (this->collisionLayer == 2) {
        ResolveCollisionLayer(this);
    }
}

void sub_080810FC(Entity* this) {
    if (this->type != ITEM_HEART) {
        sub_08081598(this);
    } else {
        this->action = 2;
        this->subAction = 0;
        COLLISION_ON(this);
        this->flags2 = 0x11;
        CopyPosition(&gPlayerEntity, this);
    }
}

void sub_08081134(Entity* this) {
    sub_080814A4(this);
    this->field_0x6c.HWORD += 80;
    sub_08081150(this);
}

void sub_08081150(Entity* this) {
    this->action = 2;
    COLLISION_ON(this);
    this->z.HALF.HI = -0x80;
    this->spriteOrientation.flipY = 1;
    this->spriteRendering.b3 = 1;
    SoundReq(SFX_12D);
}

void sub_08081188(Entity* this) {
    this->action = 2;
    COLLISION_ON(this);
    if (this->collisionLayer == 2) {
        ResolveCollisionLayer(this);
    }
}

void sub_080811AC(Entity* this) {
    this->action = 2;
    this->spriteSettings.draw = 0;
    this->field_0x6e.HWORD = GetTileTypeByEntity(this);
}

void sub_080811C8(Entity* this) {
    this->action = 2;
    this->spriteSettings.draw = 0;
}

void sub_080811D8(Entity* this) {
    sub_08081188(this);
    SoundReq(SFX_215);
}

void ItemOnGround_Action1(Entity* this) {
    if (this->field_0x68.HALF.HI != 6) {
        ProcessMovement2(this);
    } else {
        LinearMoveUpdate(this);
    }

    GravityUpdate(this, Q_8_8(40.0));
    if (this->zVelocity <= 0) {
        this->action = 2;
        COLLISION_ON(this);
        sub_080814A4(this);
    }
}

void ItemOnGround_Action2(Entity* this) {
    static void (*const gUnk_0811E814[])(Entity*) = {
        sub_08081248, sub_08081248, sub_0808126C, sub_0808127C, nullsub_113,  sub_080812A0,
        sub_08081248, sub_080812A8, sub_080812E8, nullsub_510,  sub_08081248,
    };
    gUnk_0811E814[this->field_0x68.HALF.HI](this);
}

void sub_08081248(Entity* this) {
    sub_08081500(this);
    if (sub_080814C0(this)) {
        sub_08081404(this, 0);
    } else {
        sub_0800442E(this);
    }
}

void sub_0808126C(Entity* this) {
    UpdateAnimationSingleFrame(this);
    sub_0808153C(this);
}

void sub_0808127C(Entity* this) {
    if (sub_080814C0(this)) {
        sub_08081404(this, 0);
    } else {
        sub_0808153C(this);
    }
}

void nullsub_113(Entity* this) {
}

void sub_080812A0(Entity* this) {
    sub_08081500(this);
}

void sub_080812A8(Entity* this) {
    if (sub_080B1B0C(this) != 0xF && this->field_0x6e.HWORD != GetTileTypeByEntity(this)) {
        this->direction = 0;
        this->speed = 0;
        this->spriteSettings.draw = 1;
        this->field_0x68.HALF.HI = 0;
        sub_080810A8(this);
    }
}

void sub_080812E8(Entity* this) {
    PlayerState* playerState = &gPlayerState;
#ifdef EU
    if ((playerState->swim_state & 0x80) && IsColliding(this, &gPlayerEntity)) {
#else
    if ((playerState->swim_state & 0x80) && (playerState->flags & PL_MINISH) == 0 &&
        IsColliding(this, &gPlayerEntity)) {
#endif
        sub_080810FC(this);
    }
}

void nullsub_510(Entity* this) {
}

void ItemOnGround_Action3(Entity* this) {
    Entity* other = this->child;
    if (!(other->kind == PLAYER_ITEM && other->id == 3)) {
        sub_08081404(this, 0);
    } else {
        CopyPosition(other, this);
        this->z.HALF.HI--;
        other = &gPlayerEntity;
        if (IsColliding(this, other)) {
            sub_080810FC(this);
        }
    }
}

void ItemOnGround_Action4(Entity* this) {
    if (--this->timer) {
        Entity* other = this->child;
        this->x.WORD = other->x.WORD;
        this->y.WORD = other->y.WORD;
        this->spriteOrientation.flipY = other->spriteOrientation.flipY;
        this->spriteRendering.b3 = other->spriteRendering.b3;
        GravityUpdate(this, Q_8_8(40.0));
    } else {
        sub_08081404(this, 1);
    }
}

void sub_080813BC(Entity* this) {
    static void (*const subActionFuncs[])(Entity*) = {
        sub_080813D4,
        sub_080813E8,
        sub_080813F0,
    };
    subActionFuncs[this->subAction](this);
}

void sub_080813D4(Entity* this) {
    this->subAction = 1;
    this->gustJarTolerance = 1;
    this->spriteSettings.draw = 1;
}

void sub_080813E8(Entity* this) {
    sub_0806F4E8(this);
}

void sub_080813F0(Entity* this) {
    if (sub_0806F3E4(this)) {
        sub_080810FC(this);
    }
}

void sub_08081404(Entity* this, u32 arg1) {
    if (arg1 && this->field_0x86.HWORD) {
        SetFlag(this->field_0x86.HWORD);
    }

    DeleteThisEntity();
}

bool32 sub_08081420(Entity* this) {
    if (CheckShouldPlayItemGetCutscene(this)) {
        SetDefaultPriority(this, PRIO_PLAYER_EVENT);
        CreateItemEntity(this->type, this->type2, 0);
        return TRUE;
    } else {
        GiveItem(this->type, this->type2);
        return FALSE;
    }
}

bool32 CheckShouldPlayItemGetCutscene(Entity* this) {
    return ((gItemMetaData[this->type].unk3 & 0x2) || !GetInventoryValue(this->type));
}

static const Unk_0811E84C gUnk_0811E84C[118] = {
    [ITEM_SHELLS] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_DUNGEON_MAP] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_COMPASS] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_BIG_KEY] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_SMALL_KEY] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE1] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE5] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE20] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE50] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE100] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_RUPEE200] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_KINSTONE] = { { 0x0, 0x0 }, SFX_RUPEE_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_BOMBS5] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_ARROWS5] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
    [ITEM_HEART] = { { 0x0, 0x0 }, SFX_HEART_BOUNCE, 0x1, { 0x0, 0x0, 0x0 } },
};

u8 sub_0808147C(u32 arg0) {
    const Unk_0811E84C* var0 = &gUnk_0811E84C[arg0];
    return var0->unk4;
}

void sub_0808148C(u32 arg0) {
    const Unk_0811E84C* var0 = &gUnk_0811E84C[arg0];
    if (var0->sfx) {
        SoundReq(var0->sfx);
    }
}

void sub_080814A4(Entity* this) {
    if (this->field_0x68.HALF.HI == 10) {
        this->field_0x6c.HWORD = 120;
    } else {
        this->field_0x6c.HWORD = 600;
    }
}

u32 sub_080814C0(Entity* this) {
    if (!AnyPrioritySet()) {
        if (--this->field_0x6c.HWORD == 0) {
            return TRUE;
        }

        if (this->field_0x6c.HWORD < 90) {
            this->spriteSettings.draw ^= 1;
        }
    }

    return FALSE;
}

void sub_08081500(Entity* this) {
    if (this->field_0x68.HALF.LO == 0) {
        u32 var0 = sub_080044EC(this, 0x2800);
        if (var0 == 0) {
            this->field_0x68.HALF.LO = 1;
        } else {
            if (var0 == 1) {
                sub_0808148C(this->type);
                UpdateSpriteForCollisionLayer(this);
            }

            ProcessMovement2(this);
        }
    }
}

void sub_0808153C(Entity* this) {
    if (this->field_0x68.HALF.LO > 1)
        return;

    if (this->field_0x68.HALF.LO == 0) {
        if (!GravityUpdate(this, Q_8_8(16.0)) && !sub_0800442E(this)) {
            this->field_0x68.HALF.LO = 1;
            this->zVelocity = Q_16_16(1.875);
            sub_0808148C(this->type);
            UpdateSpriteForCollisionLayer(this);
        }
    } else {
        if (!GravityUpdate(this, Q_8_8(40.0))) {
            this->field_0x68.HALF.LO = 2;
            sub_0808148C(this->type);
        }
    }
}

void sub_08081598(Entity* this) {
    if (this->health == 0) {
        sub_08081404(this, 1);
    }

    COLLISION_OFF(this);
    this->action = 4;
    this->timer = 14;
    this->zVelocity = Q_16_16(2.0);
    this->spriteSettings.draw = 1;
    this->spritePriority.b1 = 2;
    this->spritePriority.b0 = 3;
    this->child = &gPlayerEntity;
    CopyPosition(this->child, this);
    this->z.HALF.HI -= 4;
    if (this->type != 0x5F && sub_08081420(this)) {
        sub_08081404(this, 1);
    }
}
