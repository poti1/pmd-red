#include "constants/input.h"
#include "global.h"
#include "constants/iq_skill.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "team_inventory.h"
#include "text.h"
#include "input.h"
#include "item.h"
#include "menu_input.h"

struct unkStruct_3001B5C
{
    // size: 0x3fC
    u8 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC[2];
    u32 unk10;
    u8 fill14[0x354 - 0x14];
    u8 unk354;
    u8 fill355[0x35C - 0x355];
    struct MenuInputStruct input;
    u32 unk390;
    struct UnkTextStruct2 *unk394;
    struct UnkTextStruct2 unk398[4];
    u8 unk3F8[4];
};

IWRAM_DATA struct unkStruct_3001B5C *gUnknown_3001B5C;

extern u32 gUnknown_203B298;
extern u16 gUnknown_203B29C;
extern u16 gUnknown_203B29E;
extern struct UnkTextStruct2 gUnknown_80DC91C;
extern struct UnkTextStruct2 gUnknown_80DC904;

void sub_8023758(void);
void sub_80237E0(void);
extern bool8 sub_8098134(s32);
extern void sub_8023730(void);
extern u8 sub_8023704(u8);
extern void sub_8013818(struct MenuInputStruct*, u32, u32, u32);
extern void sub_8013984(struct MenuInputStruct*);
extern void sub_8023420(void);
extern void sub_80234BC(void);
extern u32 sub_80236A4(void);
extern u8 sub_80138B8(struct MenuInputStruct*, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(struct MenuInputStruct*);
extern void sub_8013660(struct MenuInputStruct*);
extern void AddMenuCursorSprite(struct MenuInputStruct*);

struct unkStruct_203B294
{   
    // size: 0x1A8
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fallbackState;
    u8 iqSkillPreGummi[NUM_IQ_SKILLS];
    u8 iqSkillPostGummi[NUM_IQ_SKILLS];
    u32 availIQSkillPreGummi;
    u32 availIQSkillPostGummi;
    u32 unk40; // Gummi eaten flag?
    struct Gummi gummi;
    /* 0x48 */ struct PokemonStruct *pokeStruct;
    u32 itemIndex;
    struct Item item;
    struct MenuStruct unk54;
    struct MenuStruct unkA4;
    u32 menuAction;
    struct MenuItem unkF8[0x8];
    u16 unk138[0x8];
};

struct unkStruct_203B294 *gUnknown_203B294;

extern u8 gUnknown_80DC5EC[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_80DC8F0[];
extern u8 gUnknown_80DC8F8[];
extern u8 *gUnknown_80D4940[];
extern u8 *gUnknown_80D4970[];
extern void sub_8022924(s32);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801B00C(void);
extern void sub_801B048(void);
extern u32 sub_801B410(void);
extern void sub_801B450(void);

void GetGummiItemStatBoost(struct PokemonStruct* pokemon, u8 id, bool8 checkBoostFlags, struct Gummi* gummi);

extern u32 sub_801A6E8(u32);
extern void sub_8099690(u32);
extern void sub_801A928(void);
s32 GetNumAvailableIQSkills(u8 *iqSkillBuffer, s32 pokeIQ);
extern u32 sub_801A8AC(void);

void sub_8022D2C(void) {
    s32 index;
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B294->unk138, 0, sizeof(gUnknown_203B294->unk138));
    if(gUnknown_203B294->pokeStruct)
    {
        gUnknown_203B294->unkF8[loopMax].text = gUnknown_80DC8F0;
        gUnknown_203B294->unkF8[loopMax].menuAction = 5;
        if(!IsGummiItem(gUnknown_203B294->item.id))
        {
            gUnknown_203B294->unk138[loopMax] = 1;
        }
        loopMax += 1;
    }
    else {
        if(GetItemCategory(gUnknown_203B294->item.id) == CATEGORY_TMS_HMS)
        {
            gUnknown_203B294->unkF8[loopMax].text = gUnknown_80DC8F8;
            gUnknown_203B294->unkF8[loopMax].menuAction = 6;
            loopMax += 1;
        }
        gUnknown_203B294->unkF8[loopMax].text = *gUnknown_80D4940;
        gUnknown_203B294->unkF8[loopMax].menuAction = 4;
        loopMax += 1;
    }
    gUnknown_203B294->unkF8[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B294->unkF8[loopMax].menuAction = 7;
    loopMax += 1;
    gUnknown_203B294->unkF8[loopMax].text = NULL;
    gUnknown_203B294->unkF8[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B294->unk138[index] == 0)
        {
            if(gUnknown_203B294->unkF8[index].menuAction == gUnknown_203B294->menuAction)
                return;
        }
    }

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B294->unk138[index] == 0)
        {
            gUnknown_203B294->menuAction = gUnknown_203B294->unkF8[index].menuAction;
            break;
        }
    }
}

