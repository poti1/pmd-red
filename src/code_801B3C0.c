#include "global.h"
#include "constants/colors.h"
#include "text.h"
#include "input.h"
#include "item.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "menu_input.h"
#include "subStruct_203B240.h"

// based off of 203B240..
struct unkStruct_203B230
{
    // size: 0x94
    s32 state;
    struct Item item;
    s32 unk8;
    s32 unkC;
    struct subStruct_203B240 *unk10[2];
    u8 fill14[0x20 - 0x18];
    u32 unk20;
    u32 unk24;
    struct UnkTextStruct2 unk28[4];
    u32 unk88;
    u32 unk8C;
    u32 unk90;
};
extern struct unkStruct_203B230 *gUnknown_203B230;

struct unkStruct_203B234
{
    // size: 0x154
    u32 unk0;
    u32 state;
    u32 fallbackState;
    u8 unkC;
    struct Item unk10;
    struct unkStruct_8090F58 unk14;
    struct Item unk20;
    u32 unk24;
    struct MenuStruct unk28;
    struct MenuStruct unk78;
    u32 menuAction;
    struct MenuItem unkCC[5];
    struct UnkTextStruct2 unkF4[4];
};

extern struct unkStruct_203B234 *gUnknown_203B234;

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_80DBA4C[];
extern u8 gUnknown_80DBB9C[];
extern u8 gUnknown_80DBD24[];
extern u8 gUnknown_80DBCE8[];
extern u8 gUnknown_80DBCC4[];
extern u8 gUnknown_80DBC98[];
extern u8 gUnknown_80DBC60[];
extern u8 gUnknown_80DBC28[];
extern u8 gUnknown_80DBB9C[];
extern u8 gUnknown_80DBAA0[];
extern u8 gUnknown_80DBAD0[];
extern u8 gUnknown_80DBB08[];
extern u8 gUnknown_80DBB38[];
extern u8 gKangaskhanTrashToolboxItem[];
extern u8 gKangaskhanTrashReceivedItem[];
extern u8 gKangaskhanStorage[];
extern u8 gKangaskhanTrash[];
extern u8 *gUnknown_80D4970[];
extern u8 gUnknown_202DEA8[];
extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];

extern s32 sub_80144A4(s32 *);
extern u32 sub_801A6E8(u32);
extern u32 sub_801A8AC();
extern void sub_8099690(u32);
extern void sub_801A928(void);

extern bool8 sub_801ADA0(s32);
extern struct UnkTextStruct2 gUnknown_80DBA58;
extern struct UnkTextStruct2 gUnknown_80DBA88;
extern struct UnkTextStruct2 gUnknown_80DBA70;

extern void sub_801BB5C(void);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_801B748(u32);
extern void sub_8008C54(u32);
extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern void xxx_format_and_draw(u32, u32, u8 *, u32, u32);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013F84(void);
extern u32 sub_8012A64(u32 *, u32);
extern s32 sub_80913E0(struct Item *, u32, struct subStruct_203B240 **);
extern void sub_80141B4(u8 *, u32, u32 *, u32);
extern void sub_801BB20(void);
extern void sub_801A8D0(u32);
extern void sub_801A9E0(void);
extern void sub_801BC24(void);
extern void sub_801A5D8(u32, u32, u32, u32);
extern void sub_8014248(const char *, u32, u32, struct MenuItem *, u32, u32, u32, u32, u32);
extern void sub_801317C(u32 *);
extern void sub_80140B4(struct UnkTextStruct2 *);
extern void sub_801B46C(u32);
extern void ResetSprites(u32);
extern void sub_801BC64(void);
extern void sub_801BC94(void);
extern void sub_801BCCC(void);
extern void sub_801BD80(void);
extern void sub_801BEAC(void);
extern void sub_801BE30(void);
extern void sub_801BEC8(void);
extern void sub_801B760(void);
extern void sub_801B874(void);
extern u32 sub_8001784(u32, u32, u16);
extern void sub_800199C(u32, u32, u32, u32);
extern void PlaySound(u32);
extern s32 sub_808D544(u32);

