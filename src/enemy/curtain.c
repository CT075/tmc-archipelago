#include "enemy.h"
#include "entity.h"

void (*const Curtain_Functions[])(Entity*);
void (*const gUnk_080D1CE0[])(Entity*);

void Curtain(Entity* this) {
    EnemyFunctionHandler(this, Curtain_Functions);
}

void Curtain_OnTick(Entity* this) {
    gUnk_080D1CE0[this->action](this);
}

void Curtain_OnCollision(Entity* this) {
    if (this->field_0x46) {
        this->action = 2;
        this->flags &= ~ENT_COLLIDE;
        this->spritePriority.b0 = 7;
        this->actionDelay = 3;
    } else {
        this->actionDelay = 2;
    }

    InitializeAnimation(this, this->actionDelay);
}

void Curtain_OnGrabbed() {
}

void sub_08048224(Entity* this) {
    this->spritePriority.b0 = 4;

    if (CheckLocalFlag(0x72) == 0) {
        this->action = 1;
        this->actionDelay = 0;
    } else {
        this->action = 3;
        this->flags &= ~ENT_COLLIDE;
        this->actionDelay = 1;
    }

    InitializeAnimation(this, this->actionDelay);
}

void sub_08048268(Entity* this) {
    if (this->actionDelay == 0) {
        return;
    }

    GetNextFrame(this);
    if (this->frame & 0x80) {
        this->actionDelay = 0;
        InitializeAnimation(this, 0);
    }
}

void sub_08048294(Entity* this) {
    GetNextFrame(this);

    if (this->frame & 0x80) {
        this->action = 3;
        SetLocalFlag(0x72);
        InitializeAnimation(this, 1);
    }
}

void nullsub_27() {
}

void (*const Curtain_Functions[])(Entity*) = {
    Curtain_OnTick, Curtain_OnCollision, GenericKnockback, GenericDeath, GenericConfused, Curtain_OnGrabbed,
};

void (*const gUnk_080D1CE0[])(Entity*) = {
    sub_08048224,
    sub_08048268,
    sub_08048294,
    nullsub_27,
};
