#ifndef FLAGS_H
#define FLAGS_H

#include "global.h"

u32 CheckFlags(u32);
u32 CheckGlobalFlag(u32);
u32 CheckGlobalFlags(u32, u32);
extern u32 CheckLocalFlag(u32);
extern u32 CheckLocalFlagByBank(u32, u32);
u32 CheckLocalFlags(u32, u32);
u32 CheckLocalFlagsByBank(u32, u32, u32);
u32 CheckRoomFlag(u32);
u32 CheckRoomFlags(u32, u32);

void ClearFlag(u32);
void ClearGlobalFlag(u32);
void ClearLocalFlag(u32);
void ClearLocalFlagByBank(u32, u32);
void ClearRoomFlag(u32);

void SetFlag(u32);
void SetGlobalFlag(u32);
void SetLocalFlag(u32);
void SetLocalFlagByBank(u32, u32);
void SetRoomFlag(u32);

extern u32 ReadBit(u32*, u32);
extern u32 CheckBits(u32*, u32, u32);
extern void WriteBit(u32*, u32);
extern void ClearBit(u32*, u32);

extern u32 gGlobalFlags;
extern u32 gRoomFlags;

extern const u16 gLocalFlagBanks[];

enum LocalFlagOffsets {
    FLAG_BANK_G = 0,
    FLAG_BANK_0 = 0,
    FLAG_BANK_1 = 0x100,
    FLAG_BANK_2 = 0x200,
    FLAG_BANK_3 = 0x300,
    FLAG_BANK_4 = 0x400,
    FLAG_BANK_5 = 0x500,
    FLAG_BANK_6 = 0x5C0,
    FLAG_BANK_7 = 0x680,
    FLAG_BANK_8 = 0x740,
    FLAG_BANK_9 = 0x800,
    FLAG_BANK_10 = 0x8C0,
    FLAG_BANK_11 = 0x9C0,
    FLAG_BANK_12 = 0xA80,
};

typedef enum {
    BEGIN,
    /*0x01*/ LV0_CLEAR,           /*                             */
    /*0x02*/ LV1_CLEAR,           /*                             */
    /*0x03*/ LV2_CLEAR,           /*                             */
    /*0x04*/ LV3_CLEAR,           /*                             */
    /*0x05*/ LV4_CLEAR,           /*                             */
    /*0x06*/ LV5_CLEAR,           /*                             */
    /*0x07*/ LV6_CLEAR,           /*                             */
    /*0x08*/ LV7_CLEAR,           /*                             */
    /*0x09*/ LV8_CLEAR,           /*                             */
    /*0x0a*/ MACHI_SET_1,         /* Defeated Big Green Chuchu   */
    /*0x0b*/ MACHI_SET_2,         /* Defeated Gleerok            */
    /*0x0c*/ MACHI_SET_3,         /*                             */
    /*0x0d*/ MACHI_SET_4,         /* Defeated Big Octorok        */
    /*0x0e*/ MACHI_SET_5,         /* Defeated Gyorg Pair         */
    /*0x0f*/ MACHI_SET_6,         /*                             */
    /*0x10*/ MACHI_SET_7,         /*                             */
    /*0x11*/ MACHI_SET_8,         /*                             */
    /*0x12*/ MACHI_MACHIHOKORI,   /* Sucked dust from carpet     */
    /*0x13*/ START,               /* Met Zelda                   */
    /*0x14*/ EZERO_1ST,           /* Met Ezlo                    */
    /*0x15*/ TABIDACHI,           /* Talked to Daltus and Smith  */
    /*0x16*/ LV1TARU,             /*                             */
    /*0x17*/ LV1TARU_OPEN,        /* Sucked barrel web           */
    /*0x18*/ TATEKAKE_HOUSE,      /* Red house complete          */
    /*0x19*/ TATEKAKE_TOCHU,      /* Red house frame             */
    /*0x1a*/ WATERBEAN_OUT,       /* Holding bean                */
    /*0x1b*/ WATERBEAN_PUT,       /* Threw bean in hole          */
    /*0x1c*/ ZELDA_CHASE,         /* Enter town festival         */
    /*0x1d*/ INLOCK,              /* Gave key to Talon           */
    /*0x1e*/ DASHBOOTS,           /* Read Castor Wilds sign      */
    /*0x1f*/ LEFT_DOOR_OPEN,      /* Spoke to Dr. Left           */
    /*0x20*/ HAKA_KEY_LOST,       /* Graveyard key stolen        */
    /*0x21*/ HAKA_KEY_FOUND,      /* Graveyard key obtained back */
    /*0x22*/ ENTRANCE_OK,         /*                             */
    /*0x23*/ TATSUMAKI,           /*                             */
    /*0x24*/ KUMOTATSUMAKI,       /* Vortex spawned              */
    /*0x25*/ KAITENGIRI,          /*                             */
    /*0x26*/ DAIKAITENGIRI,       /*                             */
    /*0x27*/ GATOTSU,             /*                             */
    /*0x28*/ KABUTOWARI,          /*                             */
    /*0x29*/ MIZUKAKI_START,      /* Spoke to Lake Hylia Minish  */
    /*0x2a*/ MIZUKAKI_HARIFALL,   /* Library book falling        */
    /*0x2b*/ RENTED_HOUSE_DIN,    /* Din moves to blue house     */
    /*0x2c*/ RENTED_HOUSE_NAYRU,  /* Nayru moves to blue house   */
    /*0x2d*/ RENTED_HOUSE_FARORE, /* Farore moves to blue house  */
    /*0x2e*/ NEW_HOUSE_DIN,       /* Din moves to red house      */
    /*0x2f*/ NEW_HOUSE_NAYRU,     /* Nayru moves to red house    */
    /*0x30*/ NEW_HOUSE_FARORE,    /* Farore moves to red house   */
    /*0x31*/ OUGONTEKI_A,         /* Golden Octorok defeated     */
    /*0x32*/ OUGONTEKI_B,         /* Golden Tektite defeated     */
    /*0x33*/ OUGONTEKI_C,         /* Golden Rope defeated        */
    /*0x34*/ OUGONTEKI_D,         /* Golden Rope defeated        */
    /*0x35*/ OUGONTEKI_E,         /* Golden Rope defeated        */
    /*0x36*/ OUGONTEKI_F,         /* Golden Tektite defeated     */
    /*0x37*/ OUGONTEKI_G,         /* Golden Tektite defeated     */
    /*0x38*/ OUGONTEKI_H,         /* Golden Octorok defeated     */
    /*0x39*/ OUGONTEKI_I,         /* Golden Octorok defeated     */
    /*0x3a*/ KAKERA_COMPLETE,     /* All fusions complete        */
    /*0x3b*/ DRUG_1,              /* Yellow pico bloomed         */
    /*0x3c*/ DRUG_2,              /* Blue pico bloomed           */
    /*0x3d*/ DRUG_3,              /* Orange pico bloomed         */
    /*0x3e*/ GORON_KAKERA_LV2,    /* Goron merchant restock 1    */
    /*0x3f*/ GORON_KAKERA_LV3,    /* Goron merchant restock 2    */
    /*0x40*/ GORON_KAKERA_LV4,    /* Goron merchant restock 3    */
    /*0x41*/ GORON_KAKERA_LV5,    /* Goron merchant restock 4    */
    /*0x42*/ GORON_KAKERA_L,      /* Red kinstone sold out       */
    /*0x43*/ GORON_KAKERA_M,      /* Blue kinstone sold out      */
    /*0x44*/ GORON_KAKERA_R,      /* Green kinstone sold out     */
    /*0x45*/ CHIKATSURO_SHUTTER,  /* Castle basement door open   */
    /*0x46*/ ENTRANCE_USED,       /*                             */
    /*0x47*/ GOMAN_RENTED_HOUSE,  /* Spoke to Gorman blue house  */
    /*0x48*/ GOMAN_NEW_HOUSE,     /* Spoke to Gorman red house   */
    /*0x49*/ OUTDOOR,             /* Exited Link's house         */
    /*0x4a*/ POWERGLOVE_HINT,     /* Spoke to Dr. Left Minish    */
    /*0x4b*/ ANJU_LV_BIT0,        /* Cucco game 1 bit            */
    /*0x4c*/ ANJU_LV_BIT1,        /* Cucco game 2 bit            */
    /*0x4d*/ ANJU_LV_BIT2,        /* Cucco game 4 bit            */
    /*0x4e*/ ANJU_LV_BIT3,        /* Cucco game 8 bit            */
    /*0x4f*/ ANJU_HEART,          /* Cucco heart piece           */
    /*0x50*/ MAROYA_WAKEUP,       /*                             */
    /*0x51*/ ENDING,              /* Vaati's wrath defeated      */
    /*0x52*/ WARP_1ST,            /* Wind ocarina unlocked       */
    /*0x53*/ WARP_MONUMENT,       /* First windcrest discovered  */
    /*0x54*/ DRUG_COUNT,          /* Pico bloom minish items     */
    /*0x55*/ GAMECLEAR,           /* Watched end cutscene        */
    /*0x56*/ WHITE_SWORD_END,     /* Exit mines with white sword */
    /*0x57*/ SOUGEN_06_HASHIGO,   /* Boomerang cave ladder       */
    /*0x58*/ WARP_EVENT_END,      /* Wind tribe tower state      */
    /*0x59*/ FIGURE_ALLCOMP,      /* Obtained Carlov Medal       */
    /*0x5a*/ AKINDO_BOTTLE_SELL,  /* Bought bottle from scrub    */
    /*0x5b*/ BIN_DOGFOOD,         /*                             */
    /*0x5c*/ TINGLE_TALK1ST,      /* Spoke to Tingle             */
    /*0x5d*/ SEIIKI_BGM,          /* Elemental sanctuary BGM     */
    /*0x5e*/ ENTRANCE_0,          /* Trunk entrance cutscene     */
    /*0x5f*/ ENTRANCE_1,          /* Rock entrance cutscene      */
    /*0x60*/ ENTRANCE_2,          /* Pot entrance cutscene       */
    /*0x61*/ MIZUKAKI_NECHAN,     /* Spoke to librarian          */
    /*0x62*/ MAZE_CLEAR,          /* Cleared Castle maze         */
    /*0x63*/ TINY_ENTRANCE,       /* Ezlo described entrances    */
    /*0x64*/ CASTLE_BGM,          /* Castle intro BGM            */
    END,
} Flag;

