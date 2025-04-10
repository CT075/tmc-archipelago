#include "global.h"
#include "entity.h"
#include "functions.h"
#include "screen.h"

void KingGustaf(Entity* this) {
    s32 speed;

    if (this->action == 0) {
        this->action++;
        this->spriteRendering.alphaBlend = 1;
        this->collisionLayer = 2;
        SetDefaultPriority(this, PRIO_MESSAGE);
        sub_0807DD50(this);
        gScreen.controls.layerFXControl = 0x3f40;
        gScreen.controls.alphaBlend = 0x1000;
        this->speed = 0x1000;
        this->zVelocity = 0;
    } else {
        sub_0807DD94(this, 0);
        speed = 0x100;
        speed *= this->speed;
        speed += this->zVelocity;
        speed >>= 0x10;
        if (speed > 0x10) {
            speed = 0x10;
        }
        if (speed < 4) {
            speed = 4;
        }
        gScreen.controls.alphaBlend = (speed << 8) | (0x10 - speed);
        this->speed = gScreen.controls.alphaBlend;
    }
}
