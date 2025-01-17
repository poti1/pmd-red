#include "global.h"
#include "bg.h"
#include "input.h"
#include "music.h"
#include "debug.h"

typedef void (*IntrCallback)(void);
extern IntrCallback gIntrCallbacks[];

struct unkStruct_202D648
{
    s16 unk0;
    s16 unk2; // Vcount??
    IntrCallback unk4; // some function... just making it IntrCallback for now
};
extern struct unkStruct_202D648 gUnknown_202D648[8];
extern struct unkStruct_202D648 gUnknown_202D608[8];

extern u8 gUnknown_202D7FE;
extern u16 gBldCnt;

EWRAM_DATA u8 gUnknown_203B099;
EWRAM_DATA u8 gUnknown_203B09A;
EWRAM_DATA u8 gUnknown_203B09B;
EWRAM_DATA u32 gUnknown_203B09C;
EWRAM_DATA u32 gUnknown_203B0A0;
EWRAM_DATA u32 gUnknown_203B0A4;
EWRAM_DATA u32 gUnknown_203B0A8;
EWRAM_DATA s16 gUnknown_203B0AA;
EWRAM_DATA s16 gUnknown_203B0AC;
EWRAM_DATA s16 gUnknown_203B0AE;
EWRAM_DATA s16 gUnknown_203B0B0;
EWRAM_DATA s16 gUnknown_203B0B2;

extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
void xxx_update_bg_sound_input();
extern void AckInterrupt(u16);
void BlinkSavingIcon();

void UnusedIntrFunc(void)
{
}

void VBlankIntr(void)
{
    int index;

    gUnknown_203B0A0++;
    SoundVSync();
    BlinkSavingIcon();
    if (gIntrCallbacks[1] != NULL) {
        gIntrCallbacks[1]();
    }
    for(index = 0; index < gUnknown_203B0AA; index++) {
        gUnknown_202D648[index] = gUnknown_202D608[index];
    }
    gUnknown_203B0AC = gUnknown_203B0AA;
    gUnknown_203B0AE = -1;
    gUnknown_203B0B0 = -1;
    gUnknown_203B0B2 = -1;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;
    if (gUnknown_203B099 == 0) {
        UpdateSound();
    }
    AckInterrupt(INTR_FLAG_VBLANK);
}

// Registers are a little off.. seems to be around the while loop
#ifdef NONMATCHING
void VCountIntr(void)
{
  s32 sVar1;
  s32 sVar2;
  
  // Hack to get the lsr/asr shifts
  sVar2 = REG_VCOUNT << 16;
  sVar2 = sVar2 >> 16;

  if (gUnknown_203B0AE < 0) {
    if (gIntrCallbacks[2] != 0) {
      gIntrCallbacks[2]();
    }
    gUnknown_203B0AE = 0;
  }
  if (gUnknown_203B0AE < gUnknown_203B0AC) {
    sVar1 = gUnknown_202D648[gUnknown_203B0AE].unk2;
    while (sVar1 <= sVar2) {
      if ( gUnknown_202D648[gUnknown_203B0AE].unk4 != NULL) {
        gUnknown_202D648[gUnknown_203B0AE].unk4();
      }
      gUnknown_203B0AE++;
      if (gUnknown_203B0AC >= gUnknown_203B0AE) break;
      sVar1 = gUnknown_202D648[gUnknown_203B0AE].unk2;
    }
    if (gUnknown_203B0AE < gUnknown_203B0AC) {
      REG_DISPSTAT = gUnknown_202D648[gUnknown_203B0AE].unk2 << 8 | DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;
    }
  }
  AckInterrupt(INTR_FLAG_VCOUNT);
}
#else
NAKED
void VCountIntr(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tldr r0, _0800BA44\n"
	"\tldrh r0, [r0]\n"
	"\tlsls r0, 16\n"
	"\tasrs r6, r0, 16\n"
	"\tldr r0, _0800BA48\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r0, r2]\n"
	"\tadds r7, r0, 0\n"
	"\tcmp r1, 0\n"
	"\tbge _0800B9B2\n"
	"\tldr r0, _0800BA4C\n"
	"\tldr r0, [r0, 0x8]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800B9AE\n"
	"\tbl _call_via_r0\n"
"_0800B9AE:\n"
	"\tmovs r0, 0\n"
	"\tstrh r0, [r7]\n"
"_0800B9B2:\n"
	"\tldr r0, _0800BA50\n"
	"\tmovs r3, 0\n"
	"\tldrsh r2, [r7, r3]\n"
	"\tmovs r3, 0\n"
	"\tldrsh r1, [r0, r3]\n"
	"\tmov r8, r0\n"
	"\tcmp r2, r1\n"
	"\tbge _0800BA34\n"
	"\tldr r1, _0800BA54\n"
	"\tadds r0, r2, 0\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tmovs r3, 0x2\n"
	"\tldrsh r0, [r0, r3]\n"
	"\tcmp r0, r6\n"
	"\tbgt _0800BA10\n"
	"\tadds r5, r1, 0\n"
	"\tadds r4, r7, 0\n"
"_0800B9D6:\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r4, r1]\n"
	"\tlsls r0, 3\n"
	"\tadds r1, r5, 0x4\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800B9EA\n"
	"\tbl _call_via_r0\n"
"_0800B9EA:\n"
	"\tldrh r0, [r4]\n"
	"\tadds r0, 0x1\n"
	"\tstrh r0, [r4]\n"
	"\tldr r1, _0800BA50\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r1, r2]\n"
	"\tcmp r0, r1\n"
	"\tbge _0800BA34\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r4, r3]\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r5\n"
	"\tmovs r1, 0x2\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tldr r7, _0800BA48\n"
	"\tcmp r0, r6\n"
	"\tble _0800B9D6\n"
"_0800BA10:\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r7, r2]\n"
	"\tmov r3, r8\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r3, r2]\n"
	"\tcmp r1, r0\n"
	"\tbge _0800BA34\n"
	"\tldr r2, _0800BA58\n"
	"\tldr r1, _0800BA54\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r7, r3]\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrh r0, [r0, 0x2]\n"
	"\tlsls r0, 8\n"
	"\tmovs r1, 0x28\n"
	"\torrs r0, r1\n"
	"\tstrh r0, [r2]\n"
"_0800BA34:\n"
	"\tmovs r0, 0x4\n"
	"\tbl AckInterrupt\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800BA44: .4byte 0x04000006\n"
"_0800BA48: .4byte gUnknown_203B0AE\n"
"_0800BA4C: .4byte gIntrCallbacks\n"
"_0800BA50: .4byte gUnknown_203B0AC\n"
"_0800BA54: .4byte gUnknown_202D648\n"
"_0800BA58: .4byte 0x04000004"
    );
}
#endif