typedef enum {
    BEGIN_1,
    LV1_CLEAR_MES,
    LV2_CLEAR_MES,
    LV3_CLEAR_MES,
    LV4_CLEAR_MES,
    LV5_CLEAR_MES,
    MIZUUMI_00_BENT,
    MIZUUMI_00_00,
    MIZUUMI_00_H00,
    MIZUUMI_00_H01,
    MIZUUMI_00_H02,
#if !defined(EU) && !defined(JP) && !defined(DEMO_JP)
    MIZUUMI_00_CAP_0,
#else
    HIKYOU_00_T0,
    HIKYOU_00_T1,
#endif
    MAENIWA_00_00,
    MAENIWA_00_01,
    MAENIWA_00_02,
    MAENIWA_00_BENT,
    MAENIWA_00_WARP,
    MAENIWA_00_T0,
    MAENIWA_00_T1,
    MAENIWA_00_CAP_0,
    NAKANIWA_00_EZERO,
    HIKYOU_00_00,
    HIKYOU_00_01,
    HIKYOU_00_02,
    HIKYOU_00_03,
    HIKYOU_00_04,
    HIKYOU_00_CAP_0,
    HIKYOU_00_CAP_1,
    HIKYOU_00_CAP_2,
    HIKYOU_00_SEKIZOU,
    HIKYOU_00_14,
    HIKYOU_00_BOSEKI,
#if defined(EU) || defined(JP) || defined(DEMO_JP)
    HIKYOU_00_H00,
#endif
    HIKYOU_00_M0,
    HIKYOU_00_M1,
    HIKYOU_00_M2,
#if !defined(EU) && !defined(JP) && !defined(DEMO_JP)
    HIKYOU_00_T1,
#endif
    LOST_00_ENTER,
    LOST_00_00,
    LOST_00_01,
    LOST_02_00,
    LOST_03_00,
    LOST_03_T0,
    LOST_04_00,
    LOST_04_SIBA0,
    LOST_04_SIBA1,
    LOST_04_SIBA2,
    LOST_04_SIBA3,
    LOST_04_SIBA4,
    LOST_05_00,
    LOST_05_01,
#if !defined(JP) && !defined(EU) && !defined(DEMO_JP)
    LOST_05_02,
    LOST_05_03,
#endif
    LOST_05_T0,
    LOST_05_T1,
    MORI_00_HIBI_0,
    MORI_00_HIBI_1,
    MORI_00_HIBI_2,
    MORI_00_HIBI_3,
    MORI_00_HIBI_4,
    MORI_00_KOBITO,
    MORI_00_H0,
    MORI_00_H1,
    MORI_ENTRANCE_1ST,
    YAMA_00_00,
    YAMA_00_01,
    YAMA_01_BW00,
    YAMA_02_00,
    YAMA_03_00,
    YAMA_03_01,
    YAMA_03_02,
    YAMA_03_DOKU_0,
    YAMA_03_DOKU_1,
    YAMA_03_DOKU_2,
    YAMA_04_CAP_0,
#if !defined(JP) && !defined(EU) && !defined(DEMO_JP)
    YAMA_04_CAP_1,
#endif
    YAMA_04_R00,
    YAMA_04_HIBI_0,
    YAMA_04_HIBI_1,
    YAMA_04_00,
    YAMA_04_01,
    YAMA_04_04,
    YAMA_04_05,
    YAMA_04_06,
    YAMA_04_ENTHOUSHI,
    YAMA_04_ANAHOUSHI,
    YAMA_04_BOMBWALL0,
    HAKA_BUNSHIN_00,
    HAKA_BOSEKI_00,
    HAKA_BOSEKI_01,
    HAKA_BOSEKI_02,
    HAKA_00_CAP_0,
    HAKA_00_BW00,
    HAKA_01_T0,
    HAKA_KEY_GET,
    SOUGEN_01_WAKAGI_0,
    SOUGEN_01_WAKAGI_1,
    SOUGEN_01_WAKAGI_2,
    SOUGEN_01_WAKAGI_3,
    SOUGEN_01_WAKAGI_4,
    SOUGEN_01_WAKAGI_5,
    SOUGEN_01_WAKAGI_6,
    SOUGEN_01_WAKAGI_7,
    SOUGEN_01_WAKAGI_8,
    SOUGEN_01_WAKAGI_9,
    SOUGEN_01_WAKAGI_10,
    SOUGEN_01_WAKAGI_11,
    SOUGEN_01_WAKAGI_12,
    SOUGEN_01_00,
    SOUGEN_01_BENT,
    SOUGEN_01_ZELDA,
    SOUGEN_02_HIBI_0,
    SOUGEN_02_HIBI_1,
    SOUGEN_03_BOMBWALL,
    SOUGEN_04_HIBI_0,
    SOUGEN_04_HIBI_1,
    SOUGEN_04_HIBI_2,
    SOUGEN_04_HIBI_3,
    SOUGEN_05_HIBI_0,
    SOUGEN_05_HIBI_1,
    SOUGEN_05_HIBI_2,
    SOUGEN_05_HIBI_3,
    SOUGEN_05_BOMB_00,
    SOUGEN_05_00,
    SOUGEN_05_01,
    SOUGEN_05_IWA02,
    SOUGEN_05_BENT,
    SOUGEN_05_H00,
    SOUGEN_05_R0,
    SOUGEN_05_CAP_0,
    SOUGEN_06_WAKAGI_0,
    SOUGEN_06_WAKAGI_1,
    SOUGEN_06_WAKAGI_2,
    SOUGEN_06_WAKAGI_3,
    SOUGEN_06_HIBI_0,
    SOUGEN_06_HIBI_1,
    SOUGEN_06_HIBI_2,
    SOUGEN_06_HIBI_3,
    SOUGEN_06_HIBI_4,
    SOUGEN_06_IWA_0,
    SOUGEN_06_AKINDO,
    SOUGEN_06_SAIKAI,
    SOUGEN_06_BENT,
    SOUGEN_06_SLIDE,
    SOUGEN_06_R1,
    SOUGEN_07_00,
    SOUGEN_07_01,
    SOUGEN_07_02,
#if defined(JP) || defined(EU) || defined(DEMO_JP)
    SOUGEN_07_H00,
#endif
    SOUGEN_08_00,
    SOUGEN_08_01,
    SOUGEN_08_02,
    SOUGEN_08_03,
    SOUGEN_08_04,
    SOUGEN_08_05,
    SOUGEN_08_06,
    SOUGEN_08_07,
    SOUGEN_08_08,
    SOUGEN_08_TORITSUKI,
    SOUGEN_08_T00,
    CASTLE_00_00,
    CASTLE_04_MEZAME,
    CASTLE_04_MAID_TALK,
    SUIGEN_00_h0,
    SUIGEN_00_T0,
    SUIGEN_00_r0,
    SUIGEN_00_r1,
    SUIGEN_00_r2,
    SUIGEN_00_CAP_0,
    SUIGEN_00_CAP_1,
    SUIGEN_00_R0,
    SUIGEN_00_R1,
#if !defined(JP) && !defined(EU) && !defined(DEMO_JP)
    SUIGEN_00_R2,
#endif
    SUIGEN_00_h1,
    SUIGENGORON_00_CAP_0,
    DAIGORON_SHIELD,
    DAIGORON_EXCHG,
    BEANDEMO_00,
    BEANDEMO_01,
    BEANDEMO_02,
    BEANDEMO_03,
    BEANDEMO_04,
    KAKERA_TAKARA_A,
    KAKERA_TAKARA_E,
#if !defined(JP) && !defined(EU) && !defined(DEMO_JP)
    KAKERA_TAKARA_J,
#endif
    KAKERA_TAKARA_K,
    KAKERA_TAKARA_L,
    KAKERA_TAKARA_M,
    KAKERA_TAKARA_N,
    KAKERA_TAKARA_O,
    KAKERA_TAKARA_P,
    KAKERA_TAKARA_Q,
    KAKERA_TAKARA_R,
    KAKERA_TAKARA_S,
    KAKERA_TAKARA_T,
    KAKERA_TAKARA_U,
    KAKERA_TAKARA_V,
    KAKERA_TAKARA_W,
    KAKERA_TAKARA_X,
    KAKERA_TAKARA_Y,
    KAKERA_TAKARA_Z,
    MACHI_02_HEISHI_TALK,
    MACHI00_00,
    MACHI00_02,
    MACHI00_03,
    MACHI_00_T00,
    MACHI_00_T01,
    MACHI_01_DEMO,
    MACHI_02_HEISHI,
    MACHI_02_DOG, /* Talk to dog as minish       */
    MACHI_07_BELL,
    SHOP05_OPEN,
    MACHI_MES_20,
    MACHI_MES_21,
    MACHI_MES_22,
    MACHI_MES_23,
    MACHI_MES_24,
    MACHI_MES_30,
    MACHI_MES_40,
    MACHI_MES_60,
    MACHI_MES_50,
    MACHI_DOG_C, /* Seen all dog dialogue        */
    KUMOUE_00_CAP_0,
    KUMOUE_01_CAP_0,
    KUMOUE_01_T0,
    KUMOUE_01_T1,
    KUMOUE_01_T2,
    KUMOUE_01_T3,
    KUMOUE_01_T4,
    KUMOUE_01_T5,
    KUMOUE_01_T6,
    KUMOUR_01_K0,
    KUMOUR_01_K1,
    KUMOUR_01_K2,
    KUMOUR_01_K3,
    KUMOUR_01_K4,
    KUMOUR_01_K5,
    KUMOUR_01_K6,
    KUMONOUE_01_KAKERA,
    KUMOUE_02_CAP_0,
    KUMOUE_02_AWASE_01,
    KUMOUE_02_AWASE_02,
    KUMOUE_02_AWASE_03,
    KUMOUE_02_AWASE_04,
    KUMOUE_02_AWASE_05,
    KUMOUE_02_00,
    KUMOUE_02_01,
    KUMOUE_02_02,
    KUMOUE_02_03,
    KUMOUE_UNCLE_TALK,
    KUMOUE_GIRL_TALK,
#if !defined(JP) && !defined(EU) && !defined(DEMO_JP)
    KS_A06,
    KS_B18,
    KS_C21,
    KS_C25,
#else
    MIZUUMI_00_CAP_0,
    SUIGEN_00_R2,
    YAMA_04_CAP_1,
    LOST_05_02,
    LOST_05_03,
    KAKERA_TAKARA_J,
#endif
#ifdef DEMO_JP
    KS_WARPUSE,
#endif
    END_1,
} LocalFlags1;