void sub_801B51C();
void sub_801B590();
void sub_801B480();


u32 sub_801B3C0(struct Item *item)
{
  ResetSprites(1);
  gUnknown_203B230 = MemoryAlloc(sizeof(struct unkStruct_203B230),8);
  gUnknown_203B230->item = *item;
  sub_801317C(&gUnknown_203B230->unk88);
  gUnknown_203B230->unk24 = 0;
  sub_80140B4(gUnknown_203B230->unk28);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B230->unk28,1,1);
  sub_801B46C(0);
  return 1;
}

u32 sub_801B410(void)
{
    switch(gUnknown_203B230->state)
    {
        case 0:
            sub_801B51C();
            break;
        case 1:
            sub_801B590();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }
    return 0;
}

void sub_801B450(void)
{
    if(gUnknown_203B230 != NULL)
    {
        MemoryFree(gUnknown_203B230);
        gUnknown_203B230 = NULL;
    }
}

void sub_801B46C(u32 newState)
{
    gUnknown_203B230->state = newState;
    sub_801B480();
}

void sub_801B480(void)
{
    struct subStruct_203B240 *preload;
    switch(gUnknown_203B230->state)
    {
        case 0:
            sub_8008C54(gUnknown_203B230->unk24);
            gUnknown_203B230->unkC = sub_80913E0(&gUnknown_203B230->item, gUnknown_203B230->unk24, gUnknown_203B230->unk10);
            gUnknown_203B230->unk20 = 0;
            break;
        case 1:
            sub_8008C54(gUnknown_203B230->unk24);
            sub_80073B8(gUnknown_203B230->unk24);
            preload = gUnknown_203B230->unk10[gUnknown_203B230->unk8];
            strcpy(gAvailablePokemonNames, preload->pokeName);
            xxx_format_and_draw(16, 0, gUnknown_80DBA4C, gUnknown_203B230->unk24, 0); // {ARG_POKEMON_0}
            xxx_format_and_draw(4, 16, gUnknown_203B230->unk10[gUnknown_203B230->unk8]->unk4, gUnknown_203B230->unk24, 0);
            sub_80073E0(gUnknown_203B230->unk24);
            break;
        case 2:
        default:
            break;
    }
}

void sub_801B51C(void)
{
    if(gUnknown_203B230->unkC != 0)
    {
        if(gUnknown_203B230->unk20 & 8)
            sub_8013F84();
        gUnknown_203B230->unk20++;
    }
    switch(sub_8012A64(&gUnknown_203B230->unk88, gUnknown_203B230->unk24))
    {
        case 1:
            PlayMenuSoundEffect(0);
            if(gUnknown_203B230->unkC != 0)
            {
                gUnknown_203B230->unk8 = 0;
                sub_801B46C(1);
            }
            else
                sub_801B46C(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
        default:
            break;
    }
}

void sub_801B590(void)
{

  if (gUnknown_203B230->unk8 < (gUnknown_203B230->unkC - 1)) {
    if ((gUnknown_203B230->unk20 & 8)) {
      sub_8013F84();
    }
    gUnknown_203B230->unk20++;
  }
  switch(sub_8012A64(&gUnknown_203B230->unk88,gUnknown_203B230->unk24))
  {
    case 1:
        PlayMenuSoundEffect(0);
        gUnknown_203B230->unk8++;
        if (gUnknown_203B230->unk8 < gUnknown_203B230->unkC) {
            sub_801B46C(1);
        }
        else {
            sub_801B46C(0);
        }
        break;
    case 2:
        PlayMenuSoundEffect(1);
        sub_801B46C(2);
        break;
  }
}

u32 sub_801B60C(u32 r0, u8 id, u8 quantity)
{
    gUnknown_203B234 = MemoryAlloc(sizeof(struct unkStruct_203B234), 8);
    gUnknown_203B234->menuAction = 0;
    gUnknown_203B234->unk0 = r0;
    gUnknown_203B234->unk10.id = id;
    if(IsThrowableItem(gUnknown_203B234->unk10.id))
    {
        gUnknown_203B234->unk10.quantity = quantity;
        gUnknown_203B234->unkC = quantity;
    }
    else
    {
        gUnknown_203B234->unk10.quantity = 0;
        gUnknown_203B234->unkC = 1;
    }
    gUnknown_203B234->unk10.flags = ITEM_FLAG_EXISTS;
    gUnknown_203B234->unk14.unk0 = 0;
    gUnknown_203B234->unk14.unk4 = 0;
    gUnknown_203B234->unk14.unk8 = 1;
    PrintColoredPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct(), COLOR_YELLOW);
    sub_8090E14(gUnknown_202DE58, &gUnknown_203B234->unk10, &gUnknown_203B234->unk14);
    sub_801B748(0);
    return 1;
}

