#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef CDS_FULLSCREEN
#define CDS_FULLSCREEN 4
#endif

#define _DEFINITIONS_H_

#define EIS1

/*
 * PFD Airbus A330
 *  define PFD from AIRBUS or LTU FCOM
 */
#define FCOM_LTU
//#define FCOM_AIRBUS

typedef struct
{
    int RED;
    int GREEN;
    int BLUE;
} RGB_COLOR;

typedef struct
{
    int YELLOW;
    int MAGENTA;
    int CYAN;
    int BLACK;
} YMCK_COLOR;

typedef enum
{
    AMBER,
    BLACK,
    BLUE,
    BROWN,
    CYAN,
    GRAY,
    GREEN,
    MAGENTA,
    RED,
    YELLOW,
    WHITE
} RGB_COLOR_LIST;

typedef enum {
    ALTERNATE_LAW,
    DIRECT_LAW,
    NORMAL_LAW
} FLIGHT_Law;

typedef enum {
    SSM_NO,         // Normal Operation
    SSM_NCD,        // No Computed Data
    SSM_FT,         // Functional Test
    SSM_FW          // Failure Warning
} SSM;

typedef enum {
    ALT_NORMAL,         // Normal (yellow frame, green digits)
    ALT_DEVIATION,      // Pulsing (yellow frame, green digits)
    ALT_EXCESSIVE_DEV,  // Flashing (amber frame, green digits)
    ALT_BELOW_MDA       // Flashing (amber frame, amber digits)
} ALT_Mode;

typedef enum {
    TRK_FPA_MODE,       // Flight Path Vector & Flight Path Director
    HDG_VS_MODE,        // FD Crossed Bars
    ROLL_OUT_MODE,      // Yaw Bar
    GROUND_MODE,        // Side Stick Deflection
    GROUND_ROLL_MODE,   // Side Stick Deflection + Yaw Bar
    FD_OFF
} FD_Mode;

typedef enum {
    OM,             // Outer Marker
    MM,             // Middle Marker
    IM,             // Inner Marker
    MARKER_OFF      // Out of range / nothing displayed
} MARKER_INDICATION;

typedef enum {
    FLS_APPR,       // FMS
    GPS_APPR,       // GPS
    ILS_APPR,       // ILS
    MMS_APPR,       // Microwave Landing System
    RNAV_APPR,      // Area Navigation
    VFR_APPR        // Visual
} APPROACH_MODE;

typedef enum {
    FOUR_LINES,     // 4 lines with equal lenght
    AB3_MERGE,      // Line 3 of Column A and B merged
    ABC3_MERGE,     // Line 3 of Columns A, B and C merged
    BC3_MERGE,      // Line 3 of Column B and C merged
    THREE_LINES     // No separation line between Column B and C (merged vertical and lateral mode)
} FMA_Lines;

typedef enum {
    LEFT,
    CENTER,
    RIGHT
} SIDE;

typedef enum {
    QNH,
    QFE,
    STD
} BARO_REF;

/*
 * Barometric Reference Unit
 */
typedef enum {
    HPA,                // hPa or mbar (hecto Pascals or milibars)
    INCH_HG             // inch Hg
} BARO_Units;

/*
 * FMA - Column A Line 1 (+2)
 * Auto Thrust System
 * Current Thrust Mode
 */
typedef enum {
    MAN_TOGA,           // Take Off/Go Around
    MAN_FLX,            // Flexible
    MAN_MCT,            // Maximum Continuous
    MAN_THR,            // Manual Thrust
    THR_CLB,            // Climb
    THR_MCT,            // Maximum Continuous
    THR_DES,            // Descend
    THR_IDLE,           // Idle
    A_FLOOR,            // Alpha Floor
    TOGA_LK,            // Take Off/Go Around Locked
    SPEED,              // Constant Speed
    MACH,               // Constant Mach
    THR_LVR,            //
    OFF_A1
} FMA_THRUST_LINE1;

/*
 * FMA - Column A Line 3
 * Auto Thrust System
 */
typedef enum {
    LVR_MCT,            // Move throttle to MCT
    LVR_CLB,            // Move throttle to CLB
    LVR_ASYM,           // Asymmetric Thrust
    THR_LK,
    SPEED_SEL,          // FM: calculated Speed
    MACH_SEL,           // FM: calculated Mach
    OFF_A3
} FMA_THRUST_LINE3;

/*
 * FMA - Column AB Line 1
 * Auto Flight System
 * Combined Mode (Lateral & Vertical)
 */
typedef enum {
    FLARE,
    ROLL_OUT,
    LAND,
    FINAL_APP,
    OFF_BC1
} FMA_LV_COMBINED_LINE1;

/*
 * FMA - Column B Line 1
 * Auto Flight System
 * Engaged Vertical Mode
 */
typedef enum {
    SRS,
    ALT_CRZ_STAR,
    ALT_CRZ,
    ALT_STAR,
    ALT,
    ALT_CST_STAR,
    ALT_CST,
    VS,
    FPA,
    GS_STAR,
    GS,
    CLB,
    DES,
    OP_CLB,
    OP_DES,
    FINAL_APP_VERT,
    OFF_B1
} FMA_VERTICAL_LINE1;