typedef enum {
    BEGIN_2,
    BILL05_YADO1F_MATSU_T0,
    BILL06_YADO1F_TAKE_T0,
    BILL07_YADO1F_UME_T0,
    BILL0A_YADO_TAKARA_T0,
    SHOUSE_00_T0,
    SHOUSE_00_T1,
    SHOUSE_01_T0,
    SHOUSE_02_T0,
    SHOUSE_02_T1,
    SHOUSE_02_T2,
    SHOUSE_02_XXXX0,
    SHOUSE_02_XXXX1,
    SHOUSE_02_XXXX2,
    SHOUSE_03_T0,
    SHOUSE_03_T1,
    KOBITOANA_06_T0,
    KOBITOANA_03_T0,
    KOBITOANA_07_T0,
    KOBITOANA_09_T0,
    KOBITOANA_0A_T0,
    KOBITOANA_0B_T0,
    MHOUSE11_T0,
    URO_08_T0,
    URO_0A_T0,
    URO_0B_T0,
    BILL00_SHICHOU_00,
    BILL00_SHICHOU_01,
    BILL00_SHICHOU_02,
    BILL00_SHICHOU_03,
    BILL00_SHICHOU_04,
    BILL01_TESSIN_1,
    BILL01_TESSIN_2,
    BILL01_TESSIN_3,
    BILL01_TESSIN_4,
    BILL01_TESSIN_5,
    BILL01_TESSIN_6,
    BILL01_TESSIN_7,
    BILL01_TESSIN_8,
    BILL09_YADO2F_POEMN,
    BILL0A_YADO_TAKARA_00,
    BILL0B_SCHOOLL_00,
    BILL0C_SCHOOLR_00,
    MHOUSE00_00,
    MHOUSE00_01,
    MHOUSE00_02,
    MHOUSE00_03,
    MHOUSE00_04,
    MHOUSE00_05,
    MHOUSE01_00,
    MHOUSE01_01,
    MHOUSE01_02,
    MHOUSE01_03,
    MHOUSE03_00,
    MHOUSE03_01,
    MHOUSE04_00,
    MHOUSE04_01,
    MHOUSE04_02,
    MHOUSE04_03,
    MHOUSE04_04,
    MHOUSE06_00,
    MHOUSE07_00,
    MHOUSE07_01,
    MHOUSE08_00,
    MHOUSE08_01,
    MHOUSE08_02,
    MHOUSE08_03,
    MHOUSE08_04,
    MHOUSE0C_00,
    MHOUSE14_00,
    MHOUSE15_OP1ST,
    MHOUSE2_00_00,
    MHOUSE2_00_01,
    MHOUSE2_00_02,
    MHOUSE2_00_03,
    MHOUSE2_01_T0,
    MHOUSE2_02_KAME,
    MHOUSE2_02_KEY,
    MHOUSE2_03_00,
    MHOUSE2_05_00,
    SHOP00_ITEM_00,
    SHOP00_ITEM_01,
    SHOP00_ITEM_02,
    SHOP00_ITEM_03,
    SHOP00_ITEM_04,
    SHOP00_SAIFU,
    SHOP00_YAZUTSU,
    SHOP01_CAFE_00,
    SHOP01_CAFE_01,
    SHOP01_TALK,
    HOUSE_XXXXX,
    SHOP03_PAN_1ST,
    SHOP07_TALK1ST,
    SHOP07_GACHAPON,
    SHOP07_TANA,
    SHOP07_COMPLETE,
    SHOP02_KUTSU_00,
    NPC37_REM_TALK1ST,
    NPC37_REM_SLEEP,
    SORA_ELDER_RECOVER,
    SORA_CHIEF_TALK,
    SORA_ELDER_TALK1ST,
    SORA_ELDER_TALK2ND,
    NPC06_19GUY_QUESTION,
    NPC06_19GUY_ANSWER,
    DANPEI_TALK1ST,
    MIZUKAKI_KOBITO,
    MIZUKAKI_HINT1,
    MIZUKAKI_BOOK1_FALL,
    MIZUKAKI_HINT2,
    MIZUKAKI_HINT2_2ND,
    MIZUKAKI_BOOK2_FALL,
    MIZUKAKI_HINT3,
    MIZUKAKI_HINT3_MAYOR,
    MIZUKAKI_BOOK3_FALL,
    MIZUKAKI_BOOK_ALLBACK,
    MIZUKAKI_STAIR,
    MIZUKAKI_STAIR_WARP_OK,
    KHOUSE27_00,
    NO_USE_00,
    KHOUSE51_00,
    NO_USE_01,
    KHOUSE51_02,
    KHOUSE42_00,
    NO_USE_02,
    NO_USE_03,
    OYAKATA_DEMO,
    YAMAKOBITO_OPEN,
    M_PRIEST_TALK,
    M_ELDER_TALK1ST,
    M_PRIEST_MOVE,
    M_ELDER_TALK2ND,
    MHOUSE04_DANRO,
    MHOUSE06_DANRO,
    URO_POEMN_TALK,
    MHOUSE06_MES_20,
    MHOUSE07_MES_20,
    MAYOR_2_TALK1ST,
    MAYOR_4_TALK1ST,
    BILL01_TESSIN_RESERVED,
    BILL01_TESSIN_BRANDNEW,
    KOBITO_MORI_1ST,
    KOBITO_YAMA_ENTER,
    KHOUSE52_KINOKO,
    SORA_YAKATA_ENTER,
    YADO_CHECKIN,
    MINIGAME_GAMEEND,
    MINIGAME_LEVEL2,
    MHOUSE_DIN_TALK,
    MHOUSE_NAYRU_TALK,
    MHOUSE_FARORE_TALK,
    URO_12_H0,
    URO_19_H0,
    URO_1F_H0,
    BILL09_TSW0,
    BILL09_TSW1,
    KHOUSE41_TALK1ST,
    TAIMA_SAIBAI_1ST,
    IZUMI_00_FAIRY,
    IZUMI_01_FAIRY,
    IZUMI_02_FAIRY,
    BILL0B_DOUZOU_L,
    BILL0B_DOUZOU_R,
    KOBITOANA_08_T0,
    KOBITOANA_0C_T0,
    KOBITOANA_0D_T0,
    KOBITOHOUSE_23_H0,
    MHOUSE08_DANRO,
    MHOUSE09_DANRO,
    MHOUSE0A_DANRO,
    MHOUSE0B_DANRO,
    MHOUSE0C_DANRO,
    MHOUSE12_DANRO,
    SORA_DANRO,
    MIZUKAKI_HINT3_MAP,
    LEFT_TALK,
    KHOUSE26_REMOCON,
    SORA_KIDS_MOVE,
    KOBITOANA_00_T0,
    KHOUSE23_TALK1ST,
    SHOP05_ELEMENT_H00,
    SHOP05_ELEMENT_T00,
    SHOP05_ELEMENT_T01,
    SHOP05_ELEMENT_T02,
    BILL0a_YADO_TAKARA_H00,
    KOBITOYAMA_00_R00,
    KOBITOYAMA_00_R01,
    KOBITOYAMA_00_R02,
    KOBITOYAMA_00_R03,
    KOBITOYAMA_00_R04,
    KOBITOYAMA_00_R05,
    KOBITOYAMA_00_R06,
    KOBITOYAMA_00_R07,
    KOBITO_MORI_00_H00,
    KOBITO_MORI_00_H0,
    CAFE_01_CAP_0,
    BILL_00_CAP_0,
    BILL_02_CAP_0,
    MHOUSE_07_CAP_0,
    MHOUSE_07_CAP_1,
    MHOUSE_10_CAP_0, // links house entrance
    MHOUSE_15_CAP_0, // links bedroom
    MHOUSE_15_CAP_1,
    SHOP_03_CAP_0,
    MHOUSE_07_CAP_2,
#ifndef EU
    SHOP00_BOMBBAG,
    CAFE_01_CAP_1,
#endif
#if !defined(EU) && !defined(JP) && !defined(DEMO_JP)
    KS_A02,
    KS_A09,
    KS_A18,
    KS_B07,
    KS_B16,
#endif
#ifdef DEMO_JP
    MH01_KS_KUSURI,
    MH09_KS_KUSURI,
#endif
    END_2,
} LocalFlags2;

