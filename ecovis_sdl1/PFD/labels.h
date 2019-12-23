//------------------------------------------------------------------------------
//Filename       labels.h
//System         WinXP
//Author         Richard Wollenheit
//Date           27/09/06
//Description    Definition of ARRAYLABEL and SINGLELABEL enums
//------------------------------------------------------------------------------

#ifndef _LABELS_H_
#define _LABELS_H_

#include "TCPIP.h"


typedef enum //defining ARRAYLABEL enum, which assigns an id-number for each label
{
    CDB_PlanMode_on = 0,
    CDB_AC_TrueTrack,
    CDB_MapReference_lat,
    CDB_MapReference_long,
    CDB_IRS_AC_TrueHeading,
    CDB_AC_MagVAR,
    CDB_AC_drift,
    CDB_AC_altitude,
    CDB_ND_Range,
    CDB_ND_Page,
    CDB_TO_Ident,
    CDB_TO_TrackDistance,
    CDB_TO_Track,
    CDB_TO_Time,
    CDB_ClockTime,
    CDB_CrossTrackError,
    CDB_ActiveFlightPlanPath_lat,
    CDB_ActiveFlightPlanPath_long,
    CDB_ActiveFlightPlanPath_turnradius,
    CDB_ActiveFlightPlanPath_coursechange,
    CDB_ActiveFlightPlanPath_inboundcourse,
    CDB_ActiveFlightPlanPath_index,
    CDB_TemporaryFlightPath_lat,
    CDB_TemporaryFlightPath_long,
    CDB_TemporaryFlightPath_turnradius,
    CDB_TemporaryFlightPath_coursechange,
    CDB_TemporaryFlightPath_inboundcourse,
    CDB_TemporaryFlightPath_index,
    CDB_SecondaryFlightPath_lat,
    CDB_SecondaryFlightPath_long,
    CDB_SecondaryFlightPath_turnradius,
    CDB_SecondaryFlightPath_coursechange,
    CDB_SecondaryFlightPath_inboundcourse,
    CDB_SecondaryFlightPath_index,
    CDB_AlternateFlightPath_lat,
    CDB_AlternateFlightPath_long,
    CDB_AlternateFlightPath_turnradius,
    CDB_AlternateFlightPath_coursechange,
    CDB_AlternateFlightPath_inboundcourse,
    CDB_AlternateFlightPath_index,
    CDB_MissedApprPath_lat,
    CDB_MissedApprPath_long,
    CDB_MissedApprPath_turnradius,
    CDB_MissedApprPath_coursechange,
    CDB_MissedApprPath_inboundcourse,
    CDB_MissedApprPath_index,
    CDB_OffsetFlightPath_lat,
    CDB_OffsetFlightPath_long,
    CDB_OffsetFlightPath_turnradius,
    CDB_OffsetFlightPath_coursechange,
    CDB_OffsetFlightPath_inboundcourse,
    CDB_OffsetFlightPath_index,
    CDB_EngineOutFlightPath_lat,
    CDB_EngineOutFlightPath_long,
    CDB_EngineOutFlightPath_turnradius,
    CDB_EngineOutFlightPath_coursechange,
    CDB_EngineOutFlightPath_inboundcourse,
    CDB_EngineOutFlightPath_index,
    CDB_DashedFlightPath_lat,
    CDB_DashedFlightPath_long,
    CDB_DashedFlightPath_turnradius,
    CDB_DashedFlightPath_coursechange,
    CDB_DashedFlightPath_inboundcourse,
    CDB_DashedFlightPath_index,
    CDB_AircraftPosition_lat,
    CDB_AircraftPosition_long,
    CDB_Holding_lat,
    CDB_Holding_long,
    CDB_Holding_side,
    CDB_Holding_azimuth,
    CDB_Holding_index,
    CDB_TunedVORDME_lat,
    CDB_TunedVORDME_long,
    CDB_TunedVORDME_index,
    CDB_TunedVORDME_text,
    CDB_TunedDME_lat,
    CDB_TunedDME_long,
    CDB_TunedDME_index,
    CDB_TunedDME_text,
    CDB_TunedVOR_lat,
    CDB_TunedVOR_long,
    CDB_TunedVOR_index,
    CDB_TunedVOR_text,
    CDB_TunedNDB_lat,
    CDB_TunedNDB_long,
    CDB_TunedNDB_index,
    CDB_TunedNDB_text,
	CDB_FlightPlan_Waypoint_Name,
	CDB_FlightPlanWPT_index,
    CDB_FlightPlanWPT_lat,
    CDB_FlightPlanWPT_long,
	CDB_FlightPlanWPT_text,
	CDB_TransitionTurnCenter_lat,
	CDB_TransitionTurnCenter_long,
	CDB_TransitionTurnBankAngle,
	CDB_FlightPlanWPT_alt,
	CDB_FlightPlanWPT_spd,
	CDB_FlightPlanWPT_originPtr,
	CDB_FlightPlan_final_turn_point_lat,
	CDB_FlightPlan_final_turn_point_lon,
	CDB_FlightPlan_initial_turn_point_lat,
	CDB_FlightPlan_initial_turn_point_lon,
	CDB_FlightPlan_turn_radius,
    CDB_ProcedureTurn_lat,
    CDB_ProcedureTurn_long,
    CDB_ProcedureTurn_side,
    CDB_ProcedureTurn_azimuth,
    CDB_ProcedureTurn_index,
    CDB_TOC1_lat,
    CDB_TOC1_long,
    CDB_TOC1_index,
    CDB_LevelOff1_lat,
    CDB_LevelOff1_long,
    CDB_LevelOff1_index,
    CDB_TOC2_lat,
    CDB_TOC2_long,
    CDB_TOC2_index,
    CDB_LevelOff2_lat,
    CDB_LevelOff2_long,
    CDB_LevelOff2_index,
    CDB_TOD2_lat,
    CDB_TOD2_long,
    CDB_TOD2_index,
    CDB_TOD1_lat,
    CDB_TOD1_long,
    CDB_TOD1_index,
    CDB_TOC3_lat,
    CDB_TOC3_long,
    CDB_TOC3_index,
    CDB_LevelOff3_lat,
    CDB_LevelOff3_long,
    CDB_LevelOff3_index,
    CDB_StartOfClimb_lat,
    CDB_StartOfClimb_long,
    CDB_StartOfClimb_index,
    CDB_Intercept2_lat,
    CDB_Intercept2_long,
    CDB_Intercept2_index,
    CDB_Intercept1_lat,
    CDB_Intercept1_long,
    CDB_Intercept1_index,
    CDB_StartOfClimb2_lat,
    CDB_StartOfClimb2_long,
    CDB_StartOfClimb2_index,
    CDB_ConstraintWPT1_lat,
    CDB_ConstraintWPT1_long,
    CDB_ConstraintWPT1_index,
    CDB_ConstraintWPT2_lat,
    CDB_ConstraintWPT2_long,
    CDB_ConstraintWPT2_index,
    CDB_ConstraintWPT3_lat,
    CDB_ConstraintWPT3_long,
    CDB_ConstraintWPT3_index,
    CDB_SpeedChangeWPT_lat,
    CDB_SpeedChangeWPT_long,
    CDB_SpeedChangeWPT_index,
    CDB_SpeedChangeWPT_text,
    CDB_SpeedLimitWPT_lat,
    CDB_SpeedLimitWPT_long,
    CDB_SpeedLimitWPT_index,
    CDB_DecelerationWPT_lat,
    CDB_DecelerationWPT_long,
    CDB_DecelerationWPT_index,
    CDB_Timemarker_lat,
    CDB_Timemarker_long,
    CDB_Timemarker_index,
    CDB_Timemarker_text,
    CDB_OriginDestAirport_lat,
    CDB_OriginDestAirport_long,
    CDB_OriginDestAirport_index,
    CDB_OriginDestAirport_text,
    CDB_Runway_lat,
    CDB_Runway_long,
    CDB_Runway_azimuth,
    CDB_Runway_length,
    CDB_Runway_index,
    CDB_Runway_text,
    CDB_TurnSymbol_lat,
    CDB_TurnSymbol_long,
    CDB_TurnSymbol_side,
    CDB_TurnSymbol_azimuth,
    CDB_TurnSymbol_index,
    CDB_Radial_lat,
    CDB_Radial_long,
    CDB_Radial_index,
    CDB_ActiveWPT_lat,
    CDB_ActiveWPT_long,
    CDB_ActiveWPT_index,
    CDB_ActiveWPT_text,
    CDB_EFIS_WPTs_lat,
    CDB_EFIS_WPTs_long,
    CDB_EFIS_WPTs_index,
    CDB_EFIS_WPTs_text,
    CDB_EFIS_VORs_lat,
    CDB_EFIS_VORs_long,
    CDB_EFIS_VORs_index,
    CDB_EFIS_VORs_text,
    CDB_EFIS_DMEs_lat,
    CDB_EFIS_DMEs_long,
    CDB_EFIS_DMEs_index,
    CDB_EFIS_DMEs_text,
    CDB_EFIS_NDBs_lat,
    CDB_EFIS_NDBs_long,
    CDB_EFIS_NDBs_index,
    CDB_EFIS_NDBs_text,
    CDB_EFIS_VORDMEs_lat,
    CDB_EFIS_VORDMEs_long,
    CDB_EFIS_VORDMEs_index,
    CDB_EFIS_VORDMEs_text,
    CDB_EFIS_Airports_lat,
    CDB_EFIS_Airports_long,
    CDB_EFIS_Airports_index,
    CDB_EFIS_Airports_text,
    CDB_DistanceToLand_lat,
    CDB_DistanceToLand_long,
    CDB_DistanceToLand_radius,
    CDB_DistanceToLand_index,
    CDB_FMC_tuned_VOR_lat,
    CDB_FMC_tuned_VOR_long,
    CDB_FMC_tuned_VOR_text,
    CDB_FMC_tuned_NDB_lat,
    CDB_FMC_tuned_NDB_long,
    CDB_FMC_tuned_NDB_text,
    CDB_TCAS_AC_lat,
    CDB_TCAS_AC_long,
    CDB_TCAS_AC_altitude,
    CDB_TCAS_AC_verticalspeed,
    CDB_TCAS_AC_index,
    CDB_TCAS_AC_heading,
    CDB_TCAS_AC_speed,
    //ANGEL PFD
    CDB_ILS_LOC_STATUS,
    CDB_ILS_LOC_INDICATION_STATUS,
    CDB_LAT_MODE,
    CDB_LOC_MODE,
    CDB_LONG_ARMED_MODE_STATE,
    CDB_VERT_ARMED2_MODE,
    CDB_AP_COM_MODE,
    CDB_VERT_MODE,
    CDB_TCAS_RA_TO_DISPLAY_STATE,
    CDB_ILS_GS_SCALE,
    CDB_VDEV_SCALE,
    CDB_APP_CAP_CAT,
	CDB_APP_AP_SIDU,
    CDB_APP_DHMDH,
    CDB_FD_ROLL_NA,
    CDB_FD_PITCH_NA,
    CDB_ATHR_MODES,
    CDB_DME_STATUS,
    CDB_ILS_IDENT,
    CDB_ILS_IDENT_FLAG,
    CDB_ILS_FAIL_FLAG,
    CDB_ILS_FREQ_FLAG,
    CDB_VC_TREND_DISPLAY,
    CDB_VC_TREND_UP_DOWN,
    CDB_VFEN_DISPLAY,
    CDB_VMAN_DISPLAY,
    CDB_V4_DISPLAY,
    CDB_V3_DISPLAY,
    CDB_VMAX_DISPLAY,
    CDB_VLS_DISPLAY,
    CDB_VAPRO_DISPLAY,
    CDB_VALIM_DISPLAY,
    CDB_FCU_SEL_STD_DISPL,
    CDB_PRESS_UNIT,
    CDB_RA_DISPLAY,
    CDB_RA_DH_DISPLAY,
    CDB_FMA_MSG_DISPLAY,
    CDB_FMA_MSG_TEXT,
    CDB_FMA_MSG_COLOR,
    CDB_TRK_DISPLAY,
    CDB_ILS_COURSE_DISPLAY,
    CDB_ILS_COURSE_DISPLAY_LEFT,
    CDB_ILS_COURSE_DISPLAY_RIGHT,
    CDB_FMA_FLX_TEMP,
    CDB_FMA_FLIGHT_PATH_ANGLE,
    CDB_FMA_VERTICAL_SPEED,
    CDB_ILS_AMBER_MESSAGE_FLAG,
    CDB_ILS_MARKER,
    CDB_FMA_DH_READOUT,
    CDB_SEL_HDG_IDX,
    CDB_RH_DISPLAY,
    CDB_VDEV_DISPLAY,
    CDB_DES_SPEED_HIGH_DISPLAY,
    CDB_DES_SPEED_LOW_DISPLAY,
    CDB_GROUND_INDICATIONS_DISPLAY,
    CDB_FD_YAW_BAR_DISPLAY,
    CDB_FPV_DISPLAY,
    CDB_AP_FRAME,
    CDB_AT_FRAME,
    CDB_FD_FRAME,
    CDB_AT_MODE1_FRAME,
    CDB_AT_MODE2_FRAME,
    CDB_APVERT_ACT_FRAME,
    CDB_APLAT_ACT_FRAME,
    CDB_APLAT_ARMED_FRAME,
    CDB_APVERT_ARMED_FRAME,
    CDB_AP_COM_FRAME,
    CDB_CAT_FRAME,
    CDB_SIDU_FRAME,
    CDB_DHMDH_FRAME,
    CDB_CHECK_ALT_FLAG_DISPLAY,
    CDB_ALT_MARK1_DISPLAY,
    CDB_ALT_MARK2_DISPLAY,
    CDB_ALT_MARK3_DISPLAY,
    CDB_FMA_MDAMDH_DISPLAY,
    CDB_ATH_MODE,
    CDB_ATH_LEV_MODE,
    CDB_METRIC_ALTITUDE_DISPLAY,
    CDB_CURRENT_AC_FLIGHT_PHASE,
    CDB_MACH_STATUS,
    CDB_DEPARTURE_ICAO_CODE,
    CDB_DEPARTURE_RWY_CODE,
    CDB_ARRIVAL_ICAO_CODE,
    CDB_ARRIVAL_RWY_CODE,
	


	// SAMI ND A330											!!!!!!!   NEU HINZUGEFUEGT
	CDB_ECP_ND_PAGE_KNOB,
	CDB_DME_RANGE,
	CDB_ILS_APP,
	CDB_GROUND_SPEED,
	CDB_TRUE_AIRSPEED,
	CDB_WIND_DIRECTION,
	CDB_WIND_SPEED,
	CDB_VOR_FREQUENCY,
	CDB_VOR_BEARING,
	CDB_VOR_SELECTED_COURSE,
	CDB_VOR_GROUND_STATION_ID,
	CDB_VOR_VALIDITY,
	CDB_DME_FREQUENCY,
	CDB_DME_DISTANCE,
	CDB_DME_VALIDITY,
	CDB_ILS_FREQUENCY,
	CDB_ILS_LOC_DEVIATION,
	CDB_ILS_COURSE_SELECTED,
	CDB_ILS_GROUND_STATION_ID,
	CDB_ILS_VALIDITY,
	CDB_MLS_RUNWAY_HEADING,
	CDB_MLS_LOC_DEVIATION,
	CDB_MLS_CHANNEL,
	CDB_MLS_GROUND_STATION_ID,
	CDB_MLS_VALIDITY,
	CDB_RADIO_HEIGHT,
	CDB_RADIO_ALT_VALIDITY,
	CDB_ECP_VORNDB_SWL,	
	CDB_ECP_VORNDB_SWR,	
	CDB_FCU_SEL_ALT_DISPL,
	CDB_MCDU_LEG_LNG,
	CDB_MCDU_LEG_TRK,
	

	


	// END SAMI ND A330										!!!!!!!   ENDE NEU HINZUGEFUEGT


    ARRAYLABELS_MAX_N //indicates the total number of labels - always the last element
} ARRAYLABEL;

   

