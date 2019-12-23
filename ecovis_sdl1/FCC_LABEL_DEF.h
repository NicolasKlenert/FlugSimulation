//==========================================================================================
//                                      Description                                         
//==========================================================================================
//	A330 (MARS) FCC Implementation LABELS.
//  GLOBAL LABEL DEFINITION FOR FCS MODULE
//  Implementation Status: DIRECT LAW & MAN PITCH TRIM EQUIV. for MARS  2013/01/25
//  
//   ----------------------------------
//  | Name:			FCC_LABEL_DEF.h          |								
//  | Last Edit: 	12.01.2013         |
//  | Author:		Christian Berth    |
//==========================================================================================
//                                 Includes & definitions                                  
//==========================================================================================
#ifndef __FCC_LABEL_DEF_H__
#define __FCC_LABEL_DEF_H__


#ifndef nostatic
static
#endif
struct sHardwareDriveData
{
  bool EMP_Eng1FireLt;  //Engine Master Panel Engine 1 Fire Light
  bool EMP_Eng2FireLt;  //Engine Master Panel Engine 2 Fire Light
  bool EMP_Eng1FaultLt;  //Engine Master Panel Engine 1 Fault Light
  bool EMP_Eng2FaultLt;  //Engine Master Panel Engine 2 Fault Light
  bool EMP_AllLtOff;     //Engine Master Panel All Lights Off
  float CP_TrimWheelPositionCmd; //Center Panel THS Wheel Position

  
} *psHardwareDriveData;


#ifndef nostatic
static
#endif
struct sHydrSys
{
  float Green1HydDSPressLMV;
  float Green4HydDSPressLMV;
  float BlueHydDSPressLMV;
  float YellowHydDSPressLMV;
  float Green1HydEDPPress;
  float Green4HydEDPPress;
  float BlueHydEDPPress;
  float YellowHydEDPPress;
  float GreenHydAccPress;
  float BlueHydAccPress;
  float YellowHydAccPress;
  
} *psHydrSys;

#ifndef nostatic
static
#endif
struct sSurfacePos
{
  float fLIAileron;
  float fRIAileron;
  float fLOAileron;
  float fROAileron;
  float fLElevator;
  float fRElevator;
  float fLStabTrim;
  float fRStabTrim;
  float fRudder;
  float fRudderTrim;
  float fLSpoiler1;
  float fLSpoiler2;
  float fLSpoiler3;
  float fLSpoiler4;
  float fLSpoiler5;
  float fLSpoiler6;
  float fRSpoiler1;
  float fRSpoiler2;
  float fRSpoiler3;
  float fRSpoiler4;
  float fRSpoiler5;
  float fRSpoiler6;
  float fLFlaps;
  float fRFlaps;
} *psSurfacePos;

#ifndef nostatic
static
#endif
struct sSurfacePosCmd
{
  float fLIAileronPosCmd;
  float fRIAileronPosCmd;
  float fLOAileronPosCmd;
  float fROAileronPosCmd;
  float fLElevatorPosCmd;
  float fRElevatorPosCmd;
  float fLStabTrimPosCmd;
  float fRStabTrimPosCmd;
  float fRudderPosCmd;
  float fRudderTrimPosCmd;
  float fLSpoiler1PosCmd;
  float fLSpoiler2PosCmd;
  float fLSpoiler3PosCmd;
  float fLSpoiler4PosCmd;
  float fLSpoiler5PosCmd;
  float fLSpoiler6PosCmd;
  float fRSpoiler1PosCmd;
  float fRSpoiler2PosCmd;
  float fRSpoiler3PosCmd;
  float fRSpoiler4PosCmd;
  float fRSpoiler5PosCmd;
  float fRSpoiler6PosCmd;
  float fFlapsPosCmd;
  float fAileronFlapCmd;
  float fOutAilDefLimFac;  //Outboard Aileron Deflection Limitation Factor depending on CAS
  float fNWSPosCptCmd;
  float fNWSPosFOCmd;
} *psSurfacePosCmd;

#ifndef nostatic
static
#endif
struct sSurfaceCurPos
{
  float fLIAileronPos;
  float fRIAileronPos;
  float fLOAileronPos;
  float fROAileronPos;
  float fLElevatorPos;
  float fRElevatorPos;
  float fLStabTrimPos;
  float fRStabTrimPos;
  float fRudderPos;
  float fRudderTrimPos;
  float fLSpoiler1Pos;
  float fLSpoiler2Pos;
  float fLSpoiler3Pos;
  float fLSpoiler4Pos;
  float fLSpoiler5Pos;
  float fLSpoiler6Pos;
  float fRSpoiler1Pos;
  float fRSpoiler2Pos;
  float fRSpoiler3Pos;
  float fRSpoiler4Pos;
  float fRSpoiler5Pos;
  float fRSpoiler6Pos;
  float fFlapsPos;
  float fNWSPosCptCmd;
  float fNWSPosFOCmd;

} *psSurfaceCurPos;