typedef enum {
    BEGIN_3,
    MAROYA_TAKARA,
    MACHI_CHIKA_00_00,
    MACHI_CHIKA_00_01,
    MACHI_CHIKA_00_02,
    MACHI_CHIKA_00_03,
    MACHI_CHIKA_00_T0,
    MACHI_CHIKA_00_T1,
    MACHI_CHIKA_00_T2,
    MACHI_CHIKA_00_T3,
    MACHI_CHIKA_00_T4,
    MACHI_CHIKA2_00_T0,
    MACHI_CHIKA2_01_T0,
    MACHI_CHIKA2_03_00,
    MACHI_CHIKA2_03_01,
    MACHI_CHIKA2_03_T0,
    MACHI_CHIKA2_04_T0,
    MACHI_CHIKA2_10_00,
    MACHI_CHIKA2_10_01,
    MACHI_CHIKA2_10_02,
    MACHI_CHIKA2_10_T0,
    MACHI_CHIKA2_12_T0,
    LV4_HAKA_05_T0,
    LV4_HAKA_04_T0,
    LV4_HAKA_04_T1,
    LV4_HAKA_01_00,
    LV4_HAKA_01_01,
    LV4_HAKA_03_00,
    LV4_HAKA_04_R0,
    LV4_HAKA_04_R1,
    LV4_HAKA_04_R2,
    LV4_HAKA_04_R3,
    LV4_HAKA_04_R4,
    LV4_HAKA_04_R5,
    LV4_HAKA_04_R6,
    LV4_HAKA_04_R8,
    LV4_HAKA_04_R9,
    LV4_HAKA_04_R10,
    LV4_HAKA_04_R11,
    LV4_HAKA_04_KB0,
    LV4_HAKA_04_KB1,
    LV4_HAKA_05_H0,
    LV4_HAKA_05_H1,
    LV4_HAKA_05_H2,
    LV4_HAKA_05_H3,
    OUBO_02_BW0,
    OUBO_02_BW1,
    OUBO_06_BW0,
    OUBO_06_BW1,
    OUBO_07_ENTER,
    OUBO_KAKERA,
    MOGURA_00_T0,
    MOGURA_00_T1,
    MOGURA_00_T2,
    MOGURA_01_T0,
    MOGURA_02_T0,
    MOGURA_02_T1,
    MOGURA_02_T2,
    MOGURA_02_T3,
    MOGURA_02_T4,
    MOGURA_02_T5,
    MOGURA_02_T6,
    MOGURA_02_T7,
    MOGURA_02_T8,
    MOGURA_09_T0,
    MOGURA_09_T1,
    MOGURA_10_T0,
    MOGURA_10_T1,
    MOGURA_10_T2,
    MOGURA_1c_T0,
    MOGURA_21_r0,
    MOGURA_27_T0,
    MOGURA_27_T1,
    MOGURA_27_T2,
    MOGURA_41_T0,
    MOGURA_41_T1,
    MOGURA_41_T2,
    MOGURA_41_T3,
    MOGURA_50_00,
    MOGURA_50_T0,
    MOGURA_51_T0,
    MOGURA_51_T1,
    MOGURA_51_T2,
    MOGURA_51_00,
    MOGURA_51_01,
    MOGURA_51_02,
    MOGURA_51_03,
    MOGURA_51_04,
    MOGURA_51_05,
    MOGURA_51_06,
    MOGURA_51_07,
    MOGURA_51_08,
    MOGURA_52_00,
    MOGURA_52_T0,
    MOGURA_52_T1,
    MOGURA_53_00,
    MOGURA_53_T0,
    MOGURA_53_T1,
    MOGURA_53_WALK,
    MOGURA_54_00,
    MOGURA_54_01,
    MOGURA_54_02,
    MOGURA_54_WALK,
    AMOS_00_00,
    AMOS_01_00,
    AMOS_02_00,
    AMOS_03_00,
    AMOS_04_00,
    AMOS_05_00,
    AMOS_06_00,
    AMOS_07_00,
    AMOS_08_00,
    AMOS_09_00,
    AMOS_0A_00,
    AMOS_0B_00,
    AMOS_0C_00,
    AMOS_0D_00,
    AMOS_0E_00,
    AMOS_0F_00,
    HARI_01_T0,
    SEIIKI_STAINED_GLASS,
    SEIIKI_ENTER,
    SEIIKI_SWORD_1ST,
    SEIIKI_SWORD_2ND,
    SEIIKI_SWORD_3RD,
    SEIIKI_BUNSHIN,
    BAGUZU_MORI_02_00,
    BAGUZU_MORI_02_T0,
    BAGUZU_MORI_02_T1,
    BAGUZU_MORI_02_T2,
    CHIKATSURO_01_BW00,
    SORA_10_H00,
    SORA_11_H00,
    SORA_11_T00,
    SORA_11_T01,
    SORA_12_T00,
    SORA_13_H00,
    SORA_13_T00,
    SORA_13_T01,
    SORA_14_T00,
    SORA_14_R00,
    SORA_14_R01,
    SORA_14_R02,
    SORA_14_R03,
    SORA_14_R04,
    SORA_14_R05,
    SORA_14_R06,
    SORA_14_R07,
    IZUMIGARE_00_H00,
    IZUMIGARE_00_H01,
    SORA_10_R00,
    SORA_10_R01,
    SORA_10_R02,
    SORA_10_R03,
    SORA_10_R04,
    SORA_10_R05,
    SORA_10_R06,
    SORA_10_R07,
    SORA_14_R08,
    SORA_14_R09,
    SORA_14_R0a,
    SORA_14_R0b,
    SORA_14_R0c,
    SORA_14_R0d,
    SORA_14_R0e,
    SORA_14_R0f,
    KAKERA_TAKARA_B,
    KAKERA_TAKARA_C,
    KAKERA_TAKARA_D,
    KAKERA_TAKARA_F,
    KAKERA_TAKARA_G,
    KAKERA_TAKARA_H,
    KAKERA_TAKARA_I,
    KAKERA_TAKARA_XXXX,
    TESTMAP00_00,
    TESTMAP01_00,
    TESTMAP01_01,
    TESTMAP02_00,
    LV4_HAKA_08_T0,
    LV4_HAKA_07_00,
    LV4_HAKA_04_00,
    LV4_HAKA_04_01,
    LV4_HAKA_04_K0,
    LV4_HAKA_04_K1,
    LV4_HAKA_01_02,
    LV4_HAKA_08_XX,
    BAGUZU_MORI_03_H00,
    MOGURAU_00_H00,
    HARI_01_H00,
    HARI_03_T00,
    MACHI_CHIKA2_00_CAP_0,
    MACHI_CHIKA2_11_CAP_0,
    LV4_HAKA_08_CAP_0,
    BAGUZUIWA_02_CAP_0,
    MACHI_CHIKA2_01_CAP_0,
    MACHI_CHIKA2_01_HK,
    LV4_HAKA_08_B0,
    LV4_HAKA_08_K0,
    MAROYA_1ST,
#ifndef EU
    MACHI_CHIKA2_10_CAP_0,
#endif
#if !defined(EU) && !defined(JP) && !defined(DEMO_JP)
    KS_C02,
#endif
    END_3,
} LocalFlags3;

