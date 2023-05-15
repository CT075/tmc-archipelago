#ifndef ARCHIPELAGO_H
#define ARCHIPELAGO_H

#include "global.h"
#include "item.h"
#include "script.h"

struct ArchipelagoReceivedItem
{
    Item id;                     // The item to be received
    u16 itemIndex;               // The index of the item according to the AP server
    bool8 isFilled;              // Whether there is an item in this struct that has not been consumed
    bool8 isProgression;         // Whether a message is progression (for filtering messages)
};

// CR-someday Cam: we should probably be more principled about this, but it's
// not worth fighting the linker over whether or not this is used
#define gArchipelagoReceivedItem ((struct ArchipelagoReceivedItem *) 0x02033400)

extern Script script_GiveArchipelagoItem;

#endif