#ifndef nostatic
static
#endif
struct sEngineCmd
{
  float fLEngThrustLevCmd;
  float fREngThrustLevCmd;
  float fLEngThrustRevCmd;
  float fREngThrustRevCmd;
  bool	bLEngRevEngage;
  bool	bREngRevEngage;
  bool	bLEngMaster;
  bool	bREngMaster;
  bool	bAThrust_Dc;
  int	iLEngStartSel_Crk;
  int	iLEngStartSel_Norm;
  int	iLEngStartSel_Ign;
} *psEngineCmd;

#ifndef nostatic
static
#endif
struct sDAInput
{
  float fLSidestick_Pitch;
  float fLSidestick_Roll;
  float fRSidestick_Pitch;
  float fRSidestick_Roll;
  float fLThrust_Lever;
  float fRThrust_Lever;
  float fRuddPed_Ampl;
  float fLRuddPed_LBrk_Ampl;
  float fLRuddPed_RBrk_Ampl;
  float fRRuddPed_LBrk_Ampl;
  float fRRuddPed_RBrk_Ampl;
  float fLNWS_Ampl;
  float fRNWS_Ampl;
  float fFlap_Lvr;
  float fSpd_Brk_Lvr;
  float fPitch_Trim;
  float fRudder_Trim;
  bool	bLSidestick_APDc;
  bool	bLSidestick_PTT;
  bool	bLNWS_NW_Dc;
  bool	bRSidestick_APDc;
  bool	bRSidestick_PTT;
  bool	bRNWS_NW_Dc;
  bool  bSpd_Brk_Armed;
  bool  bParkingBrk;
  bool  bRudder_Trim_Reset;
  bool  bRudder_Trim_Right;
  bool  bRudder_Trim_Left;
  bool  bAuto_Brk_Low;
  bool  bAuto_Brk_Med;
  bool  bAuto_Brk_Max;
  bool  bAntiSkid;
  bool  bLCronoBut;
  bool  bRCronoBut;
  bool  bLMCautionBut;
  bool  bRMCautionBut;
  bool  bLMWarnBut;
  bool  bRMWarnBut;
  bool	bGearLever_Up;
  bool	bGearLever_Dn;
  bool	bEngPnlStSel_Nrm;
  bool	bEngPnlStSel_Crk;
  bool	bEngPnlStSel_Start;
  bool	bLThrust_Lever_Reverser;
  bool	bRThrust_Lever_Reverser;
  bool	bAThrust_Dc;
  bool	bEngPnl_EngMaster1;
  bool	bEngPnl_EngMaster2;
  bool	bGlareSh_MW_Reset;
  bool	bGlareSh_MC_Reset;
  bool	bGlareSh_Cpt_CronoPB;
  bool	bGlareSh_FO_CronoPB;
} ;

#ifndef nostatic
static
#endif
struct sDAOutput
{
  bool  bAuto_Brk_Low_LT;
  bool  bAuto_Brk_Med_LT;
  bool  bAuto_Brk_Max_LT;
  bool  bLMCautionLT;
  bool  bRMCautionLT;
  bool  bLMWarnLT;
  bool  bRMWarnLT;
  bool	bLEngPnlFaultLT;
  bool	bREngPnlFaultLT;
  bool	bLEngPnlFireLT;
  bool	bREngPnlFireLT;
  bool	bGearLever_Up_LT;
  bool	bGearLever_Dn_LT;
  
} *psDAOutput;

#ifndef nostatic
static
#endif
struct sFCCInput
{
  float fLSidestick_Pitch;
  float fLSidestick_Roll;
  float fRSidestick_Pitch;
  float fSidestick_Roll;
  float fSidestick_Pitch;
  float fRSidestick_Roll;
  float fLThrust_Lever;
  float fRThrust_Lever;
  float fRuddPed_Ampl;
  float fLRuddPed_LBrk_Ampl;
  float fLRuddPed_RBrk_Ampl;
  float fRRuddPed_LBrk_Ampl;
  float fRRuddPed_RBrk_Ampl;
  float fLNWS_Ampl;
  float fRNWS_Ampl;
  float fFlap_Lvr;
  float fSpd_Brk_Lvr;
  float fPitch_Trim;
  float fRudder_Trim;
  bool	bLSidestick_APDc;
  bool	bLSidestick_PTT;
  bool	bLNWS_NW_Dc;
  bool	bRSidestick_APDc;
  bool	bRSidestick_PTT;
  bool	bRNWS_NW_Dc;
  bool  bSpd_Brk_Armed;
  bool  bParkingBrk;
  bool  bRudder_Trim_Reset;
  bool  bRudder_Trim_Right;
  bool  bRudder_Trim_Left;
  bool  bAuto_Brk_Low;
  bool  bAuto_Brk_Med;
  bool  bAuto_Brk_Max;
  bool  bAntiSkid;
  bool  bLCronoBut;
  bool  bRCronoBut;
  bool  bLMCautionBut;
  bool  bRMCautionBut;
  bool  bLMWarnBut;
  bool  bRMWarnBut;
  bool	bGearLever_Up;
  bool	bGearLever_Dn;
  bool	bEngPnlStSel_Nrm;
  bool	bEngPnlStSel_Crk;
  bool	bEngPnlStSel_Start;
  bool	bLThrust_Lever_Reverser;
  bool	bRThrust_Lever_Reverser;
  bool	bAThrust_Dc;
  bool	bEngPnl_EngMaster1;
  bool	bEngPnl_EngMaster2;
  bool	bGlareSh_MW_Reset;
  bool	bGlareSh_MC_Reset;
  bool	bGlareSh_Cpt_CronoPB;
  bool	bGlareSh_FO_CronoPB;
} *psFCCInput;