typedef enum {
    BEGIN_4,
    DOUKUTU_00_T0,
    DOUKUTU_00_T1,
    DOUKUTU_05_EVENT,
    SOUGEN_DOUKUTU_00_T0,
    SOUGEN_DOUKUTU_00_T1,
    SOUGEN_DOUKUTU_00_T2,
    SOUGEN_DOUKUTU_00_T3,
    SOUGEN_DOUKUTU_00_T4,
    SOUGEN_DOUKUTU_00_SW0,
    SOUGEN_DOUKUTU_00_SW1,
    SOUGEN_DOUKUTU_00_SW2,
    SOUGEN_DOUKUTU_00_SW3,
    SOUGEN_DOUKUTU_07_T0,
    SOUGEN_DOUKUTU_0B_T0,
    SOUGEN_DOUKUTU_0C_T0,
    SOUGEN_DOUKUTU_0C_BW00,
    SOUGEN_DOUKUTU_0D_00,
    SOUGEN_DOUKUTU_0D_T0,
    SOUGEN_DOUKUTU_0E_BW00,
    SOUGEN_DOUKUTU_0F_T00,
    SOUGEN_DOUKUTU_10_R00,
    SOUGEN_DOUKUTU_10_R01,
    SOUGEN_DOUKUTU_10_R02,
    SOUGEN_DOUKUTU_10_R03,
    SOUGEN_DOUKUTU_10_R04,
    SOUGEN_DOUKUTU_10_R05,
    SOUGEN_DOUKUTU_10_R06,
    SOUGEN_DOUKUTU_10_R07,
    SOUGEN_DOUKUTU_10_R08,
    SOUGEN_DOUKUTU_10_R09,
    SOUGEN_DOUKUTU_10_R0A,
    SOUGEN_DOUKUTU_10_R0B,
    SOUGEN_DOUKUTU_10_R0C,
    SOUGEN_DOUKUTU_10_R0D,
    SOUGEN_DOUKUTU_10_R0E,
    SOUGEN_DOUKUTU_11_R00,
    SOUGEN_DOUKUTU_11_R01,
    SOUGEN_DOUKUTU_11_R02,
    SOUGEN_DOUKUTU_11_R03,
    SOUGEN_DOUKUTU_11_R04,
    SOUGEN_DOUKUTU_11_R05,
    SOUGEN_DOUKUTU_11_R06,
    SOUGEN_DOUKUTU_11_R07,
    SOUGEN_DOUKUTU_11_R08,
    SOUGEN_DOUKUTU_11_R09,
    SOUGEN_DOUKUTU_11_R0A,
    SOUGEN_DOUKUTU_11_R0B,
    SOUGEN_DOUKUTU_11_R0C,
    SOUGEN_DOUKUTU_11_R0D,
    SOUGEN_DOUKUTU_11_R0E,
    SOUGEN_DOUKUTU_13_T0,
    HIKYOU_DOUKUTU0_00_T0,
    HIKYOU_DOUKUTU0_01_T0,
    HIKYOU_DOUKUTU0_01_T1,
    HIKYOU_DOUKUTU0_02_KAIGARA,
    HIKYOU_DOUKUTU0_04_H00,
    HIKYOU_DOUKUTU1_00_00,
    HIKYOU_DOUKUTU1_00_T0,
    YAMADOUKUTU_01_00,
    YAMADOUKUTU_02_00,
    YAMADOUKUTU_03_T0,
    YAMADOUKUTU_06_H0,
    YAMADOUKUTU_07_T0,
    YAMADOUKUTU_08_h0,
    YAMADOUKUTU_08_h1,
    YAMADOUKUTU_08_h2,
    YAMADOUKUTU_09_r0,
    YAMADOUKUTU_09_r1,
    YAMADOUKUTU_09_r2,
    YAMADOUKUTU_0F_00,
    YAMADOUKUTU_10_00,
    SUIGEN_DOUKUTU_00_T0,
    SUIGEN_DOUKUTU_01_BW00,
    SUIGEN_DOUKUTU_02_T0,
    SUIGEN_DOUKUTU_04_BW00,
    SUIGEN_DOUKUTU_05_T0,
    SUIGEN_DOUKUTU_08_R0,
    SUIGEN_DOUKUTU_08_R1,
    SUIGEN_DOUKUTU_08_R2,
    SUIGEN_DOUKUTU_08_R3,
    SUIGEN_DOUKUTU_08_R4,
    SUIGEN_DOUKUTU_08_R5,
    SUIGEN_DOUKUTU_08_R6,
    SUIGEN_DOUKUTU_08_R7,
    SUIGEN_DOUKUTU_08_R8,
    SUIGEN_DOUKUTU_08_R9,
    SUIGEN_DOUKUTU_08_R10,
    SUIGEN_DOUKUTU_08_R11,
    SUIGEN_DOUKUTU_08_R12,
    SUIGEN_DOUKUTU_08_R13,
    SUIGEN_DOUKUTU_08_R14,
    SUIGEN_DOUKUTU_09_H00,
    HAKA_DOUKUTU_00_H0,
    HAKA_DOUKUTU_01_T0,
    HAKA_DOUKUTU_01_GEENE,
    KOBITO_DOUKUTU_00_T0,
    KOBITO_DOUKUTU_02_T0,
    KOBITO_DOUKUTU_05_T0,
    KOBITO_SHIRO_DOUKUTU_00_H0,
    KOBITO_SHIRO_DOUKUTU_00_T0,
    KOBITO_SHIRO_DOUKUTU_01_T0,
    KOBITO_URA_DOUKUTU_00_T0,
    KOBITO_URA_DOUKUTU_01_T0,
    GORON_DOUKUTU_APPEAR,
    KOBITO_DOUKUTU_03_T0,
    HIKYOU_DOUKUTU0_01_AKINDO,
    SOUGEN_DOUKUTU_14_AKINDO,
    SOUGEN_DOUKUTU_17_AKINDO,
    YAMADOUKUTU_04_AKINDO,
    YAMADOUKUTU_0D_AKINDO,
    YAMADOUKUTU_0F_AKINDO,
    YAMADOUKUTU_0E_SENNIN,
    KOBITO_DOUKUTU_04_T0,
    KOBITO_DOUKUTU_07_T0,
    KOBITO_DOUKUTU_09_T0,
    KOBITO_DOUKUTU_09_T1,
    KOBITO_DOUKUTU_09_T2,
    GORON_DOUKUTU_01_T0,
    GORON_DOUKUTU_01_T1,
    GORON_DOUKUTU_01_T2,
    GORON_DOUKUTU_01_T3,
    KOBITO_DOUKUTU_09_H0,
    SOUGEN_DOUKUTU_15_H0,
    KOBITO_DOUKUTU_01_H00,
    YAMADOUKUTU_05_H00,
    KOBITO_DOUKUTU_03_H00,
    DOUKUTU_04_H00,
    DOUKUTU_00_H00,
    KOBITO_DOUKUTU_04_H00,
    DOUKUTU_06_H00,
    DOUKUTU_05_H00,
    KOBITO_DOUKUTU_02_H00,
    KOBITO_DOUKUTU_01_T0,
    YAMADOUKUTU_04_CAP_0,
#if !defined(EU) && !defined(JP) && !defined(DEMO_JP)
    KS_B06,
    KS_B15,
    KS_B01,
    KS_B12,
    KS_C12,
    KS_C37,
#endif
    END_4,
} LocalFlags4;