void sub_800BA5C(void)
{
    if(gUnknown_203B09A != 0)
    {
        gUnknown_203B09C++;
        xxx_update_bg_sound_input();
    }
    gUnknown_203B09A = 1;
    gUnknown_203B09B = 0;
    gUnknown_203B09C = 0;
    nullsub_25();

    while(REG_VCOUNT > 159){}

    gUnknown_203B099 = 1;
    VBlankIntrWait();
    nullsub_18();
}

void xxx_update_bg_sound_input(void)
{
    if(gUnknown_203B09B != 0){
        gUnknown_203B09C++;
    }
    else {
        gUnknown_203B09B = 1;
        gUnknown_203B09A = 0;
        gUnknown_203B09C = 0;
        UpdateBGControlRegisters();
        if(gUnknown_203B099 != 0)
            UpdateSound();
        UpdateInput();
        gUnknown_203B099 = 0;
        gUnknown_203B0A4 = gUnknown_203B0A0;
    }
}

void Timer3Intr(void)
{
    if(gIntrCallbacks[4])
        gIntrCallbacks[4]();
    AckInterrupt(INTR_FLAG_TIMER3);
}

// Unused
u32 sub_800BB34(void)
{
    return gUnknown_203B0A0;
}

void nullsub_178(void)
{
}

// Unused
void sub_800BB44(void)
{
    u16 ie_store;
    u16 dispcnt_store;
    bool8 interrupt_flag;

    while(REG_KEYINPUT != KEYS_MASK){}

    interrupt_flag = DisableInterrupts();

    while(REG_VCOUNT < 160){}

    dispcnt_store = REG_DISPCNT;
    REG_DISPCNT = DISPCNT_FORCED_BLANK;

    *(vu16 *)BG_PLTT = RGB_WHITE;

    ie_store = REG_IE;
    REG_IE = INTR_FLAG_KEYPAD | INTR_FLAG_GAMEPAK;

    REG_KEYCNT = KEY_AND_INTR | R_BUTTON | L_BUTTON | SELECT_BUTTON; // 0x8304
    REG_IME = 1;

    SoundBiasReset();
    asm("swi 0x3");
    SoundBiasSet();

    REG_IME = 0;
    REG_IE = ie_store;
    REG_KEYCNT = 0;
    REG_DISPCNT = dispcnt_store;
    *(vu16 *)BG_PLTT = RGB_BLACK;

    if(interrupt_flag)
        EnableInterrupts();
    while(REG_KEYINPUT != KEYS_MASK){}
}

void nullsub_17(void)
{
}

void UpdateBGControlRegisters(void)
{
    u32 BGCNT_Priority[NUM_BGS];

    if(gUnknown_202D7FE == 1)
    {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }
    else
    {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }

    REG_BG0HOFS = gBG0Control.hofs;
    REG_BG0VOFS = gBG0Control.vofs;
    REG_BG1HOFS = gBG1Control.hofs;
    REG_BG1VOFS = gBG1Control.vofs;
    REG_BG2HOFS = gBG2Control.hofs;
    REG_BG2VOFS = gBG2Control.vofs;
    REG_BG3HOFS = gBG3Control.hofs;
    REG_BG3VOFS = gBG3Control.vofs;

    REG_BG0CNT = BGCNT_Priority[BG0] | BGCNT_SCREENBASE(12) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2C00
    REG_BG1CNT = BGCNT_Priority[BG1] | BGCNT_SCREENBASE(13) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2D00
    if(gBG2Control.unk2 == 0x8000)
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(2) | BGCNT_WRAP; // 0x2E08
    else
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2E00
    REG_BG3CNT = BGCNT_Priority[BG3] | BGCNT_SCREENBASE(15) | BGCNT_CHARBASE(2) | BGCNT_WRAP;
    REG_BLDCNT = gBldCnt;
}