typedef enum //defining SINGLELABEL enum, which assigns an id-number for each label
{
    CDBs_FMS1_avail = 0,
    CDBs_FMS2_avail,
    CDBs_TrueNorthSelected,
    //ANGEL PFD
    CDBs_FE1_VALID,
    CDBs_FE2_VALID,
    CDBs_FD1_ENGAGED,
    CDBs_FD2_ENGAGED,
    CDBs_PRED_WS_OFF,
    //CDBs_FWC_FLIGHT_PHASE,
    CDBs_CAPT_EFIS_ON_DMC1,
    CDBs_FO_EFIS_ON_DMC1,
    CDBs_CAPT_EFIS_ON_DMC2,
    CDBs_FO_EFIS_ON_DMC2,
    CDBs_CAPT_EFIS_ON_DMC3,
    CDBs_FO_EFIS_ON_DMC3,
    CDBs_FE1_FAIL,
    CDBs_FE2_FAIL,
    CDBs_FD1_FAIL,
    CDBs_FD2_FAIL,
    CDBs_WINDSHEAR_SYSTEM_FAIL,
    CDBs_AP_FD_FPA_ERROR,
    CDBs_DMC1_EFIS_FAIL,
    CDBs_DMC2_EFIS_FAIL,
    CDBs_DMC3_EFIS_FAIL,
    CDBs_DME1_FAIL,
    CDBs_DME2_FAIL,
    CDBs_ILS1_FAIL,
    CDBs_ILS2_FAIL,
    CDBs_LOC1_FAIL,
    CDBs_LOC2_FAIL,
    CDBs_GS1_FAIL,
    CDBs_GS2_FAIL,
    CDBs_RA1_FAIL,
    CDBs_RA2_FAIL,
    CDBs_TCAS_FAIL,
    CDBs_TCAS_TARA_DISPLAY_FAIL,
    CDBs_TCAS_TARA_DISPLAY_FAIL_LEFT,
    CDBs_TCAS_TARA_DISPLAY_FAIL_RIGHT,
    CDBs_TCAS_TA_ONLY,
    CDBs_TCAS_INTERNAL_FAILURE,
    CDBs_TCAS_RA_FAILURE,
    CDBs_FM1_FAIL,
    CDBs_FM2_FAIL,
    CDBs_ENG1_FAIL,
    CDBs_ENG2_FAIL,
    CDBs_WINDSHEAR_WARNING,
    CDBs_TCAS_RA_CORRECTIVE,
    CDBs_TCAS_RA_PREVENTIVE,
    CDBs_TCAS_ADVISORY_TRAFIC_ALERT,
    CDBs_TCAS_WARNING_OR_VALID_OUTPUT,
    CDBs_TCAS_WINDSHEAR_INHIBIT,
    CDBs_TCAS_COMPLEMENT_MSG,
    CDBs_CHECK_PFD2_MSG_ACTIVE,
    CDBs_CHECK_PFD1_MSG_ACTIVE,
    CDBs_CHECK_PFD_MSG_ACTIVE,
    CDBs_AIRFIELD_ELEVATION,
    CDBs_FCU_METRIC_PB,
    // added changes for TEST
    //CDBs_DIST_AC_END_RWY,
    //CDBs_X_DIST_FROM_END_RWY,
    //CDBs_Y_DIST_FROM_END_RWY,
    //CDBs_X_DIST_TDZ_RWY,
    //CDBs_Y_DIST_TDZ_RWY,
    CDBs_DIST_TDZ,
    CDBs_OPTIMUM_ALTITUDE,
    CDBs_VERT_DEV_GP_FT,
    CDBs_VERT_DEV_GP_DOT,
    CDBs_LAT_DEV_FT,
    CDBs_LAT_DEV_DOT,
    CDBs_LOC_TWO_DOT,
    CDBs_LOC_ONE_DOT,
    CDBs_LOC_HALF_DOT,
    CDBs_GS_TWO_DOT,
    CDBs_GS_ONE_DOT,
    CDBs_GS_HALF_DOT,
    CDBs_BOUNDARY_FLAG,

	CDBs_fpln_end_of_predictions,
	CDBs_FROM_waypoint,
	CDBs_TO_waypoint,
	CDBs_NEXT_waypoint,
	CDBs_FOLLOWING_waypoint,
	CDBs_DESTINATION_waypoint,
	CDBs_END_waypoint,
	CDBs_AP_disc_capt,
	CDBs_Mag_Heading,
	CDBs_ILS_DME_Dez,
	CDBs_Dist_Dest,
	CDBs_Dist_TO,
	CDBs_SpeedScale_Pos,
	
	// SAMI ND A330											!!!!!!!   NEU HINZUGEFUEGT
	CDBs_HEADING_REFERENCE_TRUE,
	CDBs_VOR1_SELECTION,
	CDBs_VOR2_SELECTION,
	CDBs_ADF1_SELECTION,
	CDBs_ADF2_SELECTION,
	CDBs_VOR1_TUNING_MODE,
	CDBs_VOR2_TUNING_MODE,
	CDBs_ADF1_TUNING_MODE,
	CDBs_ADF2_TUNING_MODE,
	CDBs_VOR1_ID,
	CDBs_VOR2_ID,
	CDB_FCU_AP1PBLT,
	CDB_FCU_AP2PBLT,
	HARDWARE_ONLINE,

	CDB_BAT_1,
	CDB_BAT_2,
	CDB_BAT_A,
	CDB_RIGHT_GEAR_ONGROUND,
	CDB_LEFT_GEAR_ONGROUND,
	CDB_NOSE_GEAR_ONGROUND,
	CDB_NOSMOK_ON,
	CDB_FASTSB_ON,
	CDB_APU_FIRE_TEST,
	CDB_ENG_FIRE_TEST,
	CDB_FLIGHT_FREEZE,

	// END SAMI ND A330										!!!!!!!   ENDE NEU HINZUGEFUEGT
	//FCU  LABELS A330
	CDB_FCU_LOC_REQ,
	CDB_FCU_ALT_REQ,
	CDB_FCU_APPR_REQ,
	CDB_FCU_AP1_REQ,
	CDB_FCU_AP2_REQ,
	CDB_FCU_ATHR_REQ,
	CDB_FCU_FD1_REQ,
	CDB_FCU_LS1_REQ,
	CDB_FCU_CSTR1_REQ,
	CDB_FCU_WPT1_REQ,
	CDB_FCU_VORD1_REQ,
	CDB_FCU_NDB1_REQ,
	CDB_FCU_ARPT1_REQ,
	CDB_FCU_FD2_REQ,
	CDB_FCU_LS2_REQ,
	CDB_FCU_CSTR2_REQ,
	CDB_FCU_WPT2_REQ,
	CDB_FCU_VORD2_REQ,
	CDB_FCU_NDB2_REQ,
	CDB_FCU_ARPT2_REQ,

	CDB_FCU_LOC_STATUS,
	CDB_FCU_ALT_STATUS,
	CDB_FCU_APPR_STATUS,
	CDB_FCU_ATHR_STATUS,
	CDB_FCU_FD1_STATUS,
	CDB_FCU_LS1_STATUS,
	CDB_FCU_CSTR1_STATUS,
	CDB_FCU_WPT1_STATUS,
	CDB_FCU_VORD1_STATUS,
	CDB_FCU_NDB1_STATUS,
	CDB_FCU_ARPT1_STATUS,
	CDB_FCU_FD2_STATUS,
	CDB_FCU_LS2_STATUS,
	CDB_FCU_CSTR2_STATUS,
	CDB_FCU_WPT2_STATUS,
	CDB_FCU_VORD2_STATUS,
	CDB_FCU_NDB2_STATUS,
	CDB_FCU_ARPT2_STATUS,

	CDB_FCU_SPD_DISP,
	CDB_FCU_SPD_DISP_STATUS,
	CDB_FCU_SPD_DOT_STATUS,
	CDB_FCU_SPDMA_STATUS,
	CDB_FCU_SPD_I_STATUS,
	CDB_FCU_SPD_O_STATUS,

	CDB_FCU_HDG_DISP,
	CDB_FCU_HDG_DISP_STATUS,
	CDB_FCU_HDG_DOT_STATUS,
	CDB_FCU_HDGTRK_STATUS,
	CDB_FCU_HDG_I_STATUS,
	CDB_FCU_HDG_O_STATUS,
	CDB_FCU_HDG_VS_SEL,

	CDB_FCU_ALT_DISP,
	CDB_FCU_ALT_DOT_STATUS,
	CDB_FCU_ALT_I_STATUS,
	CDB_FCU_ALT_O_STATUS,

	CDB_FCU_VS_DISP,
	CDB_FCU_VSF_DISP_STATUS,
	CDB_FCU_VS_I_STATUS,
	CDB_FCU_VS_O_STATUS,

	CDB_ECPL_QNHDISP,
	CDB_ECPL_QNHSTD,
	CDB_ECPL_QNHMODE,
	CDB_ECPL_I_STATUS,
	CDB_ECPL_O_STATUS,

	CDB_ECPR_QNHDISP,
	CDB_ECPR_QNHSTD,
	CDB_ECPR_QNHMODE,
	CDB_ECPR_I_STATUS,
	CDB_ECPR_O_STATUS,

	CDB_FCU_SWITCH_L1,
	CDB_FCU_SWITCH_L2,
	CDB_FCU_SWITCH_R1,
	CDB_FCU_SWITCH_R2,

	CDB_FCU_SELECTOR_L1,
	CDB_FCU_SELECTOR_L2,
	CDB_FCU_SELECTOR_R1,
	CDB_FCU_SELECTOR_R2,

	CDB_IOS_REPOS,
	CDB_IOS_REPOS_PROGRESS,

    SINGLELABELS_MAX_N //indicates the total number of labels - always the last element
} SINGLELABEL;