typedef enum {
    BEGIN_5,
    LV1_00_WALK,
    LV1_01_WALK,
    LV1_02_WALK,
    LV1_03_WALK,
    LV1_04_WALK,
    LV1_05_WALK,
    LV1_06_WALK,
    LV1_07_WALK,
    LV1_08_WALK,
    LV1_09_WALK,
    LV1_0A_WALK,
    LV1_0B_WALK,
    LV1_10_WALK,
    LV1_11_WALK,
    LV1_12_WALK,
    LV1_13_WALK,
    LV1_14_WALK,
    LV1_15_WALK,
    LV1_16_WALK,
    LV1_17_WALK,
    LV1_TARU_0,
    LV1_TARU_1,
    LV1_00_00,
    LV1_00_01,
    LV1_00_02,
    LV1_00_03,
    LV1_00_T0,
    LV1_01_00,
    LV1_01_01,
    LV1_01_02,
    LV1_01_03,
    LV1_01_04,
    LV1_01_T0,
    LV1_01_T1,
    LV1_01_T2,
    LV1_02_T0,
    LV1_03_CAP_0,
    LV1_04_02,
    LV1_04_T0,
    LV1_05_T0,
    LV1_05_T1,
    LV1_06_03,
    LV1_06_T0,
    LV1_06_CAP_0,
    LV1_07_00,
    LV1_07_CAP_0,
    LV1_08_00,
    LV1_08_KEY,
    LV1_09_00,
    LV1_0A_00,
    LV1_0A_CAP_0,
    LV1_0B_01,
    LV1_0B_02,
    LV1_0B_15,
    LV1_0B_CAP_0,
    LV1_10_00,
    LV1_10_01,
    LV1_10_02,
    LV1_10_03,
    LV1_10_KEY,
    LV1_10_T0,
    LV1_11_01,
    LV1_11_T0,
    LV1_12_15,
    LV1_12_T0,
    LV1_12_T1,
    LV1_12_00,
    LV1_12_01,
    LV1_14_00,
    LV1_14_CAP_0,
    LV1_16_UTSUWA,
    LV1_16_1STEND,
    LV1_17_00,
    LV1_17_T0,
    LV1_02_00,
    LV1_02_01,
    LV1_10_04,
    LV1_20_CAP_0,
    LV1_01_HK,
    LV1_04_CAP_0,
    LV1_03_00,
    LV1_05_HK,
    LV1_08_01,
    LV1_01_05,
    LV1_10_CAP_0,
#if !defined(EU) && !defined(JP)
    LV1_12_CAP_0,
#endif
    END_5,
} LocalFlags5;

typedef enum {
    BEGIN_6,
    LV2_00_WALK,
    LV2_01_WALK,
    LV2_02_WALK,
    LV2_03_WALK,
    LV2_04_WALK,
    LV2_05_WALK,
    LV2_06_WALK,
    LV2_07_WALK,
    LV2_08_WALK,
    LV2_09_WALK,
    LV2_10_WALK,
    LV2_11_WALK,
    LV2_12_WALK,
    LV2_13_WALK,
    LV2_14_WALK,
    LV2_15_WALK,
    LV2_16_WALK,
    LV2_17_WALK,
    LV2_BOSS_00_WALK,
    LV2_00_00,
    LV2_00_01,
    LV2_01_01,
    LV2_01_02,
    LV2_01_T0,
    LV2_01_T1,
    LV2_02_01,
    LV2_03_CAP_0,
    LV2_04_00,
    LV2_04_01,
    LV2_04_CAP_0,
    LV2_06_00,
    LV2_06_T0,
    LV2_06_CAP_0,
    LV2_07_00,
    LV2_07_CAP_0,
    LV2_08_00,
    LV2_08_01,
    LV2_08_T0,
    LV2_08_T1,
    LV2_09_00,
    LV2_09_T0,
    LV2_09_T1,
    LV2_10_00,
    LV2_10_T0,
    LV2_10_T1,
    LV2_11_00,
    LV2_11_01,
    LV2_14_T0,
    LV2_15_01,
    LV2_15_T0,
    LV2_15_CAP_0,
    LV2_16_00,
    LV2_17_00,
    LV2_17_15,
    LV2_17_T0,
    LV2_17_T1,
    LV2_17_T2,
    LV2_20_UTSUWA,
    LV2_00_02,
    LV2_06_HK,
    LV2_11_02,
    LV2_05_R1,
    LV2_05_R2,
    LV2_05_R3,
    LV2_05_R4,
    LV2_05_R5,
    LV2_00_CAP_0,
    LV2_09_CAP_0,
    END_6,
} LocalFlags6;

