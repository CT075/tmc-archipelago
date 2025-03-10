#define NENT_DEPRECATED
/**
 * @file floatingPlatform.c
 * @ingroup Objects
 *
 * @brief Floating Platform object
 */
#include "entity.h"
#include "functions.h"
#include "object.h"

typedef struct {
    Entity base;
    u8 filler[0x8];
    u16 unk70;
} FloatingPlatformEntity;

void sub_080860D8(FloatingPlatformEntity*);
void sub_0808611C(FloatingPlatformEntity*);
bool32 sub_08086168(FloatingPlatformEntity*);

void FloatingPlatform(Entity* this) {
    static void (*const actionFuncs[])(FloatingPlatformEntity*) = {
        sub_080860D8,
        sub_0808611C,
    };

    actionFuncs[this->action]((FloatingPlatformEntity*)this);
}

void sub_080860D8(FloatingPlatformEntity* this) {
    super->action = 1;
    super->speed = 0x100;
    super->spriteSettings.draw = 1;
    super->frameIndex = super->type;
    super->spritePriority.b0 = 7;
    super->child = (Entity*)GetCurrentRoomProperty(super->type2);
    UpdateRailMovement(super, (u16**)&super->child, &this->unk70);
}

void sub_0808611C(FloatingPlatformEntity* this) {
    bool32 iVar2 = sub_08086168(this);

    if (super->timer != 0 && super->parent->timer == 0) {

        if (iVar2) {
            super->parent->timer++;
        }

        SyncPlayerToPlatform(super, iVar2);
    } else if (super->timer == 0) {
        SyncPlayerToPlatform(super, iVar2);
    } else {
        SyncPlayerToPlatform(super, FALSE);
    }

    if (--this->unk70 == 0) {
        UpdateRailMovement(super, (u16**)&super->child, &this->unk70);
    }
}

bool32 sub_08086168(FloatingPlatformEntity* this) {
    static const u8 gUnk_08120658[] = { 0x12, 0xa, 0xa, 0x12, 0x12, 0x12, 0x1a, 0x1a };
    const u8* ptr;

    ptr = gUnk_08120658 + super->type * 2;
    if (((EntityInRectRadius(super, &gPlayerEntity, ptr[0], ptr[1])) && PlayerCanBeMoved())) {
        gPlayerState.field_0x14 = 1;
        if (gPlayerEntity.z.HALF.HI == 0) {
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}