inline void defineLabels(TCPIP &cTcp) //definition of label names
{
    //define Array-Labels
    cTcp.iALCounter = ARRAYLABELS_MAX_N; //number of labels to be read
    strcpy_s(cTcp.ArrayLabel[CDB_PlanMode_on]							, "qelplnmod"	);
    strcpy_s(cTcp.ArrayLabel[CDB_AC_TrueTrack]						, "qemhdg"		);
    strcpy_s(cTcp.ArrayLabel[CDB_MapReference_lat]					, "qfemrplat"	);
    strcpy_s(cTcp.ArrayLabel[CDB_MapReference_long]					, "qfemrplon"	);
	strcpy_s(cTcp.ArrayLabel[CDB_IRS_AC_TrueHeading]					, "rnpsi"		);
	strcpy_s(cTcp.ArrayLabel[CDB_AC_MagVAR]						    , "qflacmva"	);
	strcpy_s(cTcp.ArrayLabel[CDB_AC_drift]							, "qfldrifta"	);
	strcpy_s(cTcp.ArrayLabel[CDB_AC_altitude]							, "rnalt"		);
	strcpy_s(cTcp.ArrayLabel[CDB_ND_Range]							, "qemrng"		);
	strcpy_s(cTcp.ArrayLabel[CDB_ND_Page]								, "qempage"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TO_Ident]							, "lmatvwpt"	);
	strcpy_s(cTcp.ArrayLabel[CDB_TO_TrackDistance]					, "qfltkdis"	);
	strcpy_s(cTcp.ArrayLabel[CDB_TO_Track]							, "qflbrgto"	);
	strcpy_s(cTcp.ArrayLabel[CDB_TO_Time]								, "qfltimto"	);
	strcpy_s(cTcp.ArrayLabel[CDB_ClockTime]							, "qficktim"	);
	strcpy_s(cTcp.ArrayLabel[CDB_CrossTrackError]						, "qflxtrk"		);
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_lat]			, "lmafplat"	);
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_long]          , "lmafplng"		);
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_turnradius]    , "lmafptr"		);
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_coursechange]  , "lmafpcc"		);
	strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_inboundcourse] , "lmafpic"		);
	strcpy_s(cTcp.ArrayLabel[CDB_ActiveFlightPlanPath_index]         , "lmafpidx"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_lat]            , "lmpfplat"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_long]           , "lmpfplng"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_turnradius]     , "lmpfptr"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_coursechange]   , "lmpfpcc"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_inboundcourse]  , "lmpfpic"		);
	strcpy_s(cTcp.ArrayLabel[CDB_TemporaryFlightPath_index]          , "lmpfpidx"		);
	strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_lat]            , "lmsfplat"		);
	strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_long]           , "lmsfplng"		);
	strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_turnradius]     , "lmsfptr"		);
	strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_coursechange]   , "lmsfpcc"		);
	strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_inboundcourse]  , "lmsfpic");
    strcpy_s(cTcp.ArrayLabel[CDB_SecondaryFlightPath_index]          , "lmsfpidx");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_lat]            , "lmaltlat");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_long]           , "lmaltlng");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_turnradius]     , "lmalttr");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_coursechange]   , "lmaltcc");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_inboundcourse]  , "lmaltic");
    strcpy_s(cTcp.ArrayLabel[CDB_AlternateFlightPath_index]          , "lmaltidx");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_lat]                 , "lmmstlat");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_long]                , "lmmstlng");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_turnradius]          , "lmmsttr");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_coursechange]        , "lmmstcc");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_inboundcourse]       , "lmmstic");
    strcpy_s(cTcp.ArrayLabel[CDB_MissedApprPath_index]               , "lmmstidx");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_lat]               , "lmofflat");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_long]              , "lmofflng");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_turnradius]        , "lmofftr");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_coursechange]      , "lmoffcc");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_inboundcourse]     , "lmoffic");
    strcpy_s(cTcp.ArrayLabel[CDB_OffsetFlightPath_index]             , "lmoffidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_lat]            , "lmenglat");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_long]           , "lmenglng");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_turnradius]     , "lmengtr");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_coursechange]   , "lmengcc");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_inboundcourse]  , "lmengic");
    strcpy_s(cTcp.ArrayLabel[CDB_EngineOutFlightPath_index]          , "lmengidx");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_lat]               , "lmdshlat");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_long]              , "lmdshlng");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_turnradius]        , "lmdshtr");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_coursechange]      , "lmdshcc");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_inboundcourse]     , "lmdshic");
    strcpy_s(cTcp.ArrayLabel[CDB_DashedFlightPath_index]             , "lmdshidx");
    strcpy_s(cTcp.ArrayLabel[CDB_AircraftPosition_lat]               , "qemrlat");
    strcpy_s(cTcp.ArrayLabel[CDB_AircraftPosition_long]              , "qemrlng");
    strcpy_s(cTcp.ArrayLabel[CDB_Holding_lat]                        , "lmhldlat");
    strcpy_s(cTcp.ArrayLabel[CDB_Holding_long]                       , "lmhldlng");
    strcpy_s(cTcp.ArrayLabel[CDB_Holding_side]                       , "lmhldsde");
    strcpy_s(cTcp.ArrayLabel[CDB_Holding_azimuth]                    , "lmhldazm");
    strcpy_s(cTcp.ArrayLabel[CDB_Holding_index]                      , "lmhldidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVORDME_lat]                    , "lmtvtlat");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVORDME_long]                   , "lmtvtlng");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVORDME_index]                  , "lmtvtidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVORDME_text]                   , "lmtvttxt");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedDME_lat]                       , "lmtdmlat");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedDME_long]                      , "lmtdmlng");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedDME_index]                     , "lmtdmidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedDME_text]                      , "lmtdmtxt");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVOR_lat]                       , "lmtvolat");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVOR_long]                      , "lmtvolng");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVOR_index]                     , "lmtvoidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedVOR_text]                      , "lmtvotxt");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedNDB_lat]                       , "lmtndlat");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedNDB_long]                      , "lmtndlng");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedNDB_index]                     , "lmtndidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TunedNDB_text]                      , "lmtndtxt");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_Waypoint_Name]		   , "qfpwpidt");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_index]                , "qfpidx");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_lat]                  , "qfpwplat");
    strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_long]                 , "qfpwplon");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_text]			    	, "lmfpwtxt");
    strcpy_s(cTcp.ArrayLabel[CDB_TransitionTurnCenter_long]          , "qfltrclo");
	strcpy_s(cTcp.ArrayLabel[CDB_TransitionTurnCenter_lat]           , "qfltrcla");
	strcpy_s(cTcp.ArrayLabel[CDB_TransitionTurnBankAngle]            , "qfltrbnk");
    strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_alt]                  , "qfpalt");
    strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_spd]                  , "qfpspd");
    strcpy_s(cTcp.ArrayLabel[CDB_FlightPlanWPT_originPtr]            , "qfpoptr");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_final_turn_point_lat]    , "QFLTRFLA");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_final_turn_point_lon]    , "QFLTRFLO");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_initial_turn_point_lat]  , "QFLTRILA");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_initial_turn_point_lon]  , "QFLTRILO");
	strcpy_s(cTcp.ArrayLabel[CDB_FlightPlan_turn_radius]				, "QFLTRRAD");
    strcpy_s(cTcp.ArrayLabel[CDB_ProcedureTurn_lat]                  , "lmptnlat");
    strcpy_s(cTcp.ArrayLabel[CDB_ProcedureTurn_long]                 , "lmptnlng");
    strcpy_s(cTcp.ArrayLabel[CDB_ProcedureTurn_side]                 , "lmptnsde");
    strcpy_s(cTcp.ArrayLabel[CDB_ProcedureTurn_azimuth]              , "lmptnazm");
    strcpy_s(cTcp.ArrayLabel[CDB_ProcedureTurn_index]                , "lmptnidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC1_lat]                           , "lmaialat");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC1_long]                          , "lmaialng");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC1_index]                         , "lmaiaidx");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff1_lat]                      , "lmaiblat");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff1_long]                     , "lmaiblng");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff1_index]                    , "lmaibidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC2_lat]                           , "lmaiclat");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC2_long]                          , "lmaiclng");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC2_index]                         , "lmaicidx");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff2_lat]                      , "lmaidlat");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff2_long]                     , "lmaidlng");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff2_index]                    , "lmaididx");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD2_lat]                           , "lmaielat");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD2_long]                          , "lmaielng");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD2_index]                         , "lmaieidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD1_lat]                           , "lmaiflat");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD1_long]                          , "lmaiflng");
    strcpy_s(cTcp.ArrayLabel[CDB_TOD1_index]                         , "lmaifidx");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC3_lat]                           , "lmaiglat");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC3_long]                          , "lmaiglng");
    strcpy_s(cTcp.ArrayLabel[CDB_TOC3_index]                         , "lmaigidx");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff3_lat]                      , "lmaihlat");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff3_long]                     , "lmaihlng");
    strcpy_s(cTcp.ArrayLabel[CDB_LevelOff3_index]                    , "lmaihidx");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb_lat]                   , "lmaiilat");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb_long]                  , "lmaiilng");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb_index]                 , "lmaiiidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept2_lat]                     , "lmaijlat");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept2_long]                    , "lmaijlng");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept2_index]                   , "lmaijidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept1_lat]                     , "lmaiklat");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept1_long]                    , "lmaiklng");
    strcpy_s(cTcp.ArrayLabel[CDB_Intercept1_index]                   , "lmaikidx");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb2_lat]                  , "lmaillat");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb2_long]                 , "lmaillng");
    strcpy_s(cTcp.ArrayLabel[CDB_StartOfClimb2_index]                , "lmailidx");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT1_lat]                 , "lmaimlat");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT1_long]                , "lmaimlng");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT1_index]               , "lmaimidx");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT2_lat]                 , "lmainlat");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT2_long]                , "lmainlng");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT2_index]               , "lmainidx");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT3_lat]                 , "lmaiolat");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT3_long]                , "lmaiolng");
    strcpy_s(cTcp.ArrayLabel[CDB_ConstraintWPT3_index]               , "lmaioidx");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedChangeWPT_lat]                 , "lmaiplat");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedChangeWPT_long]                , "lmaiplng");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedChangeWPT_index]               , "lmaipidx");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedChangeWPT_text]                , "lmaiptxt");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedLimitWPT_lat]                  , "lmaiqlat");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedLimitWPT_long]                 , "lmaiqlng");
    strcpy_s(cTcp.ArrayLabel[CDB_SpeedLimitWPT_index]                , "lmaiqidx");
    strcpy_s(cTcp.ArrayLabel[CDB_DecelerationWPT_lat]                , "lmairlat");
    strcpy_s(cTcp.ArrayLabel[CDB_DecelerationWPT_long]               , "lmairlng");
    strcpy_s(cTcp.ArrayLabel[CDB_DecelerationWPT_index]              , "lmairidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Timemarker_lat]                     , "lmaitlat");
    strcpy_s(cTcp.ArrayLabel[CDB_Timemarker_long]                    , "lmaitlng");
    strcpy_s(cTcp.ArrayLabel[CDB_Timemarker_index]                   , "lmaitidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Timemarker_text]                    , "lmaittxt");
    strcpy_s(cTcp.ArrayLabel[CDB_OriginDestAirport_lat]              , "lmodalat");
    strcpy_s(cTcp.ArrayLabel[CDB_OriginDestAirport_long]             , "lmodalng");
    strcpy_s(cTcp.ArrayLabel[CDB_OriginDestAirport_index]            , "lmodaidx");
    strcpy_s(cTcp.ArrayLabel[CDB_OriginDestAirport_text]             , "lmodatxt");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_lat]                         , "lmrwylat");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_long]                        , "lmrwylng");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_azimuth]                     , "lmrwyazm");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_length]                      , "lmrwylth");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_index]                       , "lmrwyidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Runway_text]                        , "lmrwytxt");
    strcpy_s(cTcp.ArrayLabel[CDB_TurnSymbol_lat]                     , "lmtrnlat");
    strcpy_s(cTcp.ArrayLabel[CDB_TurnSymbol_long]                    , "lmtrnlng");
    strcpy_s(cTcp.ArrayLabel[CDB_TurnSymbol_side]                    , "lmtrnsde");
    strcpy_s(cTcp.ArrayLabel[CDB_TurnSymbol_azimuth]                 , "lmtrnazm");
    strcpy_s(cTcp.ArrayLabel[CDB_TurnSymbol_index]                   , "lmtrnidx");
    strcpy_s(cTcp.ArrayLabel[CDB_Radial_lat]                         , "lmarvlat");
    strcpy_s(cTcp.ArrayLabel[CDB_Radial_long]                        , "lmarvlng");
    strcpy_s(cTcp.ArrayLabel[CDB_Radial_index]                       , "lmarvidx");
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveWPT_lat]                      , "lmawplat");
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveWPT_long]                     , "lmawplng");
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveWPT_index]                    , "lmawpidx");
    strcpy_s(cTcp.ArrayLabel[CDB_ActiveWPT_text]                     , "lmawptxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_WPTs_lat]                      , "lmgeolat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_WPTs_long]                     , "lmgeolng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_WPTs_index]                    , "lmgeoidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_WPTs_text]                     , "lmgeotxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORs_lat]                      , "lmvorlat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORs_long]                     , "lmvorlng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORs_index]                    , "lmvoridx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORs_text]                     , "lmvortxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_DMEs_lat]                      , "lmdmelat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_DMEs_long]                     , "lmdmelng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_DMEs_index]                    , "lmdmeidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_DMEs_text]                     , "lmdmetxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_NDBs_lat]                      , "lmndblat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_NDBs_long]                     , "lmndblng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_NDBs_index]                    , "lmndbidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_NDBs_text]                     , "lmndbtxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORDMEs_lat]                   , "lmvtclat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORDMEs_long]                  , "lmvtclng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORDMEs_index]                 , "lmvtcidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_VORDMEs_text]                  , "lmvtctxt");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_Airports_lat]                  , "lmarplat");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_Airports_long]                 , "lmarplng");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_Airports_index]                , "lmarpidx");
    strcpy_s(cTcp.ArrayLabel[CDB_EFIS_Airports_text]                 , "lmarptxt");
    strcpy_s(cTcp.ArrayLabel[CDB_DistanceToLand_lat]                 , "lmaislat");
    strcpy_s(cTcp.ArrayLabel[CDB_DistanceToLand_long]                , "lmaislng");
    strcpy_s(cTcp.ArrayLabel[CDB_DistanceToLand_radius]              , "lmaisrad");
    strcpy_s(cTcp.ArrayLabel[CDB_DistanceToLand_index]               , "lmaisidx");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_VOR_lat]                  , "qfrovrlt");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_VOR_long]                 , "qfrovrln");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_VOR_text]                 , "qfrovri");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_NDB_lat]                  , "qfroadlt");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_NDB_long]                 , "qfroadln");
    strcpy_s(cTcp.ArrayLabel[CDB_FMC_tuned_NDB_text]                 , "qfroadi");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_lat]                        , "vstlat");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_long]                       , "vstlon");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_altitude]                   , "vstalt");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_verticalspeed]              , "vstaltr");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_index]                      , "tatcnac");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_heading]                    , "vsthdg");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_AC_speed]                      , "vstspd");
	//ANGEL PFD
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_LOC_STATUS]                     , "qesf3lsloc");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_LOC_INDICATION_STATUS]          , "qesf4loci");
    strcpy_s(cTcp.ArrayLabel[CDB_LAT_MODE]                           , "qesfxlatem");
    strcpy_s(cTcp.ArrayLabel[CDB_LOC_MODE]                           , "qesfxlarmm");
    strcpy_s(cTcp.ArrayLabel[CDB_LONG_ARMED_MODE_STATE]              , "qesfxloarm");
    strcpy_s(cTcp.ArrayLabel[CDB_VERT_ARMED2_MODE]                   , "qesfxvcmch");
    strcpy_s(cTcp.ArrayLabel[CDB_AP_COM_MODE]                        , "qesfxlolam");
    strcpy_s(cTcp.ArrayLabel[CDB_VERT_MODE]                          , "qesfxloaem");
    strcpy_s(cTcp.ArrayLabel[CDB_TCAS_RA_TO_DISPLAY_STATE]           , "qesf3fcvsp");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_GS_SCALE]                       , "qesf3glssc");
    strcpy_s(cTcp.ArrayLabel[CDB_VDEV_SCALE]                         , "qesf3vdsc");
    strcpy_s(cTcp.ArrayLabel[CDB_APP_CAP_CAT]                        , "qes_cat_nb");
    strcpy_s(cTcp.ArrayLabel[CDB_APP_AP_SIDU]                        , "qesfxsgldl");
    strcpy_s(cTcp.ArrayLabel[CDB_APP_DHMDH]                          , "qesfxmdhaa");
    strcpy_s(cTcp.ArrayLabel[CDB_FD_ROLL_NA]                         , "qelnafdrol");
    strcpy_s(cTcp.ArrayLabel[CDB_FD_PITCH_NA]                        , "qelnafdpit");
    strcpy_s(cTcp.ArrayLabel[CDB_ATHR_MODES]                         , "qelnmchfma");
    strcpy_s(cTcp.ArrayLabel[CDB_DME_STATUS]                         , "qjsf4dmed");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_IDENT]                          , "qjmailsid");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_IDENT_FLAG]                     , "qjlndiid");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_FAIL_FLAG]                      , "qjlnailsfl");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_FREQ_FLAG]                      , "qjlndilsfr");
    strcpy_s(cTcp.ArrayLabel[CDB_VC_TREND_DISPLAY]                   , "qjlndvtren");
    strcpy_s(cTcp.ArrayLabel[CDB_VC_TREND_UP_DOWN]                   , "qjlf2trend");
    strcpy_s(cTcp.ArrayLabel[CDB_VFEN_DISPLAY]                       , "qjlndvnext");
    strcpy_s(cTcp.ArrayLabel[CDB_VMAN_DISPLAY]                       , "qjlndvman");
    strcpy_s(cTcp.ArrayLabel[CDB_V4_DISPLAY]                         , "qjlndvslat");
    strcpy_s(cTcp.ArrayLabel[CDB_V3_DISPLAY]                         , "qjlndvflap");
    strcpy_s(cTcp.ArrayLabel[CDB_VMAX_DISPLAY]                       , "qjlnavmax");
    strcpy_s(cTcp.ArrayLabel[CDB_VLS_DISPLAY]                        , "qjslavls");
    strcpy_s(cTcp.ArrayLabel[CDB_VAPRO_DISPLAY]                      , "qjsf3vapro");
    strcpy_s(cTcp.ArrayLabel[CDB_VALIM_DISPLAY]                      , "qjlnavalim");
    strcpy_s(cTcp.ArrayLabel[CDB_FCU_SEL_STD_DISPL]                          , "qjsf4mode");
    strcpy_s(cTcp.ArrayLabel[CDB_PRESS_UNIT]                         , "qjsf3cor");
    strcpy_s(cTcp.ArrayLabel[CDB_RA_DISPLAY]                         , "qji3radisp");
    strcpy_s(cTcp.ArrayLabel[CDB_RA_DH_DISPLAY]                      , "qjldhattds");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_MSG_DISPLAY]                    , "qjldfmamsg");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_MSG_TEXT]                       , "qjfmamsg21");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_MSG_COLOR]                      , "qjfmacolor");
    strcpy_s(cTcp.ArrayLabel[CDB_TRK_DISPLAY]                        , "qjltrkdisp");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_COURSE_DISPLAY]                 , "qjlilsdisp");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_COURSE_DISPLAY_LEFT]            , "qjlilsleft");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_COURSE_DISPLAY_RIGHT]           , "qjlilsrigt");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_FLX_TEMP]                       , "qjiaflxtmp");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_FLIGHT_PATH_ANGLE]              , "qjrafmafpa");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_VERTICAL_SPEED]                 , "qjrafmavs");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_AMBER_MESSAGE_FLAG]             , "qjlnailsms");
    strcpy_s(cTcp.ArrayLabel[CDB_ILS_MARKER]                         , "qjsf4mkri");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_DH_READOUT]                     , "qjiadhnum");
    strcpy_s(cTcp.ArrayLabel[CDB_SEL_HDG_IDX]                        , "qjlshddisp");
    strcpy_s(cTcp.ArrayLabel[CDB_RH_DISPLAY]                         , "qjlndraref");
    strcpy_s(cTcp.ArrayLabel[CDB_VDEV_DISPLAY]                       , "qjlnddevpr");
    strcpy_s(cTcp.ArrayLabel[CDB_DES_SPEED_HIGH_DISPLAY]             , "qjlnaspdmh");
    strcpy_s(cTcp.ArrayLabel[CDB_DES_SPEED_LOW_DISPLAY]              , "qjlnaspdml");
    strcpy_s(cTcp.ArrayLabel[CDB_GROUND_INDICATIONS_DISPLAY]         , "qjlgrdind");
    strcpy_s(cTcp.ArrayLabel[CDB_FD_YAW_BAR_DISPLAY]                 , "qjldfdyawb");
    strcpy_s(cTcp.ArrayLabel[CDB_FPV_DISPLAY]                        , "qjlbirdy");
    strcpy_s(cTcp.ArrayLabel[CDB_AP_FRAME]                           , "qjlapbd");
    strcpy_s(cTcp.ArrayLabel[CDB_AT_FRAME]                           , "qjlatbd");
    strcpy_s(cTcp.ArrayLabel[CDB_FD_FRAME]                           , "qjlfdbd");
    strcpy_s(cTcp.ArrayLabel[CDB_AT_MODE1_FRAME]                     , "qjlatmdbdw");
    strcpy_s(cTcp.ArrayLabel[CDB_AT_MODE2_FRAME]                     , "qjlatmdbda");
    strcpy_s(cTcp.ArrayLabel[CDB_APVERT_ACT_FRAME]                   , "qjlapamdbd");
    strcpy_s(cTcp.ArrayLabel[CDB_APLAT_ACT_FRAME]                    , "qjlapamltd");
    strcpy_s(cTcp.ArrayLabel[CDB_APLAT_ARMED_FRAME]                  , "qjlaplmarm");
    strcpy_s(cTcp.ArrayLabel[CDB_APVERT_ARMED_FRAME]                 , "qjlapvmarm");
    strcpy_s(cTcp.ArrayLabel[CDB_AP_COM_FRAME]                       , "qjlapcombd");
    strcpy_s(cTcp.ArrayLabel[CDB_CAT_FRAME]                          , "qjlcatbd");
    strcpy_s(cTcp.ArrayLabel[CDB_SIDU_FRAME]                         , "qjlsdlbd");
    strcpy_s(cTcp.ArrayLabel[CDB_DHMDH_FRAME]                        , "qjlmdhabd");
    strcpy_s(cTcp.ArrayLabel[CDB_CHECK_ALT_FLAG_DISPLAY]             , "qjlnackalt");
    strcpy_s(cTcp.ArrayLabel[CDB_ALT_MARK1_DISPLAY]                  , "qjlaltidc1");
    strcpy_s(cTcp.ArrayLabel[CDB_ALT_MARK2_DISPLAY]                  , "qjlaltidc2");
    strcpy_s(cTcp.ArrayLabel[CDB_ALT_MARK3_DISPLAY]                  , "qjlaltidc3");
    strcpy_s(cTcp.ArrayLabel[CDB_FMA_MDAMDH_DISPLAY]                 , "qjlf2mdhas");
    strcpy_s(cTcp.ArrayLabel[CDB_ATH_MODE]                           , "qesfxathem");
    strcpy_s(cTcp.ArrayLabel[CDB_ATH_LEV_MODE]                       , "qesf5za3th");
    strcpy_s(cTcp.ArrayLabel[CDB_METRIC_ALTITUDE_DISPLAY]            , "qjlaltmdsp");
    strcpy_s(cTcp.ArrayLabel[CDB_CURRENT_AC_FLIGHT_PHASE]            , "qfvfphase");
    strcpy_s(cTcp.ArrayLabel[CDB_MACH_STATUS]                        , "qjsf3mach");
    strcpy_s(cTcp.ArrayLabel[CDB_DEPARTURE_ICAO_CODE]                , "qfpfrom");
    strcpy_s(cTcp.ArrayLabel[CDB_DEPARTURE_RWY_CODE]                 , "qfpacrwy");
    strcpy_s(cTcp.ArrayLabel[CDB_ARRIVAL_ICAO_CODE]                  , "qfpto");
    strcpy_s(cTcp.ArrayLabel[CDB_ARRIVAL_RWY_CODE]                   , "tarwy2");

	// SAMI ND A330																	!!!!!!!   NEU HINZUGEFUEGT
    strcpy_s(cTcp.ArrayLabel[CDB_ECP_ND_PAGE_KNOB]				   , "ssswitch1");	
    strcpy_s(cTcp.ArrayLabel[CDB_DME_RANGE]						   , "rbrdme");	
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_APP]		      				   , "qflilssel");
	strcpy_s(cTcp.ArrayLabel[CDB_GROUND_SPEED]					   , "qfiir0gs");
	strcpy_s(cTcp.ArrayLabel[CDB_TRUE_AIRSPEED]					   , "qfiadtas");
	strcpy_s(cTcp.ArrayLabel[CDB_WIND_DIRECTION]					   , "qfiir0wndd");
	strcpy_s(cTcp.ArrayLabel[CDB_WIND_SPEED]						   , "qfiir0wnds");
	strcpy_s(cTcp.ArrayLabel[CDB_VOR_FREQUENCY]					   , "qfivrfreq");	
	strcpy_s(cTcp.ArrayLabel[CDB_VOR_BEARING]						   , "qfivrbear");	
	strcpy_s(cTcp.ArrayLabel[CDB_VOR_SELECTED_COURSE]				   , "qfivrscrs");	
	strcpy_s(cTcp.ArrayLabel[CDB_VOR_GROUND_STATION_ID]			   , "qfivridt");	
	strcpy_s(cTcp.ArrayLabel[CDB_VOR_VALIDITY]			           , "qfivor0v");
	strcpy_s(cTcp.ArrayLabel[CDB_DME_FREQUENCY]			           , "qfidmfreq");
	strcpy_s(cTcp.ArrayLabel[CDB_DME_DISTANCE]			           , "qfidmdist");
	strcpy_s(cTcp.ArrayLabel[CDB_DME_VALIDITY]			           , "qfidme0v");
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_FREQUENCY]			           , "qfiilfreq");
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_LOC_DEVIATION]			       , "qfiilocdev");
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_COURSE_SELECTED]			       , "qfiilscrs");
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_GROUND_STATION_ID]			   , "qfiilidt");
	strcpy_s(cTcp.ArrayLabel[CDB_ILS_VALIDITY]					   , "qfiils0v");
	strcpy_s(cTcp.ArrayLabel[CDB_MLS_RUNWAY_HEADING]			       , "qfimlrhdg");
	strcpy_s(cTcp.ArrayLabel[CDB_MLS_LOC_DEVIATION]			       , "qfimllocd");
	strcpy_s(cTcp.ArrayLabel[CDB_MLS_CHANNEL]					       , "qfimlchn");
	strcpy_s(cTcp.ArrayLabel[CDB_MLS_GROUND_STATION_ID]			   , "qfimlidt");
	strcpy_s(cTcp.ArrayLabel[CDB_MLS_VALIDITY]					   , "qfimls0v");
	strcpy_s(cTcp.ArrayLabel[CDB_RADIO_HEIGHT]					   , "qfirarhegt");
	strcpy_s(cTcp.ArrayLabel[CDB_RADIO_ALT_VALIDITY]	      		   , "qfirad0v");
	strcpy_s(cTcp.ArrayLabel[CDB_ECP_VORNDB_SWL]					   , "ssswitch3");
	strcpy_s(cTcp.ArrayLabel[CDB_ECP_VORNDB_SWR]					   , "ssswitch4");
	strcpy_s(cTcp.ArrayLabel[CDB_FCU_SEL_ALT_DISPL]					,"qjiaselal5");  
	strcpy_s(cTcp.ArrayLabel[CDB_MCDU_LEG_LNG]						 ,"qfplngth");
	strcpy_s(cTcp.ArrayLabel[CDB_MCDU_LEG_TRK]						 ,"qfpltrk");
	
	// END SAMI ND A330																!!!!!!!   ENDE NEU HINZUGEFUEGT


	//define Single-Element-Labels
    cTcp.iLCounter = SINGLELABELS_MAX_N; //number of labels to be read
    strcpy_s(cTcp.Label[CDBs_FMS1_avail]                             , "lw$fmav1");
    strcpy_s(cTcp.Label[CDBs_FMS2_avail]                             , "lw$fmav2");
    strcpy_s(cTcp.Label[CDBs_TrueNorthSelected]                      , "le$true1");
	//ANGEL PFD
    strcpy_s(cTcp.Label[CDBs_FE1_VALID]                              , "le$fev11");
    strcpy_s(cTcp.Label[CDBs_FE2_VALID]                              , "le$fev21");
    strcpy_s(cTcp.Label[CDBs_FD1_ENGAGED]                            , "le$fde11");
    strcpy_s(cTcp.Label[CDBs_FD2_ENGAGED]                            , "le$fde21");
    strcpy_s(cTcp.Label[CDBs_PRED_WS_OFF]                            , "le$pwof1");
    //strcpy_s(cTcp.Label[CDBs_FWC_FLIGHT_PHASE]                       , "lbfltph"); -> wird nicht initialisiert
    strcpy_s(cTcp.Label[CDBs_CAPT_EFIS_ON_DMC1]                      , "lacef1");
    strcpy_s(cTcp.Label[CDBs_FO_EFIS_ON_DMC1]                        , "lafef1");
    strcpy_s(cTcp.Label[CDBs_CAPT_EFIS_ON_DMC2]                      , "lacef2");
    strcpy_s(cTcp.Label[CDBs_FO_EFIS_ON_DMC2]                        , "lafef2");
    strcpy_s(cTcp.Label[CDBs_CAPT_EFIS_ON_DMC3]                      , "lacef3");
    strcpy_s(cTcp.Label[CDBs_FO_EFIS_ON_DMC3]                        , "lafef3");
    strcpy_s(cTcp.Label[CDBs_FE1_FAIL]                               , "tf220521");
    strcpy_s(cTcp.Label[CDBs_FE2_FAIL]                               , "tf220522");
    strcpy_s(cTcp.Label[CDBs_FD1_FAIL]                               , "tf220551");
    strcpy_s(cTcp.Label[CDBs_FD2_FAIL]                               , "tf220552");
    strcpy_s(cTcp.Label[CDBs_WINDSHEAR_SYSTEM_FAIL]                  , "tf220571");
    strcpy_s(cTcp.Label[CDBs_AP_FD_FPA_ERROR]                        , "tf220651");
    strcpy_s(cTcp.Label[CDBs_DMC1_EFIS_FAIL]                         , "tf310021");
    strcpy_s(cTcp.Label[CDBs_DMC2_EFIS_FAIL]                         , "tf310022");
    strcpy_s(cTcp.Label[CDBs_DMC3_EFIS_FAIL]                         , "tf310023");
    strcpy_s(cTcp.Label[CDBs_DME1_FAIL]                              , "tf340031");
    strcpy_s(cTcp.Label[CDBs_DME2_FAIL]                              , "tf340032");
    strcpy_s(cTcp.Label[CDBs_ILS1_FAIL]                              , "tf340041");
    strcpy_s(cTcp.Label[CDBs_ILS2_FAIL]                              , "tf340042");
    strcpy_s(cTcp.Label[CDBs_LOC1_FAIL]                              , "tf340141");
    strcpy_s(cTcp.Label[CDBs_LOC2_FAIL]                              , "tf340142");
    strcpy_s(cTcp.Label[CDBs_GS1_FAIL]                               , "tf340151");
    strcpy_s(cTcp.Label[CDBs_GS2_FAIL]                               , "tf340152");
    strcpy_s(cTcp.Label[CDBs_RA1_FAIL]                               , "tf34a051");
    strcpy_s(cTcp.Label[CDBs_RA2_FAIL]                               , "tf34a052");
    strcpy_s(cTcp.Label[CDBs_TCAS_FAIL]                              , "tf34c001");
    strcpy_s(cTcp.Label[CDBs_TCAS_TARA_DISPLAY_FAIL]                 , "tf34c141");
    strcpy_s(cTcp.Label[CDBs_TCAS_TARA_DISPLAY_FAIL_LEFT]            , "tf34c151");
    strcpy_s(cTcp.Label[CDBs_TCAS_TARA_DISPLAY_FAIL_RIGHT]           , "tf34c152");
    strcpy_s(cTcp.Label[CDBs_TCAS_TA_ONLY]                           , "tf34c161");
    strcpy_s(cTcp.Label[CDBs_TCAS_INTERNAL_FAILURE]                  , "tf34c201");
    strcpy_s(cTcp.Label[CDBs_TCAS_RA_FAILURE]                        , "tf34c241");
    strcpy_s(cTcp.Label[CDBs_FM1_FAIL]                               , "tf34f101");
    strcpy_s(cTcp.Label[CDBs_FM2_FAIL]                               , "tf34f102");
    strcpy_s(cTcp.Label[CDBs_ENG1_FAIL]                              , "tf711021");
    strcpy_s(cTcp.Label[CDBs_ENG2_FAIL]                              , "tf711022");
    strcpy_s(cTcp.Label[CDBs_WINDSHEAR_WARNING]                      , "idlgwsw");
    strcpy_s(cTcp.Label[CDBs_TCAS_RA_CORRECTIVE]                     , "idltcorv");
    strcpy_s(cTcp.Label[CDBs_TCAS_RA_PREVENTIVE]                     , "idltprev");
    strcpy_s(cTcp.Label[CDBs_TCAS_ADVISORY_TRAFIC_ALERT]             , "idlttrav");
    strcpy_s(cTcp.Label[CDBs_TCAS_WARNING_OR_VALID_OUTPUT]           , "idltwarn");
    strcpy_s(cTcp.Label[CDBs_TCAS_WINDSHEAR_INHIBIT]                 , "idlwtcwi");
    strcpy_s(cTcp.Label[CDBs_TCAS_COMPLEMENT_MSG]                    , "vstcomp");
    strcpy_s(cTcp.Label[CDBs_CHECK_PFD2_MSG_ACTIVE]                  , "dm24a22a");
    strcpy_s(cTcp.Label[CDBs_CHECK_PFD1_MSG_ACTIVE]                  , "dm23a22a");
    strcpy_s(cTcp.Label[CDBs_CHECK_PFD_MSG_ACTIVE]                   , "dm22a22a");
    strcpy_s(cTcp.Label[CDBs_AIRFIELD_ELEVATION]                     , "vsaele"); // or rtelvelb
    strcpy_s(cTcp.Label[CDBs_FCU_METRIC_PB]                          , "sspbmtr");
    //strcpy_s( latest changes
    //strcpy_s(cTcp.Label[CDBs_DIST_AC_END_RWY]                        , "vdrw");
    //strcpy_s(cTcp.Label[CDBs_X_DIST_FROM_END_RWY]                    , "vxrw");
    //strcpy_s(cTcp.Label[CDBs_Y_DIST_FROM_END_RWY]                    , "vyrw");
    //strcpy_s(cTcp.Label[CDBs_X_DIST_TDZ_RWY]                         , "vxd");
    //strcpy_s(cTcp.Label[CDBs_Y_DIST_TDZ_RWY]                         , "vyd");
    strcpy_s(cTcp.Label[CDBs_DIST_TDZ]                               , "rvrtd");
    strcpy_s(cTcp.Label[CDBs_OPTIMUM_ALTITUDE]                       , "rvhop");
    strcpy_s(cTcp.Label[CDBs_VERT_DEV_GP_FT]                         , "rvdgp");
    strcpy_s(cTcp.Label[CDBs_VERT_DEV_GP_DOT]                        , "rvddgp");
    strcpy_s(cTcp.Label[CDBs_LAT_DEV_FT]                             , "rvdlk");
    strcpy_s(cTcp.Label[CDBs_LAT_DEV_DOT]                            , "rvddlk");
    strcpy_s(cTcp.Label[CDBs_LOC_TWO_DOT]                            , "rvlocf2d");
    strcpy_s(cTcp.Label[CDBs_LOC_ONE_DOT]                            , "rvlocf1d");
    strcpy_s(cTcp.Label[CDBs_LOC_HALF_DOT]                           , "rvlocf5d");
    strcpy_s(cTcp.Label[CDBs_GS_TWO_DOT]                             , "rvgpf2d");
    strcpy_s(cTcp.Label[CDBs_GS_ONE_DOT]                             , "rvgpf1d");
    strcpy_s(cTcp.Label[CDBs_GS_HALF_DOT]                            , "rvgpf5d");
    strcpy_s(cTcp.Label[CDBs_BOUNDARY_FLAG]                          , "rvcrsbnd");

	strcpy_s(cTcp.Label[CDBs_fpln_end_of_predictions]		, "qfueptr");
	strcpy_s(cTcp.Label[CDBs_FROM_waypoint]				, "qflfrmlg");
	strcpy_s(cTcp.Label[CDBs_TO_waypoint]					, "qfltoleg");
	strcpy_s(cTcp.Label[CDBs_NEXT_waypoint]				, "qflnxleg");
	strcpy_s(cTcp.Label[CDBs_FOLLOWING_waypoint]			, "qflfoleg");
	strcpy_s(cTcp.Label[CDBs_DESTINATION_waypoint]		, "qfldstlg");
	strcpy_s(cTcp.Label[CDBs_END_waypoint]				, "qflendlg");
	strcpy_s(cTcp.Label[CDBs_AP_disc_capt]				, "idlfcapd");
	strcpy_s(cTcp.Label[CDBs_Mag_Heading]					, "rna320ca");
	strcpy_s(cTcp.Label[CDBs_ILS_DME_Dez]					, "qjiadmed3");
	strcpy_s(cTcp.Label[CDBs_Dist_Dest]					, "qfpdistd");
	strcpy_s(cTcp.Label[CDBs_Dist_TO]				    	, "qfltkdis");
	strcpy_s(cTcp.Label[CDBs_SpeedScale_Pos]				, "qerxspd");

	// SAMI ND A330																	!!!!!!!   NEU HINZUGEFUEGT
	strcpy_s(cTcp.Label[CDBs_HEADING_REFERENCE_TRUE]			   , "qfmtrue");
	strcpy_s(cTcp.Label[CDBs_VOR1_SELECTION]					   , "lq25c02a");
	strcpy_s(cTcp.Label[CDBs_VOR2_SELECTION]					   , "lq26c02a");
	strcpy_s(cTcp.Label[CDBs_ADF1_SELECTION]					   , "lq23c02a");
	strcpy_s(cTcp.Label[CDBs_ADF2_SELECTION]					   , "lq24c02a");
	strcpy_s(cTcp.Label[CDBs_VOR1_TUNING_MODE]				   , "jf18a01b");
	strcpy_s(cTcp.Label[CDBs_VOR2_TUNING_MODE]				   , "jf25a01b");
	strcpy_s(cTcp.Label[CDBs_ADF1_TUNING_MODE]				   , "jf20a01b");
	strcpy_s(cTcp.Label[CDBs_ADF2_TUNING_MODE]				   , "jf27a01b");
	strcpy_s(cTcp.Label[CDBs_VOR1_ID]							   , "rbdmeide[6]"); 
	strcpy_s(cTcp.Label[CDBs_VOR2_ID]							   , "rbdmeide[9]"); 
	strcpy_s(cTcp.Label[CDB_FCU_AP1PBLT]							, "ssap1pblt"); 
	strcpy_s(cTcp.Label[CDB_FCU_AP2PBLT]							, "ssap2pblt"); 
	strcpy_s(cTcp.Label[HARDWARE_ONLINE]							, "a33xonoff"); 

	strcpy_s(cTcp.Label[CDB_BAT_1]								, "idaebat");
	strcpy_s(cTcp.Label[CDB_BAT_2]								, "idaebat2");
	strcpy_s(cTcp.Label[CDB_BAT_A]								, "idaebatu");
	strcpy_s(cTcp.Label[CDB_RIGHT_GEAR_ONGROUND]					, "agfrgog");
	strcpy_s(cTcp.Label[CDB_LEFT_GEAR_ONGROUND]					, "agflgog");
	strcpy_s(cTcp.Label[CDB_NOSE_GEAR_ONGROUND]					, "agfngog");
	strcpy_s(cTcp.Label[CDB_NOSMOK_ON]							, "idrfsmko");
	strcpy_s(cTcp.Label[CDB_FASTSB_ON]							, "idrfblto");
	strcpy_s(cTcp.Label[CDB_APU_FIRE_TEST]						, "idartu");
	strcpy_s(cTcp.Label[CDB_ENG_FIRE_TEST]						, "idarte");
	strcpy_s(cTcp.Label[CDB_FLIGHT_FREEZE]						, "tcmflreq");
	
	// END SAMI ND A330																!!!!!!!   ENDE NEU HINZUGEFUEGT
	
	// FCU LABEL A330

	strcpy_s(cTcp.Label[CDB_FCU_LOC_REQ]		, "sspbloc");
	strcpy_s(cTcp.Label[CDB_FCU_ALT_REQ]		, "sspbalt");
	strcpy_s(cTcp.Label[CDB_FCU_APPR_REQ]		, "sspbappr");
	strcpy_s(cTcp.Label[CDB_FCU_AP1_REQ]		, "sspbap1");
	strcpy_s(cTcp.Label[CDB_FCU_AP2_REQ]		, "sspbap2");
	strcpy_s(cTcp.Label[CDB_FCU_ATHR_REQ]		, "sspbathr");
	strcpy_s(cTcp.Label[CDB_FCU_FD1_REQ]		, "sspbfd[0]");
	strcpy_s(cTcp.Label[CDB_FCU_LS1_REQ]		, "sspbls[0]");
	strcpy_s(cTcp.Label[CDB_FCU_CSTR1_REQ]	, "sspbcstr[0]");
	strcpy_s(cTcp.Label[CDB_FCU_WPT1_REQ]		, "sspbwpt[0]");
	strcpy_s(cTcp.Label[CDB_FCU_VORD1_REQ]	, "sspbvor[0]");
	strcpy_s(cTcp.Label[CDB_FCU_NDB1_REQ]		, "sspbndb[0]");
	strcpy_s(cTcp.Label[CDB_FCU_ARPT1_REQ]	, "sspbarpt[0]");
	strcpy_s(cTcp.Label[CDB_FCU_FD2_REQ]		, "sspbfd[1]");
	strcpy_s(cTcp.Label[CDB_FCU_LS2_REQ]		, "sspbls[1]");
	strcpy_s(cTcp.Label[CDB_FCU_CSTR2_REQ]	, "sspbcstr[1]");
	strcpy_s(cTcp.Label[CDB_FCU_WPT2_REQ]		, "sspbwpt[1]");
	strcpy_s(cTcp.Label[CDB_FCU_VORD2_REQ]	, "sspbvor[1]");
	strcpy_s(cTcp.Label[CDB_FCU_NDB2_REQ]		, "sspbndb[1]");
	strcpy_s(cTcp.Label[CDB_FCU_ARPT2_REQ]	, "sspbarpt[1]");

	strcpy_s(cTcp.Label[CDB_FCU_LOC_STATUS]		, "sslocpblt");
	strcpy_s(cTcp.Label[CDB_FCU_ALT_STATUS]		, "ssaltpblt");
	strcpy_s(cTcp.Label[CDB_FCU_APPR_STATUS]		, "ssapppblt");
	strcpy_s(cTcp.Label[CDB_FCU_ATHR_STATUS]		, "ssatpblt");
	strcpy_s(cTcp.Label[CDB_FCU_FD1_STATUS]		, "ssfdlpblt");
	strcpy_s(cTcp.Label[CDB_FCU_LS1_STATUS]		, "sslslpblt");
	strcpy_s(cTcp.Label[CDB_FCU_CSTR1_STATUS]		, "sscstlpblt");
	strcpy_s(cTcp.Label[CDB_FCU_WPT1_STATUS]		, "sswptlpblt");
	strcpy_s(cTcp.Label[CDB_FCU_VORD1_STATUS]		, "ssvorlpblt");
	strcpy_s(cTcp.Label[CDB_FCU_NDB1_STATUS]		, "ssndblpblt");
	strcpy_s(cTcp.Label[CDB_FCU_ARPT1_STATUS]		, "ssarplpblt");
	strcpy_s(cTcp.Label[CDB_FCU_FD2_STATUS]		, "ssfdrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_LS2_STATUS]		, "sslsrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_CSTR2_STATUS]		, "sscstrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_WPT2_STATUS]		, "sswptrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_VORD2_STATUS]		, "ssvorrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_NDB2_STATUS]		, "ssndbrpblt");
	strcpy_s(cTcp.Label[CDB_FCU_ARPT2_STATUS]		, "ssarprpblt");

	strcpy_s(cTcp.Label[CDB_FCU_SPD_DISP]			, "sswin1");
	strcpy_s(cTcp.Label[CDB_FCU_SPD_DISP_STATUS]	, "ssspdwdsh");
	strcpy_s(cTcp.Label[CDB_FCU_SPD_DOT_STATUS]	, "ssspdmlt");
	strcpy_s(cTcp.Label[CDB_FCU_SPDMA_STATUS]		, "sspbsm");
	strcpy_s(cTcp.Label[CDB_FCU_SPD_I_STATUS]		, "ssknob1_i");
	strcpy_s(cTcp.Label[CDB_FCU_SPD_O_STATUS]		, "ssknob1_o");

	strcpy_s(cTcp.Label[CDB_FCU_HDG_DISP]			, "sswin2");
	strcpy_s(cTcp.Label[CDB_FCU_HDG_DISP_STATUS]	, "sslatwdsh");
	strcpy_s(cTcp.Label[CDB_FCU_HDG_DOT_STATUS]	, "sslatlt");
	strcpy_s(cTcp.Label[CDB_FCU_HDGTRK_STATUS]	, "sspbht");
	strcpy_s(cTcp.Label[CDB_FCU_HDG_I_STATUS]		, "ssknob2_i");
	strcpy_s(cTcp.Label[CDB_FCU_HDG_O_STATUS]		, "ssknob2_o");
	strcpy_s(cTcp.Label[CDB_FCU_HDG_VS_SEL]		, "sshvortf");

	strcpy_s(cTcp.Label[CDB_FCU_ALT_DISP]			, "sswin3");
	strcpy_s(cTcp.Label[CDB_FCU_ALT_DOT_STATUS]	, "sslvlclt");
	strcpy_s(cTcp.Label[CDB_FCU_ALT_I_STATUS]		, "ssknob3_i");
	strcpy_s(cTcp.Label[CDB_FCU_ALT_O_STATUS]		, "ssknob3_o");

	strcpy_s(cTcp.Label[CDB_FCU_VS_DISP]			, "sswin4");
	strcpy_s(cTcp.Label[CDB_FCU_VSF_DISP_STATUS]	, "ssvsfwdsh");
	strcpy_s(cTcp.Label[CDB_FCU_VS_I_STATUS]		, "ssknob4_i");
	strcpy_s(cTcp.Label[CDB_FCU_VS_O_STATUS]		, "ssknob4_o");

	strcpy_s(cTcp.Label[CDB_ECPL_QNHDISP]			, "sswinprs[0]");
	strcpy_s(cTcp.Label[CDB_ECPL_QNHSTD]			, "ssprslwdsh");
	strcpy_s(cTcp.Label[CDB_ECPL_QNHMODE]			, "ssknob5_h[0]");
	strcpy_s(cTcp.Label[CDB_ECPL_I_STATUS]		, "ssknob5_i[0]");
	strcpy_s(cTcp.Label[CDB_ECPL_O_STATUS]		, "ssknob5_o[0]");

	strcpy_s(cTcp.Label[CDB_ECPR_QNHDISP]			, "sswinprs[1]");
	strcpy_s(cTcp.Label[CDB_ECPR_QNHSTD]			, "ssprsrwdsh");
	strcpy_s(cTcp.Label[CDB_ECPR_QNHMODE]			, "ssknob5_h[1]");
	strcpy_s(cTcp.Label[CDB_ECPR_I_STATUS]		, "ssknob5_i[1]");
	strcpy_s(cTcp.Label[CDB_ECPR_O_STATUS]		, "ssknob5_o[1]");

	strcpy_s(cTcp.Label[CDB_FCU_SWITCH_L1]		, "ssswitch3[0]");
	strcpy_s(cTcp.Label[CDB_FCU_SWITCH_L2]		, "ssswitch4[0]");
	strcpy_s(cTcp.Label[CDB_FCU_SWITCH_R1]		, "ssswitch3[1]");
	strcpy_s(cTcp.Label[CDB_FCU_SWITCH_R2]		, "ssswitch4[1]");

	strcpy_s(cTcp.Label[CDB_FCU_SELECTOR_L1]		, "ssswitch1[0]");
	strcpy_s(cTcp.Label[CDB_FCU_SELECTOR_L2]		, "ssswitch2[0]");
	strcpy_s(cTcp.Label[CDB_FCU_SELECTOR_R1]		, "ssswitch2[1]");
	strcpy_s(cTcp.Label[CDB_FCU_SELECTOR_R2]		, "ssswitch1[1]");

	strcpy_s(cTcp.Label[CDB_IOS_REPOS]			, "tcfflpos");
	strcpy_s(cTcp.Label[CDB_IOS_REPOS_PROGRESS]		, "ruflt");