void sub_8022E78(void)
{ 
  switch(sub_801A6E8(1))
  {
      case 3:
        gUnknown_203B294->itemIndex = sub_801A8AC();
        gUnknown_203B294->item = gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex];
        sub_8022924(2);
        break;
      case 4:
        gUnknown_203B294->itemIndex = sub_801A8AC();
        gUnknown_203B294->item = gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex];
        sub_8099690(0);
        sub_8022924(4);
        break;
      case 2:
        sub_8022924(0x16);
        break;
  }
}

void sub_8022EF4(void)
{
  s32 menuAction;
  s32 boostAmount;
  
  menuAction = 0;
  sub_801A6E8(0);
  if (sub_8012FD8(&gUnknown_203B294->unk54) == 0) {
    sub_8013114(&gUnknown_203B294->unk54,&menuAction);
    if(menuAction != 1) gUnknown_203B294->menuAction = menuAction;
  }

  switch(menuAction)
  {
      case 1:
        sub_8022924(1);
        break;
      case 2:
      case 3:
        break;
      case 5:
        gUnknown_203B294->availIQSkillPreGummi = GetNumAvailableIQSkills(gUnknown_203B294->iqSkillPreGummi, gUnknown_203B294->pokeStruct->IQ);
        GetGummiItemStatBoost(gUnknown_203B294->pokeStruct, gUnknown_203B294->item.id, FALSE, &gUnknown_203B294->gummi);
        gUnknown_203B294->availIQSkillPostGummi = GetNumAvailableIQSkills(gUnknown_203B294->iqSkillPostGummi, gUnknown_203B294->pokeStruct->IQ);
        gUnknown_203B294->unk40 = 1;
        boostAmount = gUnknown_203B294->gummi.boostAmount;

        sub_8090E14(gUnknown_202DE58, &gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex], NULL);
        
        if(boostAmount != -1)
            ShiftItemsDownFrom(gUnknown_203B294->itemIndex);

        sub_8099690(0);
        gUnknown_203B294->fallbackState = 0xA;

        switch(boostAmount + 1)
        {
            case 1:
                sub_8022924(6);
                break;
            case 2:
                sub_8022924(7);
                break;
            case 3:
                sub_8022924(8);
                break;
            case 4:
                sub_8022924(9);
                break;
            default:
            case 0:
                gUnknown_203B294->fallbackState = 0x16;
                sub_8022924(5);
                break;
        }
        break;
      case 6:
        sub_8022924(0x15);
        break;
      case 4:
        sub_8022924(3);
        break;
      case 7:
        sub_8099690(0);
        sub_8022924(4);
        break;
  }
}

void sub_8023068(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  sub_8012FD8(&gUnknown_203B294->unk54);
  if (sub_8012FD8(&gUnknown_203B294->unkA4) == 0) {
    sub_8013114(&gUnknown_203B294->unkA4,&menuAction);
  }

  switch(menuAction)
  {      
      case 1:
      case 3:
            sub_8022924(1);
            break;
      case 2:
        ShiftItemsDownFrom(gUnknown_203B294->itemIndex);
        if (GetNumberOfFilledInventorySlots() == 0) {
            sub_8099690(0);
            sub_801A928();
            sub_8022924(0x14);
        }
        else {
            sub_8022924(1);
        }
        break;
  }
}

void sub_80230E8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