u32 sub_801B6AC(void)
{
    switch(gUnknown_203B234->state)
    {
        case 16:
            return 3;
        case 6:
            sub_801BC64();
            break;
        case 7:
            sub_801BC94();
            break;
        case 8:
        case 9:
            sub_801BCCC();
            break;
        case 10:
            sub_801BD80();
            break;
        case 11:
            sub_801BEAC();
            break;
        case 12:
            sub_801BE30();
            break;
        case 13:
        case 14:
        case 15:
        default:
            sub_801BEC8();
            break;

    }
    return 0;
}

void sub_801B72C(void)
{
    if(gUnknown_203B234 != NULL)
    {
        MemoryFree(gUnknown_203B234);
        gUnknown_203B234 = NULL;
    }
}

void sub_801B748(u32 newState)
{
   gUnknown_203B234->state = newState;
   sub_801B760();
   sub_801B874();
}

void sub_801B760(void)
{
    s32 index;
    switch(gUnknown_203B234->state)
    {
       case 1:
       case 6:
       case 7:
       case 8:
       case 9:
       case 11:
       case 13:
       case 14:
       case 15:
            sub_8006518(gUnknown_203B234->unkF4);
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B234->unkF4[index] = gUnknown_80DBA58;
            }
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B234->unkF4, 1, 1);
            break;
        case 10:
            sub_8006518(gUnknown_203B234->unkF4);
            sub_801BB5C();
            gUnknown_203B234->unkF4[2] = gUnknown_80DBA70;
            sub_8012CAC(&gUnknown_203B234->unkF4[2], gUnknown_203B234->unkCC);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B234->unkF4, 1, 1);
            break;
        case 12:
            sub_8006518(gUnknown_203B234->unkF4);
            gUnknown_203B234->unkF4[1] = gUnknown_80DBA88;
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B234->unkF4, 1, 1);
            break;
    }
}