#ifndef nostatic
static
#endif
struct sFCCCommands
{
  float fPitch_Cmd;
  float fPitch_Rate_Cmd;
  float fPitch_Att_Cmd;  //Theta
  float fPitch_Att_CmdP;
  float fPitch_Att_CmdI;
  float fPitch_Att_CmdD;
  float fPitch_Damper_Cmd;
  float fPitch_Damper_CmdP;
  float fPitch_Damper_CmdI;
  float fPitch_Damper_CmdD;
  float fTheta_Cmd;
  float fCStar_Cmd;
  float fNz_Cmd;
  float fRoll_Cmd;
  float fRoll_Rate_Cmd;
  float fRoll_Angle_Cmd; //Roll Attitude
  float fRoll_Angle_CmdP;
  float fRoll_Angle_CmdI;
  float fRoll_Angle_CmdD;
  float fRoll_Damper_Cmd;
  float fYaw_Cmd;
  float fYaw_Rate_Cmd;
  float fYaw_Damper_Cmd;
  float fStab_Trim_Cmd;
} *psFCCCommands;

#ifndef nostatic
static
#endif
struct sFCCStateParamInput
{
  float fFCCPitchAngle_Deg;
  float fFCCPitchRate_Deg;
  float fFCCPitchAttRate_Deg;	 
  float fFCCRollAngle_Deg;	 
  float fFCCRollRate_Deg;	 
  float fFCCYawAngle_Deg;	 
  float fFCCYawRate_Deg;		 
  float fFCCFPA_Deg;
  float fFCCCAS;
  float fFCC_Nz;
  float fFCCDynPress;
  float fFCCBeta;
  float RadioAlt;
  
} *psFCCStateParamInput;

#ifndef nostatic
static
#endif
//FCS Gains and Values
struct sFCCGains
{
  float PitchRate_PGain;
  float PitchRate_IGain;
  float PitchRate_DGain;

  float PitchAtt_Cmd;
  float PitchAtt_PGain;
  float PitchAtt_IGain;
  float PitchAtt_DGain;
  bool  PitchAtt_TCSwitch;

  float PitchDmp_PGain;
  float PitchDmp_IGain;
  float PitchDmp_DGain;

  float RollRate_PGain;
  float RollRate_IGain;
  float RollRate_DGain;

  float RollAtt_Cmd;
  float RollAtt_PGain;
  float RollAtt_IValue;
  float RollAtt_IGain;
  float RollAtt_DGain;

  float RollDmp_PGain;
  float RollDmp_IGain;
  float RollDmp_DGain;

  float YawRate_Cmd;
  float YawTC_Cmd;
  float YawRate_PGain;
  float YawRate_IGain;
  float YawRate_DGain;

  float YawAtt_Cmd;
  float YawAtt_Static_Gain;
  float YawAtt_PGain;
  float YawAtt_IGain;
  float YawAtt_DGain;

  float YawDmp_Cmd;
  float YawDmp_Static_Gain;
  float YawDmp_PGain;
  float YawDmp_IGain;
  float YawDmp_DGain;

  float Nz_PGain;
  float Nz_IGain;
  float Nz_DGain;

  float Theta_PGain;
  float Theta_IGain;
  float Theta_DGain;

  float FPA_PGain;
  float FPA_IGain;
  float FPA_DGain;


  float fPitchDmpPMem;
  float fPitchDmpIMem;
  float fPitchDmpDMem;

  float fPitchTrimIGain;
  float fPitchTrimIMem;

  float RollRateInt;  //Integrated Value of actual RollRate = RollDeg
  float PitchRateInt;

  float TanPhi;
  float InvCosPhi;

  float DynPressGain;
  
} *psFCCGains;

#endif