#include "entity.h"
#include "collision.h"
#include "enemy.h"
#include "functions.h"

extern void (*const LakituLightning_Functions[])(Entity*);
extern void (*const LakituLightning_Actions[])(Entity*);

void LakituLightning_OnTick(Entity*);

void LakituLightning(Entity* this) {
    LakituLightning_Functions[GetNextFunction(this)](this);
}

void LakituLightning_OnTick(Entity* this) {
    LakituLightning_Actions[this->action](this);
}

void sub_080A9DD8(Entity* this) {
    if ((this->health == 0) || (this->contactFlags == 0x80)) {
        DeleteThisEntity();
    }
    LakituLightning_OnTick(this);
}

void LakituLightning_Init(Entity* this) {
    this->action = 1;
    this->timer = 180;
    this->health = 1;
    InitializeAnimation(this, 0);
}

void LakituLightning_Action1(Entity* this) {
    GetNextFrame(this);
    ProcessMovement3(this);
    if ((this->collisions != COL_NONE) || (--this->timer == 0)) {
        CreateFx(this, FX_BLUE_EFC, 0);
        DeleteThisEntity();
    }
    if (IsProjectileOffScreen(this)) {
        DeleteThisEntity();
    }
}

void (*const LakituLightning_Functions[])(Entity*) = {
    LakituLightning_OnTick, sub_080A9DD8, DeleteEntity, DeleteEntity, DeleteEntity,
};
void (*const LakituLightning_Actions[])(Entity*) = {
    LakituLightning_Init,
    LakituLightning_Action1,
};