typedef enum {
    BEGIN_7,
    LV3_00_WALK,
    LV3_01_WALK,
    LV3_02_WALK,
    LV3_03_WALK,
    LV3_04_WALK,
    LV3_05_WALK,
    LV3_06_WALK,
    LV3_10_WALK,
    LV3_11_WALK,
    LV3_12_WALK,
    LV3_13_WALK,
    LV3_14_WALK,
    LV3_15_WALK,
    LV3_16_WALK,
    LV3_17_WALK,
    LV3_18_WALK,
    LV3_19_WALK,
    LV3_1A_WALK,
    LV3_1B_WALK,
    LV3_1C_WALK,
    LV3_1D_WALK,
    LV3_20_WALK,
    LV3_21_WALK,
    LV3_22_WALK,
    LV3_23_WALK,
    LV3_24_WALK,
    LV3_00_00,
    LV3_00_T0,
    LV3_02_00,
    LV3_02_01,
    LV3_02_02,
    LV3_02_KEYFALL,
    LV3_03_00,
    LV3_03_01,
    LV3_04_00,
    LV3_04_KEYFALL,
    LV3_04_WARP_0,
    LV3_04_BOSSDOOR,
    LV3_10_00,
    LV3_11_00,
    LV3_12_CAP_0,
    LV3_13_00,
    LV3_14_00,
    LV3_14_01,
    LV3_14_02,
    LV3_14_KEY,
    LV3_15_00,
    LV3_17_00,
    LV3_16_BOSSDIE,
    LV3_16_GETUTSUWA,
    LV3_18_00,
    LV3_18_00_BW00,
    LV3_19_01,
    LV3_19_02,
    LV3_19_03,
    LV3_19_04,
    LV3_19_T0,
    LV3_1B_T0,
    LV3_1D_00,
    LV3_1D_01,
    LV3_1D_T0,
    LV3_1D_T1,
    LV3_20_00,
    LV3_20_CAP_0,
    LV3_22_00,
    LV3_23_01,
    LV3_23_T0,
    LV3_24_T0,
    LV3_OCARINA_FALL,
    LV3_02_CAP_0,
    LV3_24_HK,
    LV3_10_01,
    LV3_17_01,
    END_7,
} LocalFlags7;

typedef enum {
    BEGIN_8,
    LV4_00_WALK,
    LV4_01_WALK,
    LV4_02_WALK,
    LV4_03_WALK,
    LV4_04_WALK,
    LV4_05_WALK,
    LV4_06_WALK,
    LV4_07_WALK,
    LV4_08_WALK,
    LV4_09_WALK,
    LV4_0A_WALK,
    LV4_0B_WALK,
    LV4_0C_WALK,
    LV4_0D_WALK,
    LV4_0E_WALK,
    LV4_0F_WALK,
    LV4_10_WALK,
    LV4_11_WALK,
    LV4_20_WALK,
    LV4_21_WALK,
    LV4_22_WALK,
    LV4_23_WALK,
    LV4_24_WALK,
    LV4_25_WALK,
    LV4_26_WALK,
    LV4_27_WALK,
    LV4_28_WALK,
    LV4_29_WALK,
    LV4_2A_WALK,
    LV4_2B_WALK,
    LV4_2C_WALK,
    LV4_2D_WALK,
    LV4_2E_WALK,
    LV4_2F_WALK,
    LV4_30_WALK,
    LV4_31_WALK,
    LV4_32_WALK,
    LV4_33_WALK,
    LV4_34_WALK,
    LV4_35_WALK,
    LV4_INIT,
    LV4_01_00,
    LV4_03_CAP_0,
    LV4_03_BOSSDOOR,
    LV4_05_00,
    LV4_05_01,
    LV4_06_00,
    LV4_07_00,
    LV4_08_00,
    LV4_08_01,
    LV4_08_02,
    LV4_08_RAY_HALF,
    LV4_08_RAY_HALF_E,
    LV4_08_RAY_FULL,
    LV4_08_RAY_FULL_E,
    LV4_09_T0,
    LV4_0a_TSUBO,
    LV4_0a_T0,
    LV4_0c_00,
    LV4_0d_00,
    LV4_0d_01,
    LV4_0d_02,
    LV4_0d_T0,
    LV4_0e_UTSUWA,
    LV4_0f_00,
    LV4_0f_01,
    LV4_0f_02,
    LV4_0f_03,
    LV4_0f_04,
    LV4_10_RAY,
    LV4_10_T0,
    LV4_10_BOSSDIE,
    LV4_11_00,
    LV4_11_RAY_SP,
    LV4_11_RAY,
    LV4_11_T0,
    LV4_20_00,
    LV4_20_RAY,
    LV4_20_BOSSKEY,
    LV4_21_00,
    LV4_21_RAY,
    LV4_21_KEY,
    LV4_21_CAP_0,
    LV4_22_00,
    LV4_23_00,
    LV4_24_00,
    LV4_27_00,
    LV4_28_00,
    LV4_28_01,
    LV4_28_T0,
    LV4_28_T1,
    LV4_29_CAP_0,
    LV4_2b_T0,
    LV4_2b_T1,
    LV4_2b_T2,
    LV4_2b_BKABE,
    LV4_2b_00,
    LV4_2b_01,
    LV4_2b_02,
    LV4_2b_03,
    LV4_2b_04,
    LV4_2c_00,
    LV4_2c_02,
    LV4_2c_T0,
    LV4_2d_00,
    LV4_2d_01,
    LV4_2d_02,
    LV4_2e_RAY,
    LV4_2f_00,
    LV4_2f_01,
    LV4_2f_KEY,
    LV4_30_00,
    LV4_30_BKABE,
    LV4_31_00,
    LV4_31_01,
    LV4_32_00,
    LV4_32_01,
    LV4_32_T0,
    LV4_32_T1,
    LV4_33_01,
    LV4_34_00,
    LV4_34_01,
    LV4_35_00,
    LV4_35_01,
    LV4_22_01,
    LV4_2d_T0,
    LV4_03_CAP_1,
    LV4_08_CAP_0,
    LV4_08_CAP_1,
    LV4_36_WALK,
    LV4_36_T0,
    LV4_21_CAP_1,
    LV4_0d_03,
    LV4_0d_04,
    LV4_0d_05,
    LV4_0d_06,
    LV4_0d_07,
    LV4_25_00,
    LV4_25_01,
    LV4_25_02,
    LV4_25_03,
    LV4_25_04,
    LV4_31_02,
    LV4_31_03,
    LV4_31_04,
    LV4_31_05,
    LV4_31_06,
    LV4_31_07,
    LV4_06_01,
    LV4_06_02,
    LV4_06_03,
    LV4_06_04,
    LV4_06_05,
    LV4_06_06,
    LV4_08_OCT,
    LV4_05_02,
    LV4_28_02,
    LV4_2c_01,
    LV4_33_02,
    LV4_31_08,
    LV4_34_02,
    LV4_20_RAY_SW,
    LV4_21_RAY_SW,
    END_8,
} LocalFlags8;

