//------------------------------------------------------------------------------
//Filename      typedef structs1.h
//System        WinXP 32
//Author        Christian Berth
//Date          31,05,05
//Description   This Header displays the Main Communication Interface between the
//              Network connected Simulator Modules.
//              This Header contains the Com-typedef structs for UDP/TCP Communication.
//              The Data within this Header will be broadcasted or direct send
//              e.g. Broadcast: HOST-> SIM-NETWORK or ICM-> SIM-NETWORK
//------------------------------------------------------------------------------

/*
INFO:
Main Data Server:       HOST (Simulation Computer)
Tranceiving Clients:    ICM, MCM, OVERHEADPANNEL COMPUTER (OHPC), MCDU COMPUTER
Receiving only Clients: PFD1/2, ND1/2, SD, E-WD, VSM
*/

// Value within: "/* 400 */" after typedef struct Name = Command ID

/*
 * Author     : Angel Chiou
 * Date       : 10/05/2007
 * Description: This file is based on udp_data_typedef structs.h from the A330 Simulation
 *              (simconnect.c)
 * Changes    : - Added data for PFD (DMC1-3)
 *              - Orded typedef structs
 *              - Formatting Issues
 */


/* $ScmHeader: 9996Cv127C27w6v89Cz399999997%O677)&5|%O677)&8?%O677)&8?6 $*/
/* $Id: udp_data_typedef structs.h,v 76191818.4 2004/06/04 15:09:38 pettel(l322|ANY_DB) Exp $*/
#ifndef _structS1_H_
#define _structS1_H_
#pragma pack (1)
//#define AARES
typedef struct
{
    int         iPFD1_OnOff;
    int         iPFD2_OnOff;
    int         iND1_OnOff;
    int         iND2_OnOff;
    int         iEWD_OnOff;
    int         iSD_OnOff;
    int         iMCDU_OnOff;
    int         iOHP_OnOff;
} sFlightDisplayCtr;

typedef struct
{
    double         dSimTime;
    long           lSimCounter;
} sTimeData;

