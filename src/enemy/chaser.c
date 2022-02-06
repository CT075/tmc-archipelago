/**
 * @file chaser.c
 * @ingroup Enemies
 *
 * @brief Chaser enemy
 */

#include "enemy.h"
#include "functions.h"

extern s32 sub_080012DC(Entity*);
extern u32 sub_0804A024(Entity*, u32, u32);
extern bool32 sub_080AF038(Entity*);

extern void (*const gUnk_080012C8[])(Entity*);

extern void (*const Chaser_Functions[])(Entity*);
extern void (*const gUnk_080CD298[])(Entity*);

void Chaser(Entity* this) {
    u32 idx = sub_080012DC(this);
    if (idx) {
        gUnk_080012C8[idx](this);
    } else {
        Chaser_Functions[GetNextFunction(this)](this);
    }
}

void Chaser_OnTick(Entity* this) {
    gUnk_080CD298[this->action](this);
}

void sub_0802B530(Entity* this) {
    this->action = 1;
    InitializeAnimation(this, 0);
}

void sub_0802B540(Entity* this) {
    if (this->actionDelay) {
        this->actionDelay--;
    } else {
        u32 direction = sub_0804A024(this, 1, 0xc);
        if (direction != 0xff) {
            this->action = 2;
            this->speed = 0x40;
            this->direction = direction;
        }
    }
}

void sub_0802B56C(Entity* this) {
    GetNextFrame(this);
    if (this->bitfield & 0x80) {
        this->speed = 0x40;
    }

    if (sub_080AF038(this)) {
        if (this->animIndex != 1) {
            InitializeAnimation(this, 1);
        }
        if (this->speed < 0x220) {
            this->speed += 4;
        }
    } else {
        this->action = 3;
        InitializeAnimation(this, 2);
    }
}

void sub_0802B5C8(Entity* this) {
    GetNextFrame(this);
    if (this->frame & 0x80) {
        this->action = 1;
        this->actionDelay = 30;
        InitializeAnimation(this, 0);
    }
}

// clang-format off
void (*const Chaser_Functions[])(Entity*) = {
    Chaser_OnTick,
    Chaser_OnTick,
    GenericKnockback,
    GenericDeath,
    GenericConfused,
    Chaser_OnTick,
    Chaser_OnTick,
};

void (*const gUnk_080CD298[])(Entity*) = {
    sub_0802B530,
    sub_0802B540,
    sub_0802B56C,
    sub_0802B5C8,
};
// clang-format on
