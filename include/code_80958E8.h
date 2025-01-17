#include "wonder_mail.h"
#include "constants/mailbox.h"

struct subStruct_203B490
{
    // size: 0xC
    struct DungeonLocation dungeon;
    u32 unk4;
    u32 unk8;
};
 

struct unkStruct_203B490
{
    // size: 0x330?
    /* 0x0 */ struct WonderMail mailboxSlots[NUM_MAILBOX_SLOTS];
    /* 0x50 */ struct WonderMail pelipperBoardJobs[MAX_ACCEPTED_JOBS];
    /* 0xF0 */ struct WonderMail jobSlots[MAX_ACCEPTED_JOBS];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    struct subStruct_203B490 unk230[16];
    u8 PKMNNewsReceived[NUM_POKEMON_NEWS];
    bool8 unk328;
};

extern struct unkStruct_203B490 *gUnknown_203B490;