void sub_801B874(void)
{

    switch(gUnknown_203B234->state) 
    {
        case 0:
            if (gUnknown_203B234->unk10.id == ITEM_WEAVILE_FIG) {
                gUnknown_203B234->fallbackState = 0x10;
                if(sub_8001784(0,0x47,1) != 0)
                {
                    AddToTeamMoney(1000);
                    sub_801B748(4);
                }
                else
                {
                    sub_800199C(0, 0x47, 1, 1);
                    sub_801B748(3);
                }
            }
            else if (gUnknown_203B234->unk10.id == ITEM_MIME_JR_FIG)
            {
                gUnknown_203B234->fallbackState = 0x10;
                if(sub_8001784(0, 0x47, 0) != 0)
                {
                    AddToTeamMoney(1000);
                    sub_801B748(4);
                }
                else
                {
                    sub_800199C(0, 0x47, 0, 1);
                    sub_801B748(3);
                }
            }
            else
            {
                if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                {
                    if(IsNotMoneyOrUsedTMItem(gUnknown_203B234->unk10.id))
                    {
                        if((gTeamInventory_203B460->teamStorage[gUnknown_203B234->unk10.id] + gUnknown_203B234->unkC) > 0x3e7)
                        {
    store:
                            gUnknown_203B234->fallbackState = 6;
                        }
                        else
                        {
                            gTeamInventory_203B460->teamStorage[gUnknown_203B234->unk10.id] += gUnknown_203B234->unkC;
                            PlaySound(0xCB);
                            gUnknown_203B234->fallbackState = 5;
                        }
                    }
                    else
                    {
                        goto store;
                    }
                }
                else
                {
                    AddItemToInventory(&gUnknown_203B234->unk10);
                    FillInventoryGaps();
                    PlaySound(0xCB);
                    gUnknown_203B234->fallbackState = 0x10;
                }
                if(gUnknown_203B234->unk0 == 1)
                    sub_801B748(2);
                else
                    sub_801B748(1);
            }
            break;
        case 1:
            if (sub_808D544(0) < 2) {
                sub_80141B4(gUnknown_80DBAA0,0,0,0x101);
            }
            else {
                sub_80141B4(gUnknown_80DBAD0,0,0,0x101);
            }
            break;
        case 2:
            sub_80141B4(gUnknown_80DBB08,0,0,0x101);
            break;
        case 3:
            PlaySound(0xd4);
            sub_80141B4(gUnknown_80DBB38,0,0,0x101);
            break;
        case 4:
            sub_80141B4(gUnknown_80DBB9C,0,0,0x101);
            break;
        case 5:
            gUnknown_203B234->fallbackState = 0x10;
            sub_80141B4(gUnknown_80DBC28,0,0,0x101);
            break;
        case 6:
            sub_801BB20();
            sub_8014248(gUnknown_80DBC60,0,4,gUnknown_203B234->unkCC,
                        0,4,0,0,0);
            break;
        case 7:
            sub_801BC24();
            sub_8014248(gUnknown_80DBC98,0,3,gUnknown_203B234->unkCC,0,4,0,0,0);
            break;
        case 8:
            sub_801A5D8(1,3,0,10);
            break;
        case 9:
            sub_801A8D0(1);
            break;
        case 10:
            sub_801A9E0();
            sub_8012D60(&gUnknown_203B234->unk28,gUnknown_203B234->unkCC,0,0,gUnknown_203B234->menuAction,2);
            break;
        case 0xb:
            sub_801B3C0(&gUnknown_203B234->unk20);
            break;
        case 0xc:
            sub_801A9E0();
            sub_8012EA4(&gUnknown_203B234->unk28,0);
            sub_801BC24();
            sub_8012D60(&gUnknown_203B234->unk78,gUnknown_203B234->unkCC,0,0,3,1);
            break;
        case 0xd:
            gUnknown_203B234->fallbackState = 0x10;
            sub_80141B4(gUnknown_80DBCC4,0,0,0x101);
            break;
        case 0xe:
            gUnknown_203B234->fallbackState = 0x10;
            sub_80141B4(gUnknown_80DBCE8,0,0,0x101);
            break;
        case 0xf:
            gUnknown_203B234->fallbackState = 0x10;
            sub_80141B4(gUnknown_80DBD24,0,0,0x101);
            break;
        case 0x10:
            break;
    }
}

void sub_801BB20(void)
{
    s32 loopMax;

    loopMax = 0;
    gUnknown_203B234->unkCC[loopMax].text = gKangaskhanTrashToolboxItem;
    gUnknown_203B234->unkCC[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B234->unkCC[loopMax].text = gKangaskhanTrashReceivedItem;
    gUnknown_203B234->unkCC[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B234->unkCC[loopMax].text = NULL;
    gUnknown_203B234->unkCC[loopMax].menuAction = -1;
}

void sub_801BB5C(void)
{
    int index;
    s32 loopMax = 0;

    gUnknown_203B234->unkCC[loopMax].text = gKangaskhanStorage;
    gUnknown_203B234->unkCC[loopMax].menuAction = 6;
    if (!sub_801ADA0(gUnknown_203B234->unk24)) {
        gUnknown_203B234->unkCC[loopMax].menuAction = -1;
    }

    loopMax++;
    gUnknown_203B234->unkCC[loopMax].text = gKangaskhanTrash;
    gUnknown_203B234->unkCC[loopMax].menuAction = 7;

    loopMax++;
    gUnknown_203B234->unkCC[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B234->unkCC[loopMax].menuAction = 8;

    loopMax++;
    gUnknown_203B234->unkCC[loopMax].text = 0;
    gUnknown_203B234->unkCC[loopMax].menuAction = 1;


    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B234->unkCC[index].menuAction != -1)
            if(gUnknown_203B234->unkCC[index].menuAction == gUnknown_203B234->menuAction)
                return;
    }

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B234->unkCC[index].menuAction != -1)
        {
            gUnknown_203B234->menuAction = gUnknown_203B234->unkCC[index].menuAction;
            break;
        }
    }
}