typedef struct
{
    double         dLatitude;       /* at center of gravity */
    double         dLongitude;      /* at center of gravity */
    float          fAltitude;       /* at center of gravity */
    float          fPitch;                        /*deg*/
    float          fBank;                         /*deg*/
    float          fHeading;                      /*deg*/
    float          fGroundElevation;
    float          fHeightAboveTerrain;
    float          fGroundSpeed;
    float          fVerticalSpeed;
    float          fCalibratedAirspeed;
    unsigned char  ucGroundFlag;    /* 1: True; 0: False */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAircraftPosition;

typedef struct
{
    float          fSlats;              /* AV. SLAT ANGLE  */
    float          fFlaps;              /* AV. FLAP ANGLE  */
    float          fGear;               /* AVG. GEAR EXT.  */
    float          fGSPos;              /* GEAR STATUS (=4 IF ALL DOWN, NO FAIL)*/
    float          fLMGPos;             /* LMG GEAR STATUS (=1 IF GEAR NOT UP)*/
    float          fRMGPos;             /* RMG GEAR STATUS (=1 IF GEAR NOT UP)*/
    float          fNGDPos;             /* NG  DOOR STATUS (=1 IF EXT ALONE)*/
    float          fLMGDPos;            /* LMG DOOR STATUS (=1 IF EXT ALONE)*/
    float          fRMGDPos;            /* RMG DOOR STATUS (=1 IF EXT ALONE)*/
    unsigned char  ucGearLeverUpFlag;   /* Ldg Gear lever  */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAircraftData;

typedef struct
{
    char          cStrobe;
    char          cReils;
    char          cTaxi;
    char          cEnvironmental;
    char          cVASI;
    char          cRunwayApproach;
    char          cRunwayEdge;
    char          cRunwaySurface;
    char          cRunwayMarking;
    char          cRunwayCenterline;
    char          cTouchDownZone;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sLights;

typedef struct
{
    double         dLatitude;       /* at center of gravity */
    double         dLongitude;      /* at center of gravity */
    float          fAltitude;       /* at center of gravity */
    float          fPitch;
    float          fBank;
    float          fHeading;
    float          fHeightAboveTerrain;
    float          fGroundSpeed;
    float          fVerticalSpeed;
    unsigned char  ucObjectID;
    unsigned char  ucGroundFlag;    /* 1: True; 0: False */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sObjectPosition;

typedef struct
{
    unsigned char  ucObjectID;
    char           szObjectName[120];
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAddObject;

typedef struct
{
    unsigned char  ucObjectID;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sDelObject;

typedef struct
{
    char          cDayNightMode;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sDayNight;

typedef struct
{
    char           cSeason;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSeason;

typedef struct  //10
{
    float           fVisibility;
    float           fRVR;
    float           afCloudCeilng[2];
    float           afCloudTop[2];
    float           fFogTop;
    char            cVisibilityConditions;  /* 0: CAVOK           */
                                            /* 1: CIRCLING        */
                                            /* 2: NON PREC        */
                                            /* 3: MIN T/O         */
                                            /* 4: CAT I           */
                                            /* 5: CAT II          */
                                            /* 6: CAT IIIA        */
                                            /* 7: CAT IIIB        */
                                            /* 8: CAT III NO DESI */
                                            /* 9: CAT III ZERO    */
    char            cRain;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sWeather;

typedef struct
{
    char           cCrashFlag;    /* 1: True; 0: False */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sVisualStatus;

typedef struct
{
    float          fXVelocityAirBodyAxis;
    float          fXAccelerationAirBodyAxis;
    float          fYVelocityAirBodyAxis;
    float          fYAccelerationAirBodyAxis;
    float          fZVelocityAirBodyAxis;
    float          fZAccelerationAirBodyAxis;
} sTranslatoryData;


typedef struct
{
    float            fRollRate;
    float            fRollAcceleration;
    float            fPitchRate;
    float            fPitchAcceleration;
    float            fYawRate;
    float            fYawAcceleration;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sRotatoryData;

typedef struct
{
    float            fAlpha;
    float            fBeta;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAerodynamicData;

typedef struct sEulerData  /* 23 */
{
    float            fPhiDeg;
    float            fThetaDeg;
    float            fPsiDeg;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEulerData;

typedef struct
{
    float            fLoadFactorNormal;         /* VNZL   */
    float            fLoadFactorLongitudinal;   /* VNXL   */
    float            fLoadFactorLateral;        /* VNYL   */
    float            fFlightPathAngle;          /* VGAMMA */
    float            fTrueTrack;                /* VTRACK */
    float            fMach;                     /* VM     */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sMiscData;

typedef struct
{
    float            fLoadFactorNormal;         /* VNZL     */
    float            fLoadFactorLongitudinal;   /* VNXL     */
    float            fLoadFactorLateral;        /* VNYL     */
    float            fFlightPathAngle;          /* VGAMMA   */
    float            fTrueTrack;                /* VTRACK   */
    float            fMach;                     /* VM       */
    float            fPhiDeg;                   /* VPHIDG   */
    float            fThetaDeg;                 /* VTHETADG */
    float            fPsiDeg;                   /* VPSIDG   */
    float            fAlpha;                    /* VALPHA   */
    float            fBeta;                     /* VBETA    */
    float            fRollRate;                 /* vp       */
    float            fRollAcceleration;         /* vpd      */
    float            fPitchRate;                /* vq       */
    float            fPitchAcceleration;        /* vqd      */
    float            fYawRate;                  /* vr       */
    float            fYawAcceleration;          /* vrd      */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sCASData;

typedef struct
{
    float            fLInboardAileronSurfacePosition;
    float            fLOutboardAileronSurfacePosition;
    float            fRInboardAileronSurfacePosition;
    float            fROutboardAileronSurfacePosition;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAileronData;

typedef struct
{
    float           fLElevatorSurfacePosition;
    float           fRElevatorSurfacePosition;
    float           fStabilizerSurfacePosition;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sElevatorData;

typedef struct
{
    float   fRudderTrim;
    float   fRudderSurfacePosition;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sRudderData;

typedef struct
{
    float   fLSpoiler1SurfacePosition;
    float   fLSpoiler2SurfacePosition;
    float   fLSpoiler3SurfacePosition;
    float   fLSpoiler4SurfacePosition;
    float   fLSpoiler5SurfacePosition;
    float   fLSpoiler6SurfacePosition;
    float   fRSpoiler1SurfacePosition;
    float   fRSpoiler2SurfacePosition;
    float   fRSpoiler3SurfacePosition;
    float   fRSpoiler4SurfacePosition;
    float   fRSpoiler5SurfacePosition;
    float   fRSpoiler6SurfacePosition;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSpoilerData;

typedef struct
{
    float fFlapCmd;
    float fAirbrakeCmd;
    float fThrustLever1Cmd;
    float fThrustLever2Cmd;
    int   iThrustRev1Cmd;
    int   iThrustRev2Cmd;
    float fStickPosX;
    float fStickPosY;
    float fThetaStCmd;
    float fGLoadStCmd;
    float fLBrakeCmd;
    float fRBrakeCmd;
    float fNWSCmd;
    float fRudderTrimCmd;
    float fRudderCmd;
    unsigned char  ucGearLeverUCmd;
    unsigned char  ucGearLeverDCmd;
    unsigned char  ucParkingBrakeCmd;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSControlData;

typedef struct
{
    float  fEng1FF;
    float  fEng2FF;
    float  fEng1N1;
    float  fEng2N1;
    float  fEng1N2;
    float  fEng2N2;
    float  fEng1EGT;
    float  fEng2EGT;
    float  fEng1EPR;
    float  fEng2EPR;
    float  fEng1EPRCmd;
    float  fEng2EPRCmd;
    float  fEng1N1P;
    float  fEng2N1P;
    float  fEng1N2P;
    float  fEng2N2P;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEngineData;

typedef struct
{
    float fThrustLever1Cmd;
    float fThrustLever2Cmd;
	unsigned char  ucEngMaster1;
    unsigned char  ucEngMaster2;
    unsigned char  ucEngStartSelCrank;
    unsigned char  ucEngStartSelNorm;
    unsigned char  ucEngStartSelIgn;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEngineControlData;

typedef struct
{
#ifdef AARES
    int iADFFreq1;
    int iADFFreq2;
    int iVORFreq1;
    int iVORFreq2;
    int iILSFreq1;
    int iILSFreq2;
    int iDMEFreq1;
    int iDMEFreq2;
    int iDMEFreq3;
    int iDMEFreq4;
    float fILSLOC1;
    float fILSLOC2;
    float fILSGS1;
    float fILSGS2;
    float fILSXLOC1;
    float fILSXLOC2;
    float fILSXGS1;
    float fILSXGS2;
    float fDMERNG1;
    float fDMERNG2;
    float fDMERNG3;
    float fDMERNG4;
    int iADFIDE1;
    int iADFIDE2;
    int iVORIDE1;
    int iVORIDE2;
    int iILSIDE1;
    int iILSIDE2;
    float fADFBRG1;
    float fADFBRG2;
    float fVORBRG1;
    float fVORBRG2;
    unsigned char  ucVORValid1;
    unsigned char  ucVORValid2;
    unsigned char  ucDMEValid1;
    unsigned char  ucDMEValid2;
    unsigned char  ucDMEValid3;
    unsigned char  ucDMEValid4;
    float fILSSignalS1;
    float fILSSignalS2;
    int iILSRWYHDG1;
    int iILSRWYHDG2;
    unsigned char  ucMiddleMarker;
    unsigned char  ucOuterMarker;
    float fVOR1CRS; /*JFA100BA*/
    float fVOR2CRS; /*JFB100AA*/
#else

    float fILSLOC1;
      float fILSLOC2;
      float fILSGS1;
      float fILSGS2;
      float fILSXLOC1;
      float fILSXLOC2;
      float fILSXGS1;
      float fILSXGS2;
      float fDMERNG1;
      float fDMERNG2;
      float fDMERNG3;
      float fDMERNG4;
      float fADFBRG1;
      float fADFBRG2;
      float fVORBRG1;
      float fVORBRG2;
      float fILSSignalS1;
      float fILSSignalS2;
      float fVOR1CRS;	/*JFA100BA*/
      float fVOR2CRS;	/*JFB100AA*/
      int iADFIDE1;
      int iADFIDE2;
      int iVORIDE1;
      int iVORIDE2;
      int iILSIDE1;
      int iILSIDE2;
      int iADFFreq1;
      int iADFFreq2;
      int iVORFreq1;
      int iVORFreq2;
      int iILSFreq1;
      int iILSFreq2;
      int iDMEFreq1;
      int iDMEFreq2;
      int iDMEFreq3;
      int iDMEFreq4;
      int iILSRWYHDG1;
      int iILSRWYHDG2;
      unsigned char  ucVORValid1;
      unsigned char  ucVORValid2;
      unsigned char  ucDMEValid1;
      unsigned char  ucDMEValid2;
      unsigned char  ucDMEValid3;
      unsigned char  ucDMEValid4;
      unsigned char  ucMiddleMarker;
      unsigned char  ucOuterMarker;
#endif

}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sComNavData;

typedef struct
{
    unsigned char  ucPFD_Capt_on;  /* CP     BI5WK1    ,*/
    unsigned char  ucPFD_FO_on;    /* CP     BI5WK2    ,*/
    unsigned char  ucEWD_on;       /* CP     BI6WK1    ,*/
    unsigned char  ucSD_on;        /* CP     BI6WK2    ,*/
    unsigned char  ucND_Capt_on;   /* CP     BI4WK1    ,*/
    unsigned char  ucND_FO_on;     /* CP     BI4WK2    ,*/
    unsigned char  ucMCDU1_on;     /* CP     BI7CA1    ,*/
    unsigned char  ucMCDU2_on;     /* CP     BI7CA2    ,*/
    unsigned char  ucMCDU3_on;     /* CP     BI7CA3    ,*/
    unsigned char  ucFCU_AB_on;    /* CP     BI8CA1    ,*/
    unsigned char  ucFCU_C_on;     /* CP     BI8CA2    ,*/
    unsigned char  ucRMP1_on;      /* CP     BI2RG1    ,*/
    unsigned char  ucRMP2_on;      /* CP     BI2RG2    ,*/
    unsigned char  ucRMP3_on;      /* CP     BI2RG3    ,*/
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sDisplayControlData;

typedef struct
{
#ifdef AARES
    unsigned char  ucSPDLIM_1;  /* CP     qjlspdlim[0]     ,*/
    unsigned char  ucSPDLIM_2;  /* CP     qjlspdlim[1]     ,*/
    unsigned char  ucVRDisp_1;  /* CP     qjlndvr[0]       ,*/
    unsigned char  ucVRDisp_2;  /* CP     qjlndvr[1]       ,*/
    unsigned char  ucAPSTAT  ;  /* CP     qesfxapeng[0]    ,*/
    unsigned char  ucFDSTAT  ;  /* CP     qesfxfd[0]       ,*/
    unsigned char  ucATSTAT  ;  /* CP     qesfxatmod[0]    ,*/
    unsigned char  ucCATNB   ;  /* CP     qes_cat_nb[0]    ,*/
    unsigned char  ucAPPCAB  ;  /* CP     qesfxsgldl[0]    ,*/
    unsigned char  ucHDGSCL_1;  /* CP     qelxhdgsc[0]     ,*/
    unsigned char  ucHDGSCL_2;  /* CP     qelxhdgsc[1]     ,*/
    unsigned char  ucATTACT_1;  /* CP     qelznaatt[0]     ,*/
    unsigned char  ucATTACT_2;  /* CP     qelznaatt[1]     ,*/
    unsigned char  ucDEVSYM_1;  /* CP     qelnadev[0]      ,*/
    unsigned char  ucDEVSYM_2;  /* CP     qelnadev[1]      ,*/
    unsigned char  ucSPDSCL_1;  /* CP     qelznaspd[0]     ,*/
    unsigned char  ucSPDSCL_2;  /* CP     qelznaspd[1]     ,*/
    unsigned char  ucALTSCL_1;  /* CP     qelznaalt[0]     ,*/
    unsigned char  ucALTSCL_2;  /* CP     qelznaalt[1]     ,*/
#endif
    float fVR_1;                /* CP     qjrsvr[0]        ,*/
    float fVR_2;                /* CP     qjrsvr[1]        ,*/
    float fVFEN_1;              /* CP     qjrsvnext[0]     ,*/
    float fVFEN_2;              /* CP     qjrsvnext[1]     ,*/
    float fV1_1;                /* CP     qjiav1[0]        ,*/
    float fV1_2;                /* CP     qjiav1[1]        ,*/
    float fV3FLAPS_1;           /* CP     qjrsvflaps[0]    ,*/
    float fV3FLAPS_2;           /* CP     qjrsvflaps[1]    ,*/
    float fV4SLATS_1;           /* CP     qjrndvslat[0]    ,*/
    float fV4SLATS_2;           /* CP     qjrndvslat[1]    ,*/
    float fVMAN_1;              /* CP     qjrsvman[0]      ,*/
    float fVMAN_2;              /* CP     qjrsvman[1]      ,*/
    float fVMAX_1;              /* CP     qjrbvmax[0]      ,*/
    float fVMAX_2;              /* CP     qjrbvmax[1]      ,*/
    float fVLS_1;               /* CP     qjrbvls[0]       ,*/
    float fVLS_2;               /* CP     qjrbvls[1]       ,*/
    float fVPROT_1;             /* CP     qjrbvaprot[0]    ,*/
    float fVPROT_2;             /* CP     qjrbvaprot[1]    ,*/
    float fVALIM_1;             /* CP     qjrbvalim[0]     ,*/
    float fVALIM_2;             /* CP     qjrbvalim[1]     ,*/
    float fATTFPA_1;            /* CP     qjrfpvfpa[0]     ,*/
    float fATTFPA_2;            /* CP     qjrfpvfpa[1]     ,*/
    float fATTTRK_1;            /* CP     qjrfpvtrk[0]     ,*/
    float fATTTRK_2;            /* CP     qjrfpvtrk[1]     ,*/
    float fCAS_1;               /* CP     qfiadcas[0]      ,*/
    float fCAS_2;               /* CP     qfiadcas[1]      ,*/
    float fFDROLL_1;            /* CP     qerxfdrol[0]     ,*/
    float fFDROLL_2;            /* CP     qerxfdrol[1]     ,*/
    float fFDPITCH_1;           /* CP     qerxfdpit[0]     ,*/
    float fFDPITCH_2;           /* CP     qerxfdpit[1]     ,*/
    float fTRACK_1;             /* CP     qjrtrack[0]      ,*/
    float fTRACK_2;             /* CP     qjrtrack[1]      ,*/
    float fV2_1;                /* CP     qfvspdv2[0]      ,*/
    float fV2_2;                /* CP     qfvspdv2[1]      ,*/
    float fVSEL_1;              /* CP     qjiavsel[0]      ,*/
    float fVSEL_2;              /* CP     qjiavsel[1]      ,*/
    float fVSELC_1;             /* CP     qjcavsel[0]      ,*/
    float fVSELC_2;             /* CP     qjcavsel[1]      ,*/

#ifndef AARES
	unsigned char  ucSPDLIM_1;  /* CP     qjlspdlim[0]     ,*/
    unsigned char  ucSPDLIM_2;  /* CP     qjlspdlim[1]     ,*/
    unsigned char  ucVRDisp_1;  /* CP     qjlndvr[0]       ,*/
    unsigned char  ucVRDisp_2;  /* CP     qjlndvr[1]       ,*/
    unsigned char  ucAPSTAT  ;  /* CP     qesfxapeng[0]    ,*/
    unsigned char  ucFDSTAT  ;  /* CP     qesfxfd[0]       ,*/
    unsigned char  ucATSTAT  ;  /* CP     qesfxatmod[0]    ,*/
    unsigned char  ucCATNB   ;  /* CP     qes_cat_nb[0]    ,*/
    unsigned char  ucAPPCAB  ;  /* CP     qesfxsgldl[0]    ,*/
    unsigned char  ucHDGSCL_1;  /* CP     qelxhdgsc[0]     ,*/
    unsigned char  ucHDGSCL_2;  /* CP     qelxhdgsc[1]     ,*/
    unsigned char  ucATTACT_1;  /* CP     qelznaatt[0]     ,*/
    unsigned char  ucATTACT_2;  /* CP     qelznaatt[1]     ,*/
    unsigned char  ucDEVSYM_1;  /* CP     qelnadev[0]      ,*/
    unsigned char  ucDEVSYM_2;  /* CP     qelnadev[1]      ,*/
    unsigned char  ucSPDSCL_1;  /* CP     qelznaspd[0]     ,*/
    unsigned char  ucSPDSCL_2;  /* CP     qelznaspd[1]     ,*/
    unsigned char  ucALTSCL_1;  /* CP     qelznaalt[0]     ,*/
    unsigned char  ucALTSCL_2;  /* CP     qelznaalt[1]     ,*/
#endif
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEISData;

/******************************************************************************/
/*FCU LABELS*/
/******************************************************************************/
/*FCU & EFIS Ctrl Panel L-R COM LABELS */
/******************************************************************************/

typedef struct /* 55 FCU PARAM REQUEST BLOCK */
{
    int iFCU_AP1_RQ;      /*AutoPilot 1 Request            sspbap1      */
    int iFCU_AP2_RQ;      /*AutoPilot 2 Request            sspbap2      */
    int iFCU_ATHR_RQ;     /*AutoTHR Request                sspbfd[0]    */
    int iFCU_LOC_RQ;      /*LOC BUTTON Request             sspbfd[1]    */
    int iFCU_APPR_RQ;     /*APPR BUTTON Request            sspbathr     */
    int iFCU_EXPED_RQ;    /*EXPED BUTTON Request           sspbloc      */
    int iFD1_RQ;          /*FD1 BUTTON Request             sspbappr     */
    int iFD2_RQ;          /*FD2 BUTTON Request             sspbalt      */

    int iFCU_SPD_KNOB_I;  /*FCU SPD KNOB PUSH Request      ssknob1_i    */
    int iFCU_SPD_KNOB_O;  /*FCU SPD KNOB PULL Request      ssknob1_o    */
    int iFCU_HDG_KNOB_I;  /*FCU HDG KNOB PUSH Request      ssknob2_i    */
    int iFCU_HDG_KNOB_O;  /*FCU HDG KNOB PULL Request      ssknob2_o    */
    int iFCU_ALT_KNOB_I;  /*FCU ALT KNOB PUSH Request      ssknob3_i    */
    int iFCU_ALT_KNOB_O;  /*FCU ALT KNOB PULL Request      ssknob3_o    */
    int iFCU_FPA_KNOB_I;  /*FCU FPA KNOB PUSH Request      ssknob4_i    */
    int iFCU_FPA_KNOB_O;  /*FCU FPA KNOB PULL Request      ssknob4_o    */

    int iFCU_LS1_RQ;      /*LS1 BUTTON Request             sspbls[0]    */
    int iFCU_LS2_RQ;      /*LS2 BUTTON Request             sspbls[1]    */

    int iFCU_QNHL_KNOB_I; /*FCU QNHL KNOB PUSH Request     ssknob5_i[0] */
    int iFCU_QNHL_KNOB_O; /*FCU QNHL KNOB PULL Request     ssknob5_o[0] */
    int iFCU_QNHR_KNOB_I; /*FCU QNHR KNOB PUSH Request     ssknob5_i[1] */
    int iFCU_QNHR_KNOB_O; /*FCU QNHR KNOB PULL Request     ssknob5_o[1] */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sFCURqData;

typedef struct     /* 56 FCU PARAM STATUS BLOCK */
{
    int iFCU_AP1_STAT;   /*AutoPilot 1 Status        ssap1pblt  */
    int iFCU_AP2_STAT;   /*AutoPilot 2 Status        ssap2pblt  */
    int iFCU_ATHR_STAT;  /*AutoTHR Status            ssatpblt   */
    int iFCU_LOC_STAT;   /*LOC BUTTON Status         sslocpblt  */
    int iFCU_APPR_STAT;  /*APPR BUTTON Status        ssapppblt  */
    int iFCU_EXPED_STAT; /*EXPED BUTTON Status       ssaltpblt  */

    int iFD1_STAT;       /*FD1 BUTTON Status         ssfdlpblt  */
    int iFD2_STAT;       /*FD2 BUTTON Status         ssfdrpblt  */

    int iSPD_MAN_STAT;   /*SPD MANAGED OR SELECTED   ssspdmlt   */
    int iHDG_MAN_STAT;   /*LAT MANAGED OR SELECTED   sslatlt    */
    int iALT_MAN_STAT;   /*ALT MANAGED OR SELECTED   sslvlclt   */
    int iSPD_DSH_STAT;   /*SPD DISPLAY DASHED        ssspdwdsh  */
    int iHDG_DSH_STAT;   /*LAT DISPLAY DASHED        sslatwdsh  */

    int iLS1_STAT;       /*LS1 BUTTON Status         sslslpblt  */
    int iLS2_STAT;       /*LS2 BUTTON Status         sslsrpblt  */

    int iECPL_QNHSTD;    /*QNH DISPL Status          ssprslwdsh */
    int iECPR_QNHSTD;    /*QNH DISPL Status          ssprsrwdsh */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sFCUStatData;

typedef struct
{
    int iECPL_NavSel1;      /* 1=ADF 0=OFF 2=VOR        ssswitch3   */
    int iECPL_NavSel2;      /* 1=ADF 0=OFF 2=VOR        ssswitch3   */
    int iECPL_QNH_QFE;      /*QNH or QFE                            */
    float fECPL_QNHDISPL;   /* DISPLAY                              */
    int iECPL_QNHMode;      /* hPA or grQ                           */
    int iECPL_QNHSTD;       /* 0=QNH 1 STD                          */

    int iECPL_RngSel;       /*0=10Nm   5=320Nm*/
    int iECPL_ModeSel;      /*0=LS 1=VOR 2=Nav*/
    int iECPL_DCstrBut;     /*0=Off 1=On      */
    int iECPL_DWptBut;      /*0=Off 1=On      */
    int iECPL_DVorBut;      /*0=Off 1=On      */
    int iECPL_DNDBBut;      /*0=Off 1=On      */
    int iECPL_DArptBut;     /*0=Off 1=On      */

    int iECPR_NavSel1;      /* 1=ADF 0=OFF 2=VOR        ssswitch3   */
    int iECPR_NavSel2;      /* 1=ADF 0=OFF 2=VOR        ssswitch3   */
    int iECPR_QNH_QFE;      /* QNH or QFE   */
    float fECPR_QNHDISPL;   /* DISPLAY      */
    int iECPR_QNHMode;      /* hPA or grQ   */
    int iECPR_QNHSTD;       /* 0=QNH 1 STD  */

    int iECPR_RngSel;       /*0=10Nm   5=320Nm */
    int iECPR_ModeSel;      /*0=LS 1=VOR 2=Nav */
    int iECPR_DCstrBut;     /*0=Off 1=On  */
    int iECPR_DWptBut;      /*0=Off 1=On  */
    int iECPR_DVorBut;      /*0=Off 1=On  */
    int iECPR_DNDBBut;      /*0=Off 1=On  */
    int iECPR_DArptBut;     /*0=Off 1=On  */

    int iFCU_SPDMA_Set;     /*Speed Set                     */
    int iFCU_ALT_Set;       /*Speed Set                     */
    int iFCU_HDGTRK_Set;    /*HDG/TRK Set                   */
    int iFCU_VSFPA_Set;     /*VS/FPA Set                    */

    int iFCU_MEALTBUT_Set;  /*MEALT BUTTON  0=FEET 1=METER  */
    int iFCU_HDGTRKBUT_Set; /*HDGTRK BUTTON  0=HDG 1=TRK    */
    int iFCU_SPDMABUT_Set;  /*SPDMA BUTTON  0=SPD 1=MA      */

    int iLS1_STAT;          /*LS1 BUTTON Status             */
    int iLS2_STAT;          /*LS2 BUTTON Status             */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sFCUSetData;

typedef struct
{
    unsigned char  ucFlightFreeze;
    unsigned char  ucFuelFreeze;
    unsigned char  ucA33XOnOff;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSimData;

typedef struct
{
    float fAIR1ATHAcc;      /*ALONG TRACK HORIZ. ACCEL.*/
    float fAIR1CTHAcc;      /*CROSS TRACK HORIZ. ACCEL.*/
    float fAIR1FPAcc;       /*FLIGHT PATH ACCEL.*/
    float fAIR1DAngle;      /*DRIFT ANGLE*/
    float fAIR1INLat;       /*INERTIAL LATITUDE D*/
    float fAIR1INLong;      /*INERTIAL LONGITUDE D*/
    float fAIR1FPAngle;     /*FLIGHT PATH ANGLE*/
    float fAIR1INAlt;       /*INERTIAL ALTITUDE*/
    float fAIR1VSpeed;      /*VERTICAL SPEED*/
    float fAIR1BRollRate;   /*BODY ROLL RATE*/
    float fAIR1BRollAngle;  /*ROLL ANGLE*/
    float fAIR1BRollAttRate;/*ROLL ATT RATE*/
    float fAIR1THdg;        /*TRUE HEADING D*/
    float fAIR1MHdg;        /*MAGNETIC HEADING D*/
    float fAIR1TTAngle;     /*TRUE TRACK ANGLE D*/
    float fAIR1MTAngle;     /*MAG TRACK ANGLE*/
    float fAIR1WDir;        /*WIND DIRECTION D*/
    float fAIR1WSpeed;      /*WIND SPEED D*/
    float fAIR1BPRate;      /*BODY PITCH RATE*/
    float fAIR1BYRate;      /*BODY YAW RATE*/
    float fAIR1BAlt;        /*ADC BARO ALT D*/
    float fAIR1GSpeed;      /*GROUND SPEED D*/
    float fAIR1TASpeed;     /*ADC TRUE AIRSPEED D*/
    float fAIR1PitchAngle;  /*PITCH ANGLE*/
    float fAIR1PitchAttRate;/*PITCH ATT RATE*/
    float fAIR1Mach;        /*ADC Mach*/
    float fAIR1Cas;         /*ADC CAS*/
    float fAIR1MAAirSp;     /*ADC Max Allowed AirSpeed*/
    float fAIR1TAS;         /*ADC TAS*/
    float fAIR1Alt;         /*ADC ALT*/
    float fAIR1CBAlt1;      /*ADC Corrected Baro Alt #1*/
    float fAIR1CBAlt2;      /*ADC Corrected Baro Alt #2*/
    float fAIR1AltRate;     /*ADC ALT RATE*/
    float fAIR1LStatPress;  /*ADC Left Static Pressure*/
    float fAIR1RStatPress;  /*ADC Right Static Pressure*/
    float fAIR1DynPress;    /*ADC Impact Pressure*/
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sADIRSData1;

typedef struct
{
    float fAIR2ATHAcc;      /*ALONG TRACK HORIZ. ACCEL.*/
    float fAIR2CTHAcc;      /*CROSS TRACK HORIZ. ACCEL.*/
    float fAIR2FPAcc;       /*FLIGHT PATH ACCEL.*/
    float fAIR2DAngle;      /*DRIFT ANGLE*/
    float fAIR2INLat;       /*INERTIAL LATITUDE D*/
    float fAIR2INLong;      /*INERTIAL LONGITUDE D*/
    float fAIR2FPAngle;     /*FLIGHT PATH ANGLE*/
    float fAIR2INAlt;       /*INERTIAL ALTITUDE*/
    float fAIR2VSpeed;      /*VERTICAL SPEED*/
    float fAIR2BRollRate;   /*BODY ROLL RATE*/
    float fAIR2BRollAngle;  /*ROLL ANGLE*/
    float fAIR2BRollAttRate;/*ROLL ATT RATE*/
    float fAIR2THdg;        /*TRUE HEADING D*/
    float fAIR2MHdg;        /*MAGNETIC HEADING D*/
    float fAIR2TTAngle;     /*TRUE TRACK ANGLE D*/
    float fAIR2MTAngle;     /*MAG TRACK ANGLE*/
    float fAIR2WDir;        /*WIND DIRECTION D*/
    float fAIR2WSpeed;      /*WIND SPEED D*/
    float fAIR2BPRate;      /*BODY PITCH RATE*/
    float fAIR2BYRate;      /*BODY YAW RATE*/
    float fAIR2BAlt;        /*ADC BARO ALT D*/
    float fAIR2GSpeed;      /*GROUND SPEED D*/
    float fAIR2TASpeed;     /*ADC TRUE AIRSPEED D*/
    float fAIR2PitchAngle;  /*PITCH ANGLE*/
    float fAIR2PitchAttRate;/*PITCH ATT RATE*/
    float fAIR2Mach;        /*ADC Mach*/
    float fAIR2Cas;         /*ADC CAS*/
    float fAIR2MAAirSp;     /*ADC Max Allowed AirSpeed*/
    float fAIR2TAS;         /*ADC TAS*/
    float fAIR2Alt;         /*ADC ALT*/
    float fAIR2CBAlt1;      /*ADC Corrected Baro Alt #1*/
    float fAIR2CBAlt2;      /*ADC Corrected Baro Alt #2*/
    float fAIR2AltRate;     /*ADC ALT RATE*/
    float fAIR2LStatPress;  /*ADC Left Static Pressure*/
    float fAIR2RStatPress;  /*ADC Right Static Pressure*/
    float fAIR2DynPress;    /*ADC Impact Pressure*/
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sADIRSData2;

typedef struct
{
    float fAIR3ATHAcc;      /*ALONG TRACK HORIZ. ACCEL.*/
    float fAIR3CTHAcc;      /*CROSS TRACK HORIZ. ACCEL.*/
    float fAIR3FPAcc;       /*FLIGHT PATH ACCEL.*/
    float fAIR3DAngle;      /*DRIFT ANGLE*/
    float fAIR3INLat;       /*INERTIAL LATITUDE D*/
    float fAIR3INLong;      /*INERTIAL LONGITUDE D*/
    float fAIR3FPAngle;     /*FLIGHT PATH ANGLE*/
    float fAIR3INAlt;       /*INERTIAL ALTITUDE*/
    float fAIR3VSpeed;      /*VERTICAL SPEED*/
    float fAIR3BRollRate;   /*BODY ROLL RATE*/
    float fAIR3BRollAngle;  /*ROLL ANGLE*/
    float fAIR3BRollAttRate;/*ROLL ATT RATE*/
    float fAIR3THdg;        /*TRUE HEADING D*/
    float fAIR3MHdg;        /*MAGNETIC HEADING D*/
    float fAIR3TTAngle;     /*TRUE TRACK ANGLE D*/
    float fAIR3MTAngle;     /*MAG TRACK ANGLE*/
    float fAIR3WDir;        /*WIND DIRECTION D*/
    float fAIR3WSpeed;      /*WIND SPEED D*/
    float fAIR3BPRate;      /*BODY PITCH RATE*/
    float fAIR3BYRate;      /*BODY YAW RATE*/
    float fAIR3BAlt;        /*ADC BARO ALT D*/
    float fAIR3GSpeed;      /*GROUND SPEED D*/
    float fAIR3TASpeed;     /*ADC TRUE AIRSPEED D*/
    float fAIR3PitchAngle;  /*PITCH ANGLE*/
    float fAIR3PitchAttRate;/*PITCH ATT RATE*/
    float fAIR3Mach;        /*ADC Mach*/
    float fAIR3Cas;         /*ADC CAS*/
    float fAIR3MAAirSp;     /*ADC Max Allowed AirSpeed*/
    float fAIR3TAS;         /*ADC TAS*/
    float fAIR3Alt;         /*ADC ALT*/
    float fAIR3CBAlt1;      /*ADC Corrected Baro Alt #1*/
    float fAIR3CBAlt2;      /*ADC Corrected Baro Alt #2*/
    float fAIR3AltRate;     /*ADC ALT RATE*/
    float fAIR3LStatPress;  /*ADC Left Static Pressure*/
    float fAIR3RStatPress;  /*ADC Right Static Pressure*/
    float fAIR3DynPress;    /*ADC Impact Pressure*/
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sADIRSData3;

typedef struct
{
	#ifdef AARES
    unsigned char ucVSIDisplyTextbox_1;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_1;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_1;/*ePFD: ALTITUDE Readout upper/lower                  */
	#endif
	float fLocalizerDeviation_1;                /*loc indication ptr (<>)                      F8.3   */
    float fNeedleRotation_1;                    /*needle rortation from horizontal             F8.3   */
    float fLateralRotation_1;                   /*L)general rotation                     [deg] AN180  */
    float fSpeedScalePosition_1;                /*speed scale position                 [knots] F7.2   */
    float fAltitudeScaleDisplacement_1;         /*Alt scale displacement                       F8.3   */
    float fVDEVDeviation_1;                     /*vdev indicator pointer var                   F8.3   */
    float fDMEDistance_1;                       /*ePFD: DME distance                   [NM]           */
    float fILSFrequency_1;                      /*ePFD: ILS Freq.                                     */
    float fVTrendUp_1;                          /*ePFD: Vc Trend up                                   */
    float fVTrendDown_1;                        /*ePFD: Vc Trend down                                 */
    float fSelectedSpeed_1;                     /*ePFD: Selected Speed                 [kts]          */
    float fSelectedSpeedValue_1;                /*ePFD: Selected Speed display                        */
    float fPressureReference_inHg_1;            /*ePFD: Pressure Reference             [inHg]         */
    float fPressureReference_mbar_1;            /*ePFD: Pressure Reference             [mbar]         */
    float fVSIReadout_1;                        /*ePFD: V-Speed Readout                [100ft/s]      */
    float fVSIReadoutPosition_1;                /*ePFD: V-Speed Readout position                      */
    float fRAReadout_1;                         /*ePFD: RA Attitude Readout            [ft]           */
    float fILSCoursePosition_1;                 /*ePFD: ILS Course Symbol              [deg]          */
    float fILSCourseReadout_1;                  /*ePFD: ILS Course Readout             [deg]          */
    float fAltitudefeetReadout_1;               /*ePFD: ALTITUDE Readout XXXXX         [ft]           */
    float fAltitudeFLReadout_1;                 /*ePFD: ALTITUDE Readout FLXXX         [ft*100]       */
    float fSelectedAltitudePosition_1;          /*ePFD: ALTITUDE Sel. Altitude position               */
    float fSeletectedFLPosition_1;              /*ePFD: ALTITUDE Sel. FL position                     */
    float fSelectedHeadingReadoutDeg_1;         /*ePFD: Selected HEADING readout       [deg]          */
    float fAltitudeRadioHeight_1;               /*ePFD: ALTITUDE Radio Height          [ft]           */
    float fAltitudeVerticalDeviation_1;         /*ePFD: ALTITUDE Vertical Dev          [ft]           */
    float fDesSpeedHighValue_1;                 /*ePFD: SPEED Des Speed margin high    [kts]          */
    float fDesSpeedLowValue_1;                  /*ePFD: SPEED Des Speed margin low     [kts]          */
    float fGroundStickRoll_1;                   /*ePFD: ATTITUDE Ground Sstick Roll                   */
    float fGroundStickPitch_1;                  /*ePFD: ATTITUDE Ground Sstick Pitch                  */
    float fFDYawBarDeviation_1;                 /*ePFD: ATTITUDE FD Yaw Bar                           */
    float fSideSlip_1;                          /*ePFD: ATTITUDE SideSlip Indicator    [deg]          */
    float fFMAMDAMDHValue_1;                    /*ePFD: FMA MDA/MDH value              [ft]           */
    int iNeedleReadoutColor_1;                  /*needle and readout color                     I4     */
    int iVDEVPositionIndication_1;              /*vdev indicator (,2:bot,top,both)             I4     */
    int iV1Status_1;                            /*ePFD: V1 status                      [index]        */
    int iSelectedSpeedStatus_1;                 /*ePFD: Selected Speed status          [index]        */
    int iSelectedSpeedColor_1;                  /*ePFD: Speed color change             [index]        */
    int iVSIColor_1;                            /*ePFD: V-Speed color change           [index]        */
    int iAltitudeDisplay_1;                     /*ePFD: ALTITUDE Display               [index]        */
    int iAltitudeTextColor_1;                   /*ePFD: ALTITUDE Text Color                           */
    int iAltitudeFLTextColor_1;                 /*ePFD: ALTITUDE Text Color (FL lower)				*/

	#ifndef AARES
    unsigned char ucVSIDisplyTextbox_1;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_1;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_1;/*ePFD: ALTITUDE Readout upper/lower                  */
	#endif
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sPFDDataDMC1;

typedef struct
{
	#ifdef AARES
    unsigned char ucVSIDisplyTextbox_2;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_2;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_2;/*ePFD: ALTITUDE Readout upper/lower                  */
    #endif
	float fLocalizerDeviation_2;                /*loc indication ptr (<>)                      F8.3   */
    float fNeedleRotation_2;                    /*needle rortation from horizontal             F8.3   */
    float fLateralRotation_2;                   /*L)general rotation                     [deg] AN180  */
    float fSpeedScalePosition_2;                /*speed scale position                 [knots] F7.2   */
    float fAltitudeScaleDisplacement_2;         /*Alt scale displacement                       F8.3   */
    float fVDEVDeviation_2;                     /*vdev indicator pointer var                   F8.3   */
    float fDMEDistance_2;                       /*ePFD: DME distance                   [NM]           */
    float fILSFrequency_2;                      /*ePFD: ILS Freq.                                     */
    float fVTrendUp_2;                          /*ePFD: Vc Trend up                                   */
    float fVTrendDown_2;                        /*ePFD: Vc Trend down                                 */
    float fSelectedSpeed_2;                     /*ePFD: Selected Speed                 [kts]          */
    float fSelectedSpeedValue_2;                /*ePFD: Selected Speed display                        */
    float fPressureReference_inHg_2;            /*ePFD: Pressure Reference             [inHg]         */
    float fPressureReference_mbar_2;            /*ePFD: Pressure Reference             [mbar]         */
    float fVSIReadout_2;                        /*ePFD: V-Speed Readout                [100ft/s]      */
    float fVSIReadoutPosition_2;                /*ePFD: V-Speed Readout position                      */
    float fRAReadout_2;                         /*ePFD: RA Attitude Readout            [ft]           */
    float fILSCoursePosition_2;                 /*ePFD: ILS Course Symbol              [deg]          */
    float fILSCourseReadout_2;                  /*ePFD: ILS Course Readout             [deg]          */
    float fAltitudefeetReadout_2;               /*ePFD: ALTITUDE Readout XXXXX         [ft]           */
    float fAltitudeFLReadout_2;                 /*ePFD: ALTITUDE Readout FLXXX         [ft*100]       */
    float fSelectedAltitudePosition_2;          /*ePFD: ALTITUDE Sel. Altitude position               */
    float fSeletectedFLPosition_2;              /*ePFD: ALTITUDE Sel. FL position                     */
    float fSelectedHeadingReadoutDeg_2;         /*ePFD: Selected HEADING readout       [deg]          */
    float fAltitudeRadioHeight_2;               /*ePFD: ALTITUDE Radio Height          [ft]           */
    float fAltitudeVerticalDeviation_2;         /*ePFD: ALTITUDE Vertical Dev          [ft]           */
    float fDesSpeedHighValue_2;                 /*ePFD: SPEED Des Speed margin high    [kts]          */
    float fDesSpeedLowValue_2;                  /*ePFD: SPEED Des Speed margin low     [kts]          */
    float fGroundStickRoll_2;                   /*ePFD: ATTITUDE Ground Sstick Roll                   */
    float fGroundStickPitch_2;                  /*ePFD: ATTITUDE Ground Sstick Pitch                  */
    float fFDYawBarDeviation_2;                 /*ePFD: ATTITUDE FD Yaw Bar                           */
    float fSideSlip_2;                          /*ePFD: ATTITUDE SideSlip Indicator    [deg]          */
    float fFMAMDAMDHValue_2;                    /*ePFD: FMA MDA/MDH value              [ft]           */
    int iNeedleReadoutColor_2;                  /*needle and readout color                     I4     */
    int iVDEVPositionIndication_2;              /*vdev indicator (,2:bot,top,both)             I4     */
    int iV1Status_2;                            /*ePFD: V1 status                      [index]        */
    int iSelectedSpeedStatus_2;                 /*ePFD: Selected Speed status          [index]        */
    int iSelectedSpeedColor_2;                  /*ePFD: Speed color change             [index]        */
    int iVSIColor_2;                            /*ePFD: V-Speed color change           [index]        */
    int iAltitudeDisplay_2;                     /*ePFD: ALTITUDE Display               [index]        */
    int iAltitudeTextColor_2;                   /*ePFD: ALTITUDE Text Color                           */
    int iAltitudeFLTextColor_2;                 /*ePFD: ALTITUDE Text Color (FL lower)                */
	#ifndef AARES
    unsigned char ucVSIDisplyTextbox_2;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_2;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_2;/*ePFD: ALTITUDE Readout upper/lower                  */
    #endif
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sPFDDataDMC2;

typedef struct
{
	#ifdef AARES
    unsigned char ucVSIDisplyTextbox_3;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_3;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_3;/*ePFD: ALTITUDE Readout upper/lower                  */
	#endif
	float fLocalizerDeviation_3;                /*loc indication ptr (<>)                      F8.3   */
    float fNeedleRotation_3;                    /*needle rortation from horizontal             F8.3   */
    float fLateralRotation_3;                   /*L)general rotation                     [deg] AN180  */
    float fSpeedScalePosition_3;                /*speed scale position                 [knots] F7.2   */
    float fAltitudeScaleDisplacement_3;         /*Alt scale displacement                       F8.3   */
    float fVDEVDeviation_3;                     /*vdev indicator pointer var                   F8.3   */
    float fDMEDistance_3;                       /*ePFD: DME distance                   [NM]           */
    float fILSFrequency_3;                      /*ePFD: ILS Freq.                                     */
    float fVTrendUp_3;                          /*ePFD: Vc Trend up                                   */
    float fVTrendDown_3;                        /*ePFD: Vc Trend down                                 */
    float fSelectedSpeed_3;                     /*ePFD: Selected Speed                 [kts]          */
    float fSelectedSpeedValue_3;                /*ePFD: Selected Speed display                        */
    float fPressureReference_inHg_3;            /*ePFD: Pressure Reference             [inHg]         */
    float fPressureReference_mbar_3;            /*ePFD: Pressure Reference             [mbar]         */
    float fVSIReadout_3;                        /*ePFD: V-Speed Readout                [100ft/s]      */
    float fVSIReadoutPosition_3;                /*ePFD: V-Speed Readout position                      */
    float fRAReadout_3;                         /*ePFD: RA Attitude Readout            [ft]           */
    float fILSCoursePosition_3;                 /*ePFD: ILS Course Symbol              [deg]          */
    float fILSCourseReadout_3;                  /*ePFD: ILS Course Readout             [deg]          */
    float fAltitudefeetReadout_3;               /*ePFD: ALTITUDE Readout XXXXX         [ft]           */
    float fAltitudeFLReadout_3;                 /*ePFD: ALTITUDE Readout FLXXX         [ft*100]       */
    float fSelectedAltitudePosition_3;          /*ePFD: ALTITUDE Sel. Altitude position               */
    float fSeletectedFLPosition_3;              /*ePFD: ALTITUDE Sel. FL position                     */
    float fSelectedHeadingReadoutDeg_3;         /*ePFD: Selected HEADING readout       [deg]          */
    float fAltitudeRadioHeight_3;               /*ePFD: ALTITUDE Radio Height          [ft]           */
    float fAltitudeVerticalDeviation_3;         /*ePFD: ALTITUDE Vertical Dev          [ft]           */
    float fDesSpeedHighValue_3;                 /*ePFD: SPEED Des Speed margin high    [kts]          */
    float fDesSpeedLowValue_3;                  /*ePFD: SPEED Des Speed margin low     [kts]          */
    float fGroundStickRoll_3;                   /*ePFD: ATTITUDE Ground Sstick Roll                   */
    float fGroundStickPitch_3;                  /*ePFD: ATTITUDE Ground Sstick Pitch                  */
    float fFDYawBarDeviation_3;                 /*ePFD: ATTITUDE FD Yaw Bar                           */
    float fSideSlip_3;                          /*ePFD: ATTITUDE SideSlip Indicator    [deg]          */
    float fFMAMDAMDHValue_3;                    /*ePFD: FMA MDA/MDH value              [ft]           */
    int iNeedleReadoutColor_3;                  /*needle and readout color                     I4     */
    int iVDEVPositionIndication_3;              /*vdev indicator (,2:bot,top,both)             I4     */
    int iV1Status_3;                            /*ePFD: V1 status                      [index]        */
    int iSelectedSpeedStatus_3;                 /*ePFD: Selected Speed status          [index]        */
    int iSelectedSpeedColor_3;                  /*ePFD: Speed color change             [index]        */
    int iVSIColor_3;                            /*ePFD: V-Speed color change           [index]        */
    int iAltitudeDisplay_3;                     /*ePFD: ALTITUDE Display               [index]        */
    int iAltitudeTextColor_3;                   /*ePFD: ALTITUDE Text Color                           */
    int iAltitudeFLTextColor_3;                 /*ePFD: ALTITUDE Text Color (FL lower)                */
	#ifndef AARES
    unsigned char ucVSIDisplyTextbox_3;         /*ePFD: V-Speed Textbox display                       */
    unsigned char ucVSIDisplayAmberBox_3;       /*ePFD: V-Speed amber box display                     */
    unsigned char ucAltitudeReadoutUpperLower_3;/*ePFD: ALTITUDE Readout upper/lower                  */
	#endif
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sPFDDataDMC3;

typedef struct
{
    float fXX;
    float fYY;
    float fZZ;
    float fXZ;
    float fYZ;
    float fXY;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sMomentOfInertia;

typedef struct
{
    float fZFW;
    float fPayloadWeight;
    float fTotalFuel;
    float fGrossWeight;
    float fZFWCG;
    float fCG;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sWeight;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fHorizontalStabilizer;
    float fCGShift;
    float fAlphaDot;
    float fSpoiler;
    float fJetEngEffects;
    float fLoadFactor;
    float fSideslip;
    float fAileron;
    float fGear;
    float fElevatorLeft;
    float fElevatorRight;
    float fElevator;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sLiftForce;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fGear;
    float fGearDoors;
    float fSpoiler;
    float fSpeedbrakes;
    float fLiftDumpers;
    float fAileron;
    float fHroizontalStabilizer;
    float fRudder;
    float fStall;
    float fWeight;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sDragForce;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fRudder;
    float fSpoiler;
    float fAileron;
    float fElevator;
    float fBank;
    float fBeta;
    float fGear;
    float fGearDoors;
    float fYawRate;
    float fRollRate;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSideForce;

typedef struct
{
    float fNetThrustEng1;
    float fNetThrustEng2;
    float fXForce;
    float fYForce;
    float fZForce;
    float fPitchMoment;
    float fRollMoment;
    float fYawMoment;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sThrust;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fHorizontalStabilizer;
    float fElevator;
    float fCGShift;
    float fAlphaDot;
    float fSpoiler;
    float fSpeedbrake;
    float fLiftDumpers;
    float fGear;
    float fGearDoors;
    float fJetEngEffects;
    float fLoadFactor;
    float fBeta;
    float fAileron;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sPitchMoment;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fBeta;
    float fRollRate;
    float fYawRate;
    float fRudder;
    float fAileron;
    float fSpoiler;
    float fBetaDot;
    float fGear;
    float fGearDoors;
    float fElevators;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sRollMoment;

typedef struct
{
    float fTotal;
    float fCoeffTotal;
    float fBeta;
    float fRollRate;
    float fYawRate;
    float fRudder;
    float fAileron;
    float fSpoiler;
    float fBetaDot;
    float fGear;
    float fGearDoors;
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sYawMoment;

typedef struct
{
    float fEWD_Eng1_EGTRedline; /*EGTRDLN(1)  EGT Redline           */
    float fEWD_Eng2_EGTRedline; /*EGTRDLN(2)                        */
    float fEWD_Eng1Rev;         /*EREVP(1)  Thrust Reverser Position*/
    float fEWD_Eng2Rev;         /*EREVP(2)                          */
    float fEWD_Eng1EPR_max;     /*EPRMAX(1)  EPR Limit              */
    float fEWD_Eng2EPR_max;     /*EPRMAX(2)                         */
    float fEWD_Eng1_AntiIce;    /*EWAI[1]  - ENGINE ANTI-ICE FLOW   */
    float fEWD_Eng2_AntiIce;    /*EWAI[2]  - ENGINE ANTI-ICE FLOW   */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEWD_Page;

typedef struct
{
    /*Flightphase*/

    int iSD_Permanent_Page_Frz; /*LE0FRZ  - ECAM SD PERMANENT DATA FREEZE FLAG  */
    int iSD_APU_Page_Frz;       /*LE1FRZ  - APU ECAM SYSTEM PAGE FREEZE FLAG    */
    int iSD_ACElec_Page_Frz;    /*LE2FRZ  - EL/AC ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_DCElec_Page_Frz;    /*LE3FRZ  - EL/DC ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_HYD_Page_Frz;       /*LE4FRZ  - HYD ECAM SYSTEM PAGE FREEZE FLAG    */
    int iSD_Press_Page_Frz;     /*LE5FRZ  - PRESS ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_Bleed_Page_Frz;     /*LE6FRZ  - BLEED ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_Cond_Page_Frz;      /*LE7FRZ  - COND ECAM SYSTEM PAGE FREEZE FLAG   */
    int iSD_Wheel_Page_Frz;     /*LE8FRZ  - WHEEL ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_Eng_Page_Frz;       /*LE9FRZ  - ENG ECAM SYSTEM PAGE FREEZE FLAG    */
    int iSD_FCTL_Page_Frz;      /*LEAFRZ  - F/CTL ECAM SYSTEM PAGE FREEZE FLAG  */
    int iSD_Door_Page_Frz;      /*LEBFRZ  - DOOR ECAM SYSTEM PAGE FREEZE FLAG   */
    int iSD_Fuel_Page_Frz;      /*LECFRZ  - FUEL ECAM SYSTEM PAGE FREEZE FLAG   */
    int iSD_APU_Page_Sel;       /*LE1PAGE  - APU ECAM PAGE SELECTED             */
    int iSD_ACElec_Page_Sel;    /*LE2PAGE  - EL/AC ECAM PAGE SELECTED           */
    int iSD_DCElec_Page_Sel;    /*LE3PAGE  - EL/DC ECAM PAGE SELECTED           */
    int iSD_HYD_Page_Sel;       /*LE4PAGE  - HYD ECAM PAGE SELECTED             */
    int iSD_Press_Page_Sel;     /*LE5PAGE  - PRESS ECAM PAGE SELECTED           */
    int iSD_Bleed_Page_Sel;     /*LE6PAGE  - BLEED ECAM PAGE SELECTED           */
    int iSD_Cond_Page_Sel;      /*LE7PAGE  - COND ECAM PAGE SELECTED            */
    int iSD_Wheel_Page_Sel;     /*LE8PAGE  - WHEEL ECAM PAGE SELECTED           */
    int iSD_Eng_Page_Sel;       /*LE9PAGE  - ENG ECAM PAGE SELECTED             */
    int iSD_FCTL_Page_Sel;      /*LEAPAGE  - F/CTL ECAM PAGE SELECTED           */
    int iSD_Door_Page_Sel;      /*LEBPAGE  - DOOR ECAM PAGE SELECTED            */
    int iSD_Fuel_Page_Sel;      /*LECPAGE  - FUEL ECAM PAGE SELECTED            */
    int iSD_SAT;                /*LEI0SAT  - SAT indication                     */
    int iSD_TAT;                /*LEI0TAT  - TAT indication                     */
    int iSD_UTC_Hour;           /*LEI0UTCH  - UTC Hour                          */
    int iSD_UTC_Min;            /*LEI0UTCM  - UTC Minutes                       */
    float fSD_GrossWeight_CG;   /*LER0GWC  - GWCG Num. Value                    */
    float fSD_GrossWeight;      /*LEI0GW  - GW Num. Value                       */
    float fSD_Gload;            /*LER0GLDN  - G Load Value                      */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_PermanentPage;

typedef struct
{
    float fSD_Eng1_FuelUsed;    /*EWFUSED[1]  - FUEL USED                       */
    float fSD_Eng1_N1Vib;       /*EVIBN1IN[1]  - ENGINE N1 VIB AMPL INDICATED   */
    float fSD_Eng1_N2Vib;       /*EVIBN2IN[1]  - ENGINE N2 VIB AMPL INDICATED   */
    float fSD_Eng1_NACTemp;     /*ENACT[1]  - NACELLE TEMPERATURE               */
    float fSD_Eng1_OilPress;    /*EOILP[1]  - OIL PRESSURE                      */
    float fSD_Eng1_OilQT;       /*EOILQ[1]  - OIL QUANTITY                      */
    float fSD_Eng1_OilTemp;     /*EOILT[1]  - OIL TEMPERATURE                   */
    float fSD_Eng1_StartPres;   /*EPSTA[1]  - STARTER PRESSURE                  */
    float fSD_Eng2_FuelUsed;    /*EWFUSED[2]  - FUEL USED                       */
    float fSD_Eng2_N1Vib;       /*EVIBN1IN[2]  - ENGINE N1 VIB AMPL INDICATED   */
    float fSD_Eng2_N2Vib;       /*EVIBN2IN[2]  - ENGINE N2 VIB AMPL INDICATED   */
    float fSD_Eng2_NACTemp;     /*ENACT[2]  - NACELLE TEMPERATURE               */
    float fSD_Eng2_OilPress;    /*EOILP[2]  - OIL PRESSURE                      */
    float fSD_Eng2_OilQT;       /*EOILQ[2]  - OIL QUANTITY                      */
    float fSD_Eng2_OilTemp;     /*EOILT[2]  - OIL TEMPERATURE                   */
    float fSD_Eng2_StartPres;   /*EPSTA[2]  - STARTER PRESSURE                  */
    float fSD_GreenSysPress;    /*AHPG           - Green  sys manifold press    */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_EnginePage;

typedef struct
{
    float fSD_ACT1FuelQT;       /*AFQ7   - ACT 1 tank quantity                      */
    float fSD_ACT2FuelQT;       /*AFQ8   - ACT 2 tank quantity                      */
    float fSD_AftTemp;          /*DNTCAI[5]  - ZONE ADV TEMP                        */
    float fSD_APU_Valve;        /*AFVIU   - APU isolation valve position            */
    float fSD_CabAlt;           /*DTHC   - CABIN ALTITUDE                           */
    float fSD_CabPressRate;     /*DURC   - CABIN PRESS RATE SENSED                  */
    float fSD_CenterFuelQT;     /*AFQ5   - Center tank quantity                     */
    float fSD_CkptTemp;         /*DNTCI   - COCKPIT TEMPERATURE                     */
    float fSD_CrossFeedValve;   /*AFVXW   - Wing crossfeed valve position           */
    float fSD_DuctTemp;         /*DNTDAI  - ZONE DUCT ADV TEMP                      */
    float fSD_Eng1_FuelUsed;    /*EWFUSED[1]  - FUEL USED                           */
    float fSD_Eng2_FuelUsed;    /*EWFUSED[2]  - FUEL USED                           */
    float fSD_FOBQT;            /*AFQT   - Total fuel quantity                      */
    float fSD_FwdTemp;          /*DNTCAI[1]  - ZONE ADV TEMP                        */
    float fSD_FwdTransf;        /*AFVXFRF  - Forward transfer valve position        */
    float fSD_L_EngineValve;    /*AFVLP   - Fuel lo pressure valve 1 position       */
    float fSD_L_Out2In_Valve;   /*AFVXFRL  - Left outr to inr transfer valve posn   */
    float fSD_LdgElev;          /*DVHLI   - LANDING FIELD ELEVATION                 */
    float fSD_LeftAftTransf;    /*AFVXFRAL  - Left aft transfer valve position      */
    float fSD_LeftCellFuelQT;   /*AFQC2   - Left inner collector cell fuel quantity */
    float fSD_LeftInFuelQT;     /*AFQ   - Left inner tank quantity                  */
    float fSD_LeftInTankTemp;   /*AFT   - Left inner tank temperature               */
    float fSD_LeftOutFuelQT;    /*AFQ3   - Left outer tank quantity                 */
    float fSD_LeftOutTankTemp;  /*AFT3   - Left outer tank temperature              */
    float fSD_MidTemp;          /*DNTCAI[3]  - ZONE ADV TEMP                        */
    float fSD_R_EngineValve;    /*AFVLP2  - Fuel lo pressure valve 2 position       */
    float fSD_R_Out2In_Valve;   /*AFVXFRR  - Right outr to inr transfer valve posn  */
    float fSD_RightAftTransf;   /*AFVXFRAR  - Right aft transfer valve position     */
    float fSD_RightCellFuelQT;  /*AFQC3   - Right outer collector cel fuel quantity */
    float fSD_RightInFuelQT;    /*AFQ2   - Right inner tank quantity                */
    float fSD_RightInTankTemp;  /*AFT2   - Right inner tank temperature             */
    float fSD_RightOutFuelQT;   /*AFQ4   - Right outer tank quantity                */
    float fSD_RightOutTankTemp; /*AFT4   - Right outer tank temperature             */
    float fSD_TrimFuelQT;       /*AFQ6   - Trim tank quantity                       */
    float fSD_TrimT_Valve;      /*AFVITT - Trim tank isolation valve position       */
    float fSD_TrimTankTemp;     /*AFT6   - Trim tank temperature                    */
    float fSD_CabPressRate1;    /*dtqc   - Cabin Alt ROC                            */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_CruisePage;

typedef struct
{
    float fSD_APU_BleedPre;     /*AUPB   - Bleed pressure               */
    float fSD_APU_BleedTemp;    /*AUTB   - Bleed temperature            */
    float fSD_APU_EGT;          /*AUTE   - APU egt                      */
    float fSD_APU_FF;           /*AUWF   - Fuel flow                    */
    float fSD_APU_FlapPos;      /*AUVFLAP - APU air intake flap position*/
    float fSD_APU_OilQT;        /*AUQOIL - APU oil quantity             */
    float fSD_APU_OilTemp;      /*AUTOIL - APU oil temperature          */
    float fSD_APU_RPM;          /*AUNRPM - APU RPM                      */
    float fSD_APU_Valve;        /*AFVIU   - APU isolation valve positio */
    float fSD_APUBleed_Valve;   /*DBVU   - APU BLEED VALVE POSN         */
    float fSD_APUGen_Freq;      /*AEHUG   - APU gen frequency           */
    float fSD_APUGen_Load;      /*AEWUG   - APU gen ac load             */
    float fSD_APUGen_Volt;      /*AEVUG   - APU gen ac voltage          */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_APUPage;

typedef struct
{
    float fSD_ACBus1_V;         /*AEVA11  - BUS 1XP1 VOLTAGE        */
    float fSD_ACBus2_V;         /*AEVA24  - BUS 2XP4 VOLTAGE        */
    float fSD_APUBat_charge;    /*AEQBU   - APU  battery charge     */
    float fSD_APUBat_Curr;      /*AEIBU   - APU  battery current    */
    float fSD_APUBat_Volt;      /*AEVBU   - APU  battery voltage    */
    float fSD_APUBus_V;         /*AEVD30  - BUS 309PP  VOLTAGE      */
    float fSD_APUGen_Freq;      /*AEHUG   - APU gen frequency       */
    float fSD_APUGen_Load;      /*AEWUG   - APU gen ac load         */
    float fSD_APUGen_Volt;      /*AEVUG   - APU gen ac voltage      */
    float fSD_APUTR_Load;       /*AEWTRU  - APU TR LOAD             */
    float fSD_APUTR_Volt;       /*AEVTRU  - APU TR VOLTAGE          */
    float fSD_Bat1_charge;      /*AEQBM   - Main battery 1 charge   */
    float fSD_Bat1_Curr;        /*AEIBM   - Main battery 1 curren   */
    float fSD_Bat1_Volt;        /*AEVBM   - Main battery 1 voltag   */
    float fSD_Bat2_charge;      /*AEQBM2 - Main battery 2 charge    */
    float fSD_Bat2_Curr;        /*AEIBM2  - Main battery 2 curren   */
    float fSD_Bat2_Volt;        /*AEVBM2  - Main battery 2 voltag   */
    float fSD_BatBus_V;         /*AEVD3   - BUS 3PP  VOLTAGE        */
    float fSD_DCBus1_V;         /*AEVD1   - BUS 1PP  VOLTAGE        */
    float fSD_DCBus2_V;         /*AEVD2   - BUS 2PP  VOLTAGE        */
    float fSD_EmerGenHydDemand; /*AEWHDEMG  - EMER GEN HYD DEMAND   */
    float fSD_EmergGen_Freq;    /*AEHEMG  - EMER GEN FREQUENCY      */
    float fSD_EmergGen_Load;    /*AEWEMG  - EMER GEN LOAD AC        */
    float fSD_EmergGen_Volt;    /*AEVEMG  - EMER GEN VOLTAGE        */
    float fSD_EssACBus_V;       /*AEVA9   - BUS 9XP  VOLTAGE        */
    float fSD_EssDCBus_V;       /*AEVD4   - BUS 4PP  VOLTAGE        */
    float fSD_EssTR_Load;       /*AEWTRE  - ESS TR LOAD             */
    float fSD_EssTR_Volt;       /*AEVTRE  - ESS TR VOLTAGE          */
    float fSD_ExtA_Freq;        /*AEHXP   - EXT pwr A frequency     */
    float fSD_ExtA_Volt;        /*AEVXP   - EXT pwr A ac voltage    */
    float fSD_ExtB_Freq;        /*AEHXPB  - EXT pwr B frequency     */
    float fSD_ExtB_Volt;        /*AEVXPB  - EXT pwr B ac voltage    */
    float fSD_Gen1_Freq;        /*AEHEG   - Eng gen 1 frequency     */
    float fSD_Gen1_Load;        /*AEWEG   - Eng gen 1 ac load       */
    float fSD_Gen1_Volt;        /*AEVEG   - Eng gen 1 ac voltage    */
    float fSD_Gen2_Freq;        /*AEHEG2  - Eng gen 2 frequency     */
    float fSD_Gen2_Load;        /*AEWEG2  - Eng gen 2 ac load       */
    float fSD_Gen2_Volt;        /*AEVEG2  - Eng gen 2 ac voltage    */
    float fSD_IDG1_OiloutTemp;  /*AETOO   - IDG 1 oil outlet temp   */
    float fSD_IDG2_OiloutTemp;  /*AETOO2  - IDG 2 oil outlet temp   */
    float fSD_STATINV_Freq;     /*LSB107AA  - 01/STAT INV FREQ      */
    float fSD_STATINV_Volt;     /*LSB076AA  - 01/STAT INV VOLTAGE   */
    float fSD_TR1_Load;         /*AEWTR   - TR 1 LOAD               */
    float fSD_TR1_Volt;         /*AEVTR   - TR 1 VOLTAGE            */
    float fSD_TR2_Load;         /*AEWTR2  - TR 2 LOAD               */
    float fSD_TR2_Volt;         /*AEVTR2  - TR 2 VOLTAGE            */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_ELECPage;

typedef struct
{
    float fSD_RAT_Press;        /*AHPRAT  - RAT actual output press         */
    float fSD_B_RsvrPress;      /*AHPAB   - Blue   reservoir air pressure   */
    float fSD_Blue_EDP_Press;   /*AHPEB   - B  EDP pressure                 */
    float fSD_BlueSys_Press;    /*AHPB   - Blue   sys manifold press        */
    float fSD_G_RsvrPress;      /*AHPAG   - Green  reservoir air pressure   */
    float fSD_G_RsvrTemp;       /*AHTG   - Green  sys fluid temp            */
    float fSD_Green1_EDP_Press; /*AHPEG1 - G1 EDP pressure                  */
    float fSD_Green4_EDP_Press; /*AHPEG4 - G4 EDP pressure                  */
    float fSD_B_RsvrTemp;       /*AHTB   - Blue   sys fluid temp            */
    float fSD_RAT_extend;       /*AHVRATP  - RAT position ( 1-> extend      */
    float fSD_YellowSys_Press;  /*AHPY   - Yellow sys manifold press        */
    float fSD_RAT_RPM;          /*AHNRAT  - RAT RPM                         */
    float fSD_RsvrQT_B;         /*AHQB   - Blue   sys rsvr qty              */
    float fSD_RsvrQT_G;         /*AHQG   - Green  sys rsvr qty              */
    float fSD_RsvrQT_Y;         /*AHQY   - Yellow sys rsvr qty              */
    float fSD_Y_RsvrPress;      /*AHPAY   - Yellow reservoir air pressure   */
    float fSD_Y_RsvrTemp;       /*AHTY   - Yellow sys fluid temp            */
    float fSD_Yellow_EDP_Press; /*AHPEY   - Y  EDP pressure                 */
    float fSD_GreenSys_Press;   /*AHPG   - Green  sys manifold press        */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_FCTLPage;

typedef struct
{
    float fSD_Bleed_APUBleed_Valve; /*DBVU   - APU BLEED VALVE POSN             */
    float fSD_BleedValve_Eng1;      /*DBVBI[2]  - ENG PRV POSN                  */
    float fSD_BleedValve_Eng2;      /*DBVBI[3]  - ENG PRV POSN                  */
    float fSD_Cond_AftTemp;         /*DNTCAI[5]  - ZONE ADV TEMP                */
    float fSD_Cond_CkptTemp;        /*DNTCI   - COCKPIT TEMPERATURE             */
    float fSD_Cond_FwdTemp;         /*DNTCAI[1]  - ZONE ADV TEMP                */
    float fSD_Cond_MidTemp;         /*DNTCAI[3]  - ZONE ADV TEMP                */
    float fSD_CrossHotAir_Valve_Pos;/*DOVGI[1]  - HOT MANIFOLD SHUT OFF VALVE   */
    float fSD_DuctTemp_Area1;       /*DPTDS1A  - AREA 1 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area2;       /*DPTDS2A  - AREA 2 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area3;       /*DPTDS3A  - AREA 3 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area4;       /*DPTDS4A  - AREA 4 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area5;       /*DPTDS5A  - AREA 5 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area6;       /*DPTDS6A  - AREA 6 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Area7;       /*DPTDS7A  - AREA 7 DUCT TEMP ANTICIP (L1)  */
    float fSD_DuctTemp_Ckpt;        /*DPTDSFA  - FL DK DUCT TEMP ANTICIP (L1)   */
    float fSD_GNDAirFlow;           /*DNWG   - AIR COND GND SUPPLY FLOW         */
    float fSD_GNDAirTemp;           /*DNTG   - AIR COND GND SUPPLY TEMP         */
    float fSD_HighPressValve_Eng1;  /*DBVHI[2]  - ENG HPV POSN                  */
    float fSD_HighPressValve_Eng2;  /*DBVHI[3]  - ENG HPV POSN                  */
    float fSD_HotAir1_Valve_Pos;    /*DOVPI[1]  - TRIM AIR PRV POSN             */
    float fSD_HotAir2_Valve_Pos;    /*DOVPI[2]  - TRIM AIR PRV POSN             */
    float fSD_Pack1_Flow;           /*DPW127C  - PACK FLOW 1                    */
    float fSD_Pack1_Inlet_Temp;     /*DKTFI[1]  - PACK INLET TEMPERATURE        */
    float fSD_Pack1_Outlet_Temp;    /*DMT121A1  - PACK OUTLET TEMPERATURE       */
    float fSD_Pack1_TempCtrl_Valve; /*DLVBI[1]  - TEMP CONTROL VALVE POSITION   */
    float fSD_Pack2_Flow;           /*DPW127D  - PACK FLOW 2                    */
    float fSD_Pack2_Inlet_Temp;     /*DKTFI[2]  - PACK INLET TEMPERATURE        */
    float fSD_Pack2_Outlet_Temp;    /*DMT121A2  - PACK OUTLET TEMPERATURE       */
    float fSD_Pack2_TempCtrl_Valve; /*DLVBI[2]  - TEMP CONTROL VALVE POSITION   */
    float fSD_PackFlowValve_Eng1;   /*DLVFI[1]  - PACK FCV POSITION             */
    float fSD_PackFlowValve_Eng2;   /*DLVFI[2]  - PACK FCV POSITION             */
    float fSD_PrecoolerInlet_Temp1; /*DCTDI[1]  - PRECOOLER INLET TEMP          */
    float fSD_PrecoolerInlet_Temp2; /*DCTDI[2]  - PRECOOLER INLET TEMP          */
    float fSD_RAMAir_Valve_Pos;     /*DOVR   - AIR COND RAM VLV POSN            */
    float fSD_TrimValvePos_Area1;   /*DOVTI[2]  - AREA 1 VALVE POSN             */
    float fSD_TrimValvePos_Area2;   /*DOVTI[3]  - AREA 2 VALVE POSN             */
    float fSD_TrimValvePos_Area3;   /*DOVTI[4]  - AREA 3 VALVE POSN             */
    float fSD_TrimValvePos_Area4;   /*DOVTI[5]  - AREA 4 VALVE POSN             */
    float fSD_TrimValvePos_Area5;   /*DOVTI[6]  - AREA 5 VALVE POSN             */
    float fSD_TrimValvePos_Area6;   /*DOVTI[7]  - AREA 6 VALVE POSN             */
    float fSD_TrimValvePos_Ckpt;    /*DOVTI[1]  - FLT DK VALVE POSN             */
    float fSD_WingAntiIceValve_Eng1;/*DLVAI[1]  - PACK A/I VALVE POSITION       */
    float fSD_WingAntiIceValve_Eng2;/*DLVAI[2]  - PACK A/I VALVE POSITION       */
    float fSD_XbleedValve_Pos;      /*DBVD   - PNEU ISOLATION VLV POSN          */
    float fSD_PrecoolerInlet_Press1;/*DAPEAI[2]   - ENG BLEED DUCT ADV PRESS    */
    float fSD_PrecoolerInlet_Press2;/*DAPEAI[2]   - ENG BLEED DUCT ADV PRESS    */
    float fSD_WingAI_left_Valve1;   /*DGVAI[1]   - NORM A/I VALVE POS           */
    float fSD_WingAI_left_Valve2;   /*DGVAI[2]   - NORM A/I VALVE POS           */
    float fSD_WingAI_right_Valve1;  /*DGVAI[3]   - NORM A/I VALVE POS           */
    float fSD_WingAI_right_Valve2;  /*DGVAI[4]   - NORM A/I VALVE POS           */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_BleedPage;

typedef struct
{
    float fSD_AFT_Outflow_Pos;          /*DVVCFI - FWD O/V COMMAND          */
    float fSD_CabinPress_CabinAltitude; /*DTHC   - CABIN ALTITUDE           */
    float fSD_CabinPress_Diff;          /*DTPDI   - CAB/CARGO DIFF PRESS    */
    float fSD_CabPress_CabRate;         /*DURC   - CABIN PRESS RATE SENSED  */
    float fSD_FWD_Outflow_Pos;          /*DVVCAI - AFT O/V COMMAND          */
    float fSD_LdgElev;                  /*DVHLI   - LANDING FIELD ELEVATION */
    float fSD_Overboad_Valve_Pos;       /*DQVB   - OVERBOARD V POSN         */
    float fSD_Oxygen_Press;             /*TACREWOX - OXYGEN BOTTLE (PSI)    */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_PressPage;

typedef struct
{
    float fSD_BrakeProbe_Temp_W1;   /*ABT[1]  - Brake probe temp wheel 1      */
    float fSD_BrakeProbe_Temp_W2;   /*ABT[2]  - Brake probe temp wheel 2      */
    float fSD_BrakeProbe_Temp_W3;   /*ABT[3]  - Brake probe temp wheel 3      */
    float fSD_BrakeProbe_Temp_W4;   /*ABT[4]  - Brake probe temp wheel 4      */
    float fSD_BrakeProbe_Temp_W5;   /*ABT[5]  - Brake probe temp wheel 5      */
    float fSD_BrakeProbe_Temp_W6;   /*ABT[6]  - Brake probe temp wheel 6      */
    float fSD_BrakeProbe_Temp_W7;   /*ABT[7]  - Brake probe temp wheel 7      */
    float fSD_BrakeProbe_Temp_W8;   /*ABT[8]  - Brake probe temp wheel 8      */
    float fSD_Groundspeed;          /*ABVSOL  - Ground speed                  */
    float fSD_LeftBrake_Press;      /*AB$PBRKL  - Left brake pressure (14-016)*/
    float fSD_NoseGear_Angle;       /*CNWS    - NOSE GEAR ANGLE               */
    float fSD_NoseWheel_Pos;        /*TRWHEEL  - NOSE WHEEL POSITION          */
    float fSD_ParkBrakeAccu_Press;  /*AH$PBAC  - Park brake accum pres(14-016)*/
    float fSD_RightBrake_Press;     /*AB$PBRKR  - Right brake pressure(14-016)*/
    float fSD_Tachometer_Speed;     /*ABVTACH  - Tachometer speed             */
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sSD_WheelPage;


typedef struct //sAnalogeControlData /* 42 */
{
  float fThrustLever1Cmd;
  float fThrustLever2Cmd; 
  float fNWSCmd;
  float fLBrakeCmd;
  float fRBrakeCmd;

  
} 
#ifdef __GNUC__
__attribute__((packed))
#endif
 sAnalogeControlData;

//EFCS Struct /* 601 */
typedef struct
{
    float fRudderPedalA;			/* Rudderpedal position					*/
	float fTillerPositionLeft;		/* Tillerposition Cpt					*/
	float fTillerPositionRight;		/* Tillerposition Fo					*/
	float fRollInputLeft;			/* Left Stick Roll Position				*/
	float fRollInputRight;			/* Right Stick Roll Position			*/
	float fPitchInputLeft;			/* Left Stick Pitch Position			*/
	float fPitchInputRight;			/* Right Stick Pitch Position			*/
	float fBreak1Pedal;				/* Position of left CPT-breakpedal		*/
	float fBreak2Pedal;				/* Position of right CPT-breakpedal		*/
	float fBreak3Pedal;				/* Position of left FO-breakpedal		*/
	float fBreak4Pedal;				/* Position of right FO-breakpedal		*/
	float fSpoilerLeverA;			/* Spoilerleaver position				*/
	float fThrustLeverLPosition;	/* Position of left Thrustlever			*/
	float fThrustLeverRPosition;	/* Position of right Thrustlever		*/
	float fFlapLeverPosition;		/* Position of Flaplever				*/
}
#ifdef __GNUC__
__attribute__((packed))
#endif
 sEFCSControlsData;


#pragma pack()

typedef struct{
    sFlightDisplayCtr FlightDisplayCtr;

    sTimeData TimeData;
    sAircraftPosition AircraftPosition;
    sAircraftData AircraftData;
    sDayNight DayNight;
    sLights Lights;
    sObjectPosition ObjectPosition;
    sAddObject AddObject;
    sDelObject DelObject;
    sSeason Season;
    sWeather Weather;
    sVisualStatus VisualStatus;
    sTranslatoryData TranslatoryData;
    sRotatoryData RotatoryData;
    sAerodynamicData AerodynamicData;
    sEulerData EulerData;
    sMiscData MiscData;
    sAileronData AileronData;
    sElevatorData ElevatorData;
    sRudderData RudderData;
    sSpoilerData SpoilerData;
    sSControlData SControlData;
    sComNavData ComNavData;
    sADIRSData1 ADIRSData1;
    sADIRSData2 ADIRSData2;
    sADIRSData3 ADIRSData3;

    sSimData SimData;
    sEngineData EngineData;
    sEngineControlData EngineControlData;
    sMomentOfInertia MomentOfInertia;
    sWeight Weight;
    //FCU COM STRUCTS
    sFCUSetData FCUSetData;
    sFCURqData FCURqData;
    sFCUStatData FCUStatData;
    // EIS (DMC + DU) Structs
    sEISData EISData;
    sPFDDataDMC1 PFDDataDMC1;
    sPFDDataDMC2 PFDDataDMC2;
    sPFDDataDMC3 PFDDataDMC3;


	sSD_FCTLPage SD_FCTLPage;

	sAnalogeControlData AnalogeControlData;
	sEFCSControlsData   EFCSControlsData;

    sCASData CASData;
    //SimStatus True = AARES online & False = offline/debug
    bool bSimStatus;

    // Added by Angel Chiou
    sLiftForce LiftForce;
} sUDP_Struct;
#endif


