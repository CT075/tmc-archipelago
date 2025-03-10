#include "sound.h"
#include "entity.h"
#include "room.h"
#include "npc.h"

void Carlov(Entity* this) {
    if (this->action == 0) {
        this->action++;
        sub_0807DD50(this);
    } else {
        sub_0807DD94(this, 0);
    }
    if ((this->frame & 0x10) != 0) {
        this->frame &= ~0x10;
        EnqueueSFX(SFX_PLACE_OBJ);
        InitScreenShake(16, 0);
    }
    if ((this->frame & 0x20) != 0) {
        this->frame &= ~0x20;
        EnqueueSFX(SFX_PLY_JUMP);
    }
}