void sub_8023104(void)
{
    switch(sub_801B00C())
    {
        case 2:
        case 3:
            sub_801B048();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

void sub_8023120(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_8022924(gUnknown_203B294->fallbackState);
    }
}

bool8 sub_8023144(s32 param_1, s32 index, struct UnkTextStruct2_sub *sub, u32 param_4)
{
  u8 param_1_u8 = param_1;

  if (sub_8023704(param_1_u8)) {
    return 0;
  }
  if (gUnknown_3001B5C == NULL) {
    gUnknown_3001B5C = MemoryAlloc(sizeof(struct unkStruct_3001B5C), 8);
  }
  gUnknown_3001B5C->unk0 = param_1_u8;
  gUnknown_3001B5C->unk4 = gUnknown_203B298;

  gUnknown_3001B5C->unk390 = index;
  gUnknown_3001B5C->unk394 = &gUnknown_3001B5C->unk398[index];
  sub_8006518(gUnknown_3001B5C->unk398);
  gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC91C;

  gUnknown_3001B5C->unk394->unk14 = gUnknown_3001B5C->unk3F8;
  if (sub != NULL) {
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390].unk08 = *sub;
  }
  sub_8012D08(gUnknown_3001B5C->unk394,param_4);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,1,1);
  sub_8013818(&gUnknown_3001B5C->input,sub_80236A4(),param_4,index);
  gUnknown_3001B5C->input.menuIndex = gUnknown_203B29C;
  gUnknown_3001B5C->input.unk1E = gUnknown_203B29E;
  sub_8013984(&gUnknown_3001B5C->input);
  sub_8023420();
  sub_80234BC();
  return 1;
}


u8 sub_8023278(u8 param_1)
{
  s32 iVar3;
  u32 temp;
  
  if (param_1 == 0) {
    sub_8013660(&gUnknown_3001B5C->input);
    return 0;
  }
  switch(GetKeyPress(&gUnknown_3001B5C->input))
  {
    case INPUT_B_BUTTON:
        PlayMenuSoundEffect(1);
        return 2;
    case INPUT_A_BUTTON:
      PlayMenuSoundEffect(0);
      return 3;
    case INPUT_SELECT_BUTTON:
        PlayMenuSoundEffect(5);
        if (temp = gUnknown_3001B5C->unk4, iVar3 = 1, temp < 2) {
            iVar3 = temp + 1;
        }
        gUnknown_3001B5C->unk4 = iVar3;
        sub_80236A4();
        break;
    default:
        if (sub_80138B8(&gUnknown_3001B5C->input, 1) == 0) {
            return 0;
        }
        break;
  }
  sub_8023420();
  sub_80234BC();
  return 1;
}

s16 sub_802331C(void)
{
  return gUnknown_3001B5C->unkC[gUnknown_3001B5C->input.unk1E * gUnknown_3001B5C->input.unk1C + gUnknown_3001B5C->input.menuIndex];
}

void sub_8023354(u8 param_1)
{
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,0,0);
  sub_8013984(&gUnknown_3001B5C->input);
  sub_8023420();
  sub_80234BC();
  if (param_1 != 0) {
    AddMenuCursorSprite(&gUnknown_3001B5C->input);
  }
}


void sub_80233A0(void)
{
  if (gUnknown_3001B5C != NULL) {
    gUnknown_203B298 = gUnknown_3001B5C->unk4;
    gUnknown_203B29C = gUnknown_3001B5C->input.menuIndex;
    gUnknown_203B29E = gUnknown_3001B5C->input.unk1E;
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC904;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_3001B5C->unk398,1,1);
    MemoryFree(gUnknown_3001B5C);
    gUnknown_3001B5C = NULL;
  }
}

NAKED
void sub_8023420(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tldr r4, _080234A8\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0xFE\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r1\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _080234AC\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, 0x1\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _080234B0\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r2, _080234B4\n"
	"\tadds r0, r2\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tldr r3, [r4]\n"
	"\tmovs r2, 0xE4\n"
	"\tlsls r2, 2\n"
	"\tadds r5, r3, r2\n"
	"\tldr r2, [r5]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r1, r2\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r3, r1\n"
	"\tldr r2, _080234B8\n"
	"\tadds r1, r2\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r2, [r5]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r1, r2\n"
	"\tlsls r1, 3\n"
	"\tadds r3, r1\n"
	"\tmovs r1, 0xEA\n"
	"\tlsls r1, 2\n"
	"\tadds r3, r1\n"
	"\tstrh r0, [r3]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tmovs r2, 0xE6\n"
	"\tlsls r2, 2\n"
	"\tadds r0, r2\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080234A8: .4byte gUnknown_3001B5C\n"
"_080234AC: .4byte 0x000003f9\n"
"_080234B0: .4byte 0x000003fb\n"
"_080234B4: .4byte 0x00000376\n"
"_080234B8: .4byte 0x000003a6");
}

