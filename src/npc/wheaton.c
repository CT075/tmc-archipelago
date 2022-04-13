#include "npc.h"

void Wheaton(Entity* this) {
    static const Hitbox gUnk_0810C3C0 = { 0, 4, { 0, 0, 0, 0 }, 6, 12 };
    if (this->action == 0) {
        this->action++;

        SetDefaultPriority(this, PRIO_MESSAGE);
        SortEntityAbove(this, this);
        this->hitbox = (Hitbox*)&gUnk_0810C3C0;
        this->spriteOffsetY = 0xfe;
        sub_0807DD64(this);
    }
    sub_0807DD94(this, 0);
}