typedef enum {
    BEGIN_9,
    LV5_00_WALK,
    LV5_01_WALK,
    LV5_02_WALK,
    LV5_03_WALK,
    LV5_04_WALK,
    LV5_05_WALK,
    LV5_06_WALK,
    LV5_07_WALK,
    LV5_08_WALK,
    LV5_09_WALK,
    LV5_0A_WALK,
    LV5_0B_WALK,
    LV5_0C_WALK,
    LV5_0D_WALK,
    LV5_0E_WALK,
    LV5_0F_WALK,
    LV5_10_WALK,
    LV5_11_WALK,
    LV5_12_WALK,
    LV5_13_WALK,
    LV5_14_WALK,
    LV5_15_WALK,
    LV5_16_WALK,
    LV5_17_WALK,
    LV5_18_WALK,
    LV5_19_WALK,
    LV5_1A_WALK,
    LV5_1B_WALK,
    LV5_1C_WALK,
    LV5_1D_WALK,
    LV5_1E_WALK,
    LV5_1F_WALK,
    LV5_20_WALK,
    LV5_21_WALK,
    LV5_22_WALK,
    LV5_23_WALK,
    LV5_24_WALK,
    LV5_25_WALK,
    LV5_26_WALK,
    LV5_27_WALK,
    LV5_28_WALK,
    LV5_29_WALK,
    LV5_2A_WALK,
    LV5_2B_WALK,
    LV5_2C_WALK,
    LV5_2D_WALK,
    LV5_2E_WALK,
    LV5_2F_WALK,
    LV5_30_WALK,
    LV5_31_WALK,
    LV5_32_WALK,
    LV5_01_T0,
    LV5_03_T0,
    LV5_03_BOSSDOOR,
    LV5_04_T0,
    LV5_05_00,
    LV5_05_01,
    LV5_05_02,
    LV5_06_00,
    LV5_07_00,
    LV5_07_01,
    LV5_07_T0,
    LV5_08_00,
    LV5_08_01,
    LV5_08_KEY,
    LV5_08_BOSSDOOR,
    LV5_0b_B0,
    LV5_0b_B1,
    LV5_0d_00,
    LV5_0e_00,
    LV5_0f_T0,
    LV5_0f_T1,
    LV5_10_T0,
    LV5_15_00,
    LV5_15_01,
    LV5_15_02,
    LV5_15_03,
    LV5_15_04,
    LV5_15_T0,
    LV5_15_B0,
    LV5_15_B1,
    LV5_1a_00,
    LV5_1a_01,
    LV5_1b_00,
    LV5_1b_T0,
    LV5_1c_00,
    LV5_1c_T0,
    LV5_20_00,
    LV5_20_01,
    LV5_21_00,
    LV5_21_01,
    LV5_21_02,
    LV5_21_03,
    LV5_21_04,
    LV5_21_05,
    LV5_21_06,
    LV5_21_07,
    LV5_21_08,
    LV5_21_09,
    LV5_21_0a,
    LV5_21_CAP_0,
    LV5_22_00,
    LV5_22_01,
    LV5_22_CAP_0,
    LV5_23_00,
    LV5_23_01,
    LV5_27_00,
    LV5_29_00,
    LV5_29_01,
    LV5_29_T0,
    LV5_2b_T0,
    LV5_2c_00,
    LV5_2c_01,
    LV5_2c_02,
    LV5_2c_03,
    LV5_2c_T0,
    LV5_2c_CAP_0,
    LV5_2d_T0,
    LV5_31_CAP_0,
    LV5_32_CAP_0,
    LV5_32_T0,
    LV5_32_T1,
    LV5_BOSSDIE,
    LV5_MBOSSDIE,
    LV5_00_UTSUWA,
    LV5_0c_00,
    LV5_0A_CAP_0,
    LV5_0f_HK,
    LV5_05_03,
    LV5_08_02,
    LV5_0c_01,
    LV5_0c_02,
    LV5_22_02,
    LV5_15_05,
    LV5_20_02,
    END_9,
} LocalFlags9;

typedef enum {
    BEGIN_10,
    LV6_00_WALK,
    LV6_01_WALK,
    LV6_02_WALK,
    LV6_03_WALK,
    LV6_04_WALK,
    LV6_05_WALK,
    LV6_06_WALK,
    LV6_07_WALK,
    LV6_08_WALK,
    LV6_09_WALK,
    LV6_0A_WALK,
    LV6_0B_WALK,
    LV6_0C_WALK,
    LV6_0D_WALK,
    LV6_0E_WALK,
    LV6_0F_WALK,
    LV6_10_WALK,
    LV6_11_WALK,
    LV6_12_WALK,
    LV6_13_WALK,
    LV6_14_WALK,
    LV6_15_WALK,
    LV6_16_WALK,
    LV6_17_WALK,
    LV6_18_WALK,
    LV6_19_WALK,
    LV6_1A_WALK,
    LV6_1B_WALK,
    LV6_1C_WALK,
    LV6_1D_WALK,
    LV6_1E_WALK,
    LV6_1F_WALK,
    LV6_20_WALK,
    LV6_21_WALK,
    LV6_22_WALK,
    LV6_23_WALK,
    LV6_24_WALK,
    LV6_25_WALK,
    LV6_26_WALK,
    LV6_27_WALK,
    LV6_28_WALK,
    LV6_29_WALK,
    LV6_2A_WALK,
    LV6_2B_WALK,
    LV6_2C_WALK,
    LV6_2D_WALK,
    LV6_2E_WALK,
    LV6_2F_WALK,
    LV6_30_WALK,
    LV6_31_WALK,
    LV6_32_WALK,
    LV6_33_WALK,
    LV6_34_WALK,
    LV6_35_WALK,
    LV6_36_WALK,
    LV6_37_WALK,
    LV6_38_WALK,
    LV6_39_WALK,
    LV6_3A_WALK,
    LV6_3B_WALK,
    LV6_00_00,
    LV6_01_T0,
    LV6_02_T0,
    LV6_03_T0,
    LV6_04_T0,
    LV6_07_00,
    LV6_09_T0,
    LV6_09_KB0,
    LV6_09_KB1,
    LV6_09_KB2,
    LV6_09_KB3,
    LV6_0a_01,
    LV6_0b_00,
    LV6_0c_00,
    LV6_0c_01,
    LV6_0e_00,
    LV6_10_00,
    LV6_11_00,
    LV6_11_01,
    LV6_11_B0,
    LV6_11_B1,
    LV6_11_B2,
    LV6_13_00,
    LV6_14_00,
    LV6_14_BOSSDOOR,
    LV6_15_00,
    LV6_16_00,
    LV6_17_00,
    LV6_17_01,
    LV6_18_00,
    LV6_1a_00,
    LV6_1c_CAP_0,
    LV6_1d_00,
    LV6_1f_00,
    LV6_20_T0,
    LV6_24_00,
    LV6_26_00,
    LV6_26_01,
    LV6_26_CAP_0,
    LV6_27_00,
    LV6_27_T0,
    LV6_30_00,
    LV6_32_00,
    LV6_34_00,
    LV6_34_01,
    LV6_35_00,
    LV6_37_T0,
    LV6_39_00,
    LV6_39_01,
    LV6_39_02,
    LV6_1f_CHAIR_L,
    LV6_1f_CHAIR_R,
    LV6_1d_KEYGET,
    LV6_1b_TAREMAKU,
    LV6SOTO_01_KAIJO,
    LV6_SEKIKA_END,
    LV6_GUFUU1_FIGURE,
    LV6_GUFUU2_FIGURE,
    LV6_GUFUU1_GISHIKI,
    LV6_GUFUU1_DEMO,
    LV6_ZELDA_DISCURSE,
    LV6_00_ESCAPE,
    LV6_GUFUU2_DEAD,
    LV6_KANE_START,
    LV6_KANE_1ST,
    LV6_KANE_2ND,
    LV6_SOTO_ENDING,
    LV6_08_00,
    LV6_39_03,
    LV6_SOTO_06_00,
    LV6_SOTO_06_01,
    LV6_0A_CAP_0,
    LV6SOTO_01_CAP_0,
    LV6_0a_00,
    LV6_0b_01,
    LV6_0e_01,
    LV6_10_01,
    LV6_13_01,
    LV6_14_01,
    LV6_15_01,
    LV6_1a_01,
    LV6_1f_01,
    LV6_39_04,
    LV6_17_02,
    LV6_18_01,
    LV6_08_01,
    LV6_SOTO_01_00,
    LV6_SOTO_01_01,
    LV6_SOTO_01_02,
    LV6_39_KING,
    END_10,
} LocalFlags10;

typedef enum {
    BEGIN_11,
    END_11,
} LocalFlags11;

typedef enum {
    BEGIN_12,
    END_12,
} LocalFlags12;

#endif