//*         ---------------------------------------------
//****      Temperature, Wind, Shear and Turbulence Terms
//*         ---------------------------------------------
//VDRW      REAL 0.            DISTANCE FROM A/C TO END OF R/W         [FT] F10.2
//VXRW      REAL 0.            X DIST. FROM END OF R/W                 [FT] F10.2
//VYRW      REAL 0.            Y DIST. FROM END OF R/W                 [FT] F10.2
//VXD       REAL 0.            X DISTANCE TO TOUCHDOWN AREA ON R/W   [FEET] F10.2
//VYD       REAL 0.            Y DISTANCE TO TOUCHDOWN AREA ON R/W   [FEET] F10.2
//VXDP      REAL 0.            DISTANCE TO TOUCHDOWN AREA ON R/W [VXD+3000] F10.2
//*
//***       APPROACH PLOT OUTPUTS TO I/F
//*
//RVRTD     REAL 0.            DISTANCE TO TOUCHDOWN                  [NM]  F6.2
//RVBRG     REAL 0.            BEARING TO TOUCHDOWN                  [DEG]  F6.1
//RVHOP     REAL 0.            OPTIMUM ALTITUDE                       [FT]  F4.0
//RVDGP     REAL 0.            VERTICAL DEV'N FROM GLIDEPATH          [FT]  F4.0
//RVDDGP    REAL 0.            VERTICAL DEV'N FROM GLIDEPATH         [DOT]  F4.1
//RVDLK     REAL 0.            HORIZONTAL DEV'N                       [FT]  F4.0
//RVDDLK    REAL 0.            HORIZONTAL DEV'N                      [DOT]  F4.1
//RVTFRE    REAL 0.            STATION FREQUENCY(=0 IF GCA)                 F8.2
//*
//RVLOCF2D  LOG1 .F.           LOCALIZER DEV'N > 2 DOTS                     TRUE
//RVLOCF1D  LOG1 .F.           LOCALIZER DEV'N > 1 DOT                      TRUE
//RVLOCF5D  LOG1 .F.           LOCALIZER DEV'N > 0.5 DOT                    TRUE
//RVGPF2D   LOG1 .F.           GLIDEPATH DEV'N > 2 DOTS                     TRUE
//RVGPF1D   LOG1 .F.           GLIDEPATH DEV'N > 1 DOT                      TRUE
//RVGPF5D   LOG1 .F.           GLIDEPATH DEV'N > 0.5 DOT                    TRUE
//RVCRSBND  LOG1 .F.           BOUNDARY FLAG                                TRUE
}

#endif