void sub_801BC24(void)
{
    s32 loopMax;
    loopMax = 0;
    gUnknown_203B234->unkCC[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B234->unkCC[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B234->unkCC[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B234->unkCC[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B234->unkCC[loopMax].text = NULL;
    gUnknown_203B234->unkCC[loopMax].menuAction = 1;
}

void sub_801BC64(void)
{
    s32 temp;
    if(sub_80144A4(&temp)== 0)
    {
        switch(temp)
        {
            case 4:
                sub_801B748(0x8);
                break;
            case 5:
                sub_801B748(0x7);
                break;
        }
    }
}

void sub_801BC94(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 2:
                sub_801B748(0xD);
                break;
            case 1:
            case 3:
                sub_801B748(0x6);
                break;
        }
    }
}

void sub_801BCCC(void)
{
    switch(sub_801A6E8(1))
    {
        case 0:
        case 1:
            break;
        case 3:
            gUnknown_203B234->unk24 = sub_801A8AC();
            gUnknown_203B234->unk20 = gTeamInventory_203B460->teamItems[gUnknown_203B234->unk24];
            sub_8090E14(gUnknown_202DEA8, &gUnknown_203B234->unk20, &gUnknown_203B234->unk14);
            sub_801B748(0xA);
            break;
        case 4:
            gUnknown_203B234->unk24 = sub_801A8AC();
            gUnknown_203B234->unk20 = gTeamInventory_203B460->teamItems[gUnknown_203B234->unk24];
            sub_8090E14(gUnknown_202DEA8, &gUnknown_203B234->unk20, &gUnknown_203B234->unk14);
            sub_8099690(0);
            sub_801B748(0xB);
            break;
        case 2:
            sub_801A928();
            sub_801B748(6);
            break;
    }
}

void sub_801BD80(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  if (!sub_8012FD8(&gUnknown_203B234->unk28)) {
    sub_8013114(&gUnknown_203B234->unk28,&menuAction);
    if (menuAction != 1) gUnknown_203B234->menuAction = menuAction;
  }
  switch(menuAction)
  {
    case 6:
        MoveToStorage(&gUnknown_203B234->unk20);
        ShiftItemsDownFrom(gUnknown_203B234->unk24);
        AddItemToInventory(&gUnknown_203B234->unk10);
        FillInventoryGaps();
        PlaySound(0xcb);
        sub_8099690(0);
        sub_801A928();
        sub_801B748(0xE);
        break;
    case 7:
        sub_801B748(0xC);
        break;
    case 8:
        sub_8099690(0);
        sub_801B748(0xB);
        break;
    case 1:
        sub_801B748(0x9);
        break;
  }
}

void sub_801BE30(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  sub_8012FD8(&gUnknown_203B234->unk28);
  if (!sub_8012FD8(&gUnknown_203B234->unk78)) {
    sub_8013114(&gUnknown_203B234->unk78,&menuAction);
  }
  switch(menuAction)
  {
    case 1:
    case 3:
        sub_801B748(9);
        break;
    case 2:
        ShiftItemsDownFrom(gUnknown_203B234->unk24);
        AddItemToInventory(&gUnknown_203B234->unk10);
        FillInventoryGaps();
        PlaySound(0xcb);
        sub_801A928();
        sub_801B748(0xf);
        break;
  }
}

void sub_801BEAC(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_801B748(9);
        case 0:
        case 1:
            break;
    }
}

void sub_801BEC8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_801B748(gUnknown_203B234->fallbackState);
    }
}