/*
 * FMA - Column B Line 2
 * Auto Flight System
 * Armed Vertical Mode
 */
typedef enum {
    ALT_MANAGED,
    ALT_SELECTED,
    ALT_CRZ_ARMED,
    CLB_ARMED,
    OP_CLB_ARMED,
    DES_ARMED,
    GS_ARMED,
    FINAL,
    OFF_B2
} FMA_VERTICAL_LINE2;

/*
 * FMA - Column C Line 1
 * Auto Flight System
 * Engaged Lateral Mode
 */
typedef enum {
    RWY,
    HDG,
    TRACK,
    LOC_STAR,
    LOC,
    NAV,
    APP_NAV,
    RWY_TRK,
    GA_TRK,
    LOC_BC_STAR,
    LOC_BC,
    OFF_C1
} FMA_LATERAL_LINE1;

/*
 * FMA - Column C Line 2
 * Auto Flight System
 * Armed Lateral Mode
 */
typedef enum {
    NAV_ARMED,
    APP_NAV_ARMED,
    LOC_ARMED,
    LOC_BC_ARMED,
    OFF_C2
} FMA_LATERAL_LINE2;

/*
 * FMA - Column BC Line 3
 * System Messages and Warnings
 */
typedef enum {
    MAN_PITCH_TRIM_ONLY,
    USE_MAN_PITCH_TRIM,
    CHECK_APPR_SELECTION,
    SET_MANAGED_SPEED,
    SET_GREEN_DOT_SPEED,
    SET_HOLD_SPEED,
    VERT_DISCONT_AHEAD,
    DECELERATE,
    MORE_DRAG,
    EFIS_SINGLE_SOURCE_1,
    EFIS_SINGLE_SOURCE_2,
    EFIS_SWTG_NOT_ALLOWED,
    EXTEND_SPD_BRK,
    RETRACT_SPD_BRK,
    OFF_BC3
} FMA_MESSAGES;

/*
 * FMA - Column D Line 1
 * Landing Capabilities
 */
typedef enum {
    CAT1,
    CAT2,
    CAT3,
    OFF_D1
} FMA_LANDING_LINE1;

/*
 * FMA - Column D Line 2
 * Landing Capabilities
 */
typedef enum {
    SINGLE,
    DUAL,
    OFF_D2
} FMA_LANDING_LINE2;

/*
 * FMA - Column D Line 3
 * Landing Capabilities
 */
typedef enum {
    DH,         // DH ###
    NO_DH,      // NO DH ("NO" inserted in MCDU / DH = 0)
    MDA,        // MDA ###
    MDH,        // MDH ###
    OFF_D3      // Nothing displayed
} FMA_LANDING_LINE3;

/*
 * FMA - Column E Line 1
 * Auto Flight System
 * Auto Pilot Status
 */
typedef enum {
    AP_12,      // AP 1 + 2 engaged (during landing only)
    AP_1,       // AP 1 engaged
    AP_2,       // AP 2 engaged
    OFF_E1      // AP OFF, nothing displayed
} FMA_AFS_LINE1;

/*
 * FMA - Column E Line 2
 * Auto Flight System
 * Flight Director Status
 */
typedef enum {
    FD00,
    FD01,
    FD02,
    FD10,
    FD11,
    FD12,
    FD20,
    FD22,
    OFF_E2
} FMA_AFS_LINE2;

/*
 * FMA - Column E Line 3
 * Auto Flight System
 * Auto Thrust Status
 */
typedef enum {
    ATHR_ENGAGED,
    ATHR_ARMED,
    OFF_E3
} FMA_AFS_LINE3;

/*
 * list is used to select the factoring scale (displacement of diplay lists)
 * or to decide where the bugs should be drawn
 */
typedef enum {
    ALT_TAPE,
    HDG_TAPE,
    SPD_TAPE
} TAPES;

/*
 * Flight Phases according to FAA
 */
//typedef enum {
//    STANDING = 0,
//    TAXI,
//    TAKE_OFF,
//    CLIMB,
//    CRUISE,
//    DESCENT,
//    APPROACH,
//    LANDING,
//    GO_AROUND // Missed Approach
//} FLIGHT_PHASE;

/* flight phases according to a340sz.for:
   1 : preflight
   2 : take off
   3 : climb
   4 : cruise
   5 : descent
   6 : approach
   7 : go around
   8 : done
 */
typedef enum {
    PREFLIGHT = 1,
    TAKE_OFF,
    CLIMB,
    CRUISE,
    DESCENT,
    APPROACH,
    GO_AROUND,
    DONE
} FLIGHT_PHASE;

typedef enum {
    AIRBUS_SQUARE = 0,
    AIRBUS_RECTANGULAR,
    OTHER_RECTANGULAR
} DISPLAY_FORMAT;

typedef enum {
    PFD_DISPLAY,
    OTHER_DISPLAY
} DISPLAY_TYPE;

#endif