extern u8 gUnknown_80DC934[];

struct unkStruct_8092638
{
    u32 unk0;
    u8 unk4;
    u32 unk5;
};
extern void sub_8092638(u8,struct unkStruct_8092638  *, u32, u32);
extern void xxx_call_draw_string(u32, u32, const u8 *, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
void sub_808D930(u8 *buffer, s32 index);
extern s32 sub_8013800(void *, u32);
bool8 HasRecruitedMon(s16 species_);
extern u8 gUnknown_80DC93C[];
void sprintfStatic(char *buffer, const char *text, ...);

void sub_80234BC(void)
{
  u8 cVar2;
  u32 y;
  s32 uVar3;
  s32 iVar4;
  s32 species;
  u32 color;
  s32 index;
  u8 buffer2 [256];
  u8 buffer1 [100];
  struct unkStruct_8092638 auStack_2c;
  
  sub_8008C54(gUnknown_3001B5C->unk390);
  sub_80073B8(gUnknown_3001B5C->unk390);
  xxx_call_draw_string(10,0,gUnknown_80DC934,gUnknown_3001B5C->unk390,0); // Pokemon
  sub_8012BC4(gUnknown_3001B5C->unk3F8[2] * 8 + 4,0,
              gUnknown_3001B5C->input.unk1E + 1,2,7,gUnknown_3001B5C->unk390);
  for(index = 0; index < gUnknown_3001B5C->input.unk1A; index++)
  {
      y = sub_8013800(&gUnknown_3001B5C->input,index);
      species = gUnknown_3001B5C->unkC[(gUnknown_3001B5C->input.unk1E * gUnknown_3001B5C->input.unk1C + index)];
      sub_8092638(GetFriendArea(species),&auStack_2c,0,0);
      color = 7;
      if (auStack_2c.unk4 != 0) {
        color = HasRecruitedMon(species) ? 5 : 4;
      }
      iVar4 = GetDexInternalNo(species,0);
      cVar2 = (iVar4 % 10) + 0x30;
      sub_8012C60(0x14,y,cVar2,color,gUnknown_3001B5C->unk390);
      if (9 < iVar4) {
        iVar4 /= 10;
        cVar2 = (iVar4 % 10) + 0x30;
        sub_8012C60(0xd,y,cVar2,color,gUnknown_3001B5C->unk390);
        if (9 < iVar4) {
          uVar3 = iVar4 / 10;
          cVar2 = (uVar3 % 10) + 0x30;
          sub_8012C60(6,y,cVar2,color,gUnknown_3001B5C->unk390);
        }
      }
      sub_808D930(buffer1,species);
      sprintfStatic(buffer2,gUnknown_80DC93C,color,buffer1); // {COLOR_2}%c%s
      xxx_call_draw_string(0x24,y,buffer2,gUnknown_3001B5C->unk390,0);
  }
  sub_80073E0(gUnknown_3001B5C->unk390);
}

u32 sub_80236A4(void)
{
  s16 index_s32;
  int index;
  s32 temp;
  
  gUnknown_3001B5C->unk8 = 0;
  for(index = 0; index < 0x1a8; index++)
  {
    index_s32 = index;
    if ((sub_8098134(index_s32)) &&
       (index_s32 == GetBaseSpeciesNoUnown(index_s32))) {
      temp = gUnknown_3001B5C->unk8;
      gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk8] = index;
      gUnknown_3001B5C->unk8 = temp + 1;
    }
  }
  sub_8023730();
  return gUnknown_3001B5C->unk8;
}

bool8 sub_8023704(u8 unused)
{
  s32 index;
  
  for(index = 0; index < 0x1a8; index++)
  {
    if (sub_8098134((s16)index))
        return FALSE;
  }
  return TRUE;
}

void sub_8023730(void) 
{
    switch(gUnknown_3001B5C->unk4)
    {
        case 1:
            sub_8023758();
            break;
        case 2:
            sub_80237E0();
            break;
        
    }
}
