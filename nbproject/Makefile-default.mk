#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/ES_Framework.c C:/CMPE118/src/IO_Ports.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FiringSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/MotorControl.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/NightFallHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeSensors.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/WinningSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Main.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/BumperControl.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachBumperService.c" C:/CMPE118/src/roach.c "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/SynchronousSampling.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Beacon.c" "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TrackwireService.c" C:/CMPE118/src/RC_Servo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/ES_Framework.o ${OBJECTDIR}/_ext/331920610/IO_Ports.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o ${OBJECTDIR}/_ext/601312841/MotorControl.o ${OBJECTDIR}/_ext/601312841/NightFallHSM.o ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o ${OBJECTDIR}/_ext/601312841/TapeSensors.o ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o ${OBJECTDIR}/_ext/601312841/Main.o ${OBJECTDIR}/_ext/601312841/BumperControl.o ${OBJECTDIR}/_ext/601312841/RoachBumperService.o ${OBJECTDIR}/_ext/331920610/roach.o ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o ${OBJECTDIR}/_ext/601312841/Beacon.o ${OBJECTDIR}/_ext/601312841/TrackwireService.o ${OBJECTDIR}/_ext/331920610/RC_Servo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/331920610/AD.o.d ${OBJECTDIR}/_ext/331920610/BOARD.o.d ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d ${OBJECTDIR}/_ext/331920610/pwm.o.d ${OBJECTDIR}/_ext/331920610/serial.o.d ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d ${OBJECTDIR}/_ext/601312841/MotorControl.o.d ${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d ${OBJECTDIR}/_ext/601312841/TapeSensors.o.d ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d ${OBJECTDIR}/_ext/601312841/Main.o.d ${OBJECTDIR}/_ext/601312841/BumperControl.o.d ${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d ${OBJECTDIR}/_ext/331920610/roach.o.d ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d ${OBJECTDIR}/_ext/601312841/Beacon.o.d ${OBJECTDIR}/_ext/601312841/TrackwireService.o.d ${OBJECTDIR}/_ext/331920610/RC_Servo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/ES_Framework.o ${OBJECTDIR}/_ext/331920610/IO_Ports.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o ${OBJECTDIR}/_ext/601312841/MotorControl.o ${OBJECTDIR}/_ext/601312841/NightFallHSM.o ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o ${OBJECTDIR}/_ext/601312841/TapeSensors.o ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o ${OBJECTDIR}/_ext/601312841/Main.o ${OBJECTDIR}/_ext/601312841/BumperControl.o ${OBJECTDIR}/_ext/601312841/RoachBumperService.o ${OBJECTDIR}/_ext/331920610/roach.o ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o ${OBJECTDIR}/_ext/601312841/Beacon.o ${OBJECTDIR}/_ext/601312841/TrackwireService.o ${OBJECTDIR}/_ext/331920610/RC_Servo.o

# Source Files
SOURCEFILES=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/ES_Framework.c C:/CMPE118/src/IO_Ports.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FiringSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/MotorControl.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/NightFallHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeSensors.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/WinningSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Main.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/BumperControl.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachBumperService.c C:/CMPE118/src/roach.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/SynchronousSampling.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Beacon.c C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TrackwireService.c C:/CMPE118/src/RC_Servo.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c   
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c   
	
${OBJECTDIR}/_ext/331920610/ES_Framework.o: C:/CMPE118/src/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/331920610/ES_Framework.o C:/CMPE118/src/ES_Framework.c   
	
${OBJECTDIR}/_ext/331920610/IO_Ports.o: C:/CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/331920610/IO_Ports.o C:/CMPE118/src/IO_Ports.c   
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c   
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c   
	
${OBJECTDIR}/_ext/601312841/FiringSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/FiringSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FiringSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/MotorControl.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/MotorControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/MotorControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/MotorControl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/MotorControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/MotorControl.o.d" -o ${OBJECTDIR}/_ext/601312841/MotorControl.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/MotorControl.c"   
	
${OBJECTDIR}/_ext/601312841/NightFallHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/NightFallHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/NightFallHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/NightFallHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/NightFallHSM.c"   
	
${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d" -o ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c"   
	
${OBJECTDIR}/_ext/601312841/TapeSensors.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeSensors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeSensors.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeSensors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeSensors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeSensors.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeSensors.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeSensors.c"   
	
${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/WinningSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/WinningSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/WinningSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/Main.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/Main.o.d" -o ${OBJECTDIR}/_ext/601312841/Main.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Main.c"   
	
${OBJECTDIR}/_ext/601312841/BumperControl.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/BumperControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/BumperControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/BumperControl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/BumperControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/BumperControl.o.d" -o ${OBJECTDIR}/_ext/601312841/BumperControl.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/BumperControl.c"   
	
${OBJECTDIR}/_ext/601312841/RoachBumperService.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/RoachBumperService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachBumperService.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d" -o ${OBJECTDIR}/_ext/601312841/RoachBumperService.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachBumperService.c"   
	
${OBJECTDIR}/_ext/331920610/roach.o: C:/CMPE118/src/roach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/roach.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/roach.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/roach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/roach.o.d" -o ${OBJECTDIR}/_ext/331920610/roach.o C:/CMPE118/src/roach.c   
	
${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/SynchronousSampling.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/SynchronousSampling.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d" -o ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/SynchronousSampling.c"   
	
${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/Beacon.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/Beacon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/Beacon.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/Beacon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/Beacon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/Beacon.o.d" -o ${OBJECTDIR}/_ext/601312841/Beacon.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Beacon.c"   
	
${OBJECTDIR}/_ext/601312841/TrackwireService.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TrackwireService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TrackwireService.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TrackwireService.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TrackwireService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TrackwireService.o.d" -o ${OBJECTDIR}/_ext/601312841/TrackwireService.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TrackwireService.c"   
	
${OBJECTDIR}/_ext/331920610/RC_Servo.o: C:/CMPE118/src/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/331920610/RC_Servo.o C:/CMPE118/src/RC_Servo.c   
	
else
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c   
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c   
	
${OBJECTDIR}/_ext/331920610/ES_Framework.o: C:/CMPE118/src/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/331920610/ES_Framework.o C:/CMPE118/src/ES_Framework.c   
	
${OBJECTDIR}/_ext/331920610/IO_Ports.o: C:/CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/331920610/IO_Ports.o C:/CMPE118/src/IO_Ports.c   
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c   
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c   
	
${OBJECTDIR}/_ext/601312841/FiringSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/FiringSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/FiringSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/FiringSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FiringSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/LoadingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/LoadingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/MotorControl.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/MotorControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/MotorControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/MotorControl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/MotorControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/MotorControl.o.d" -o ${OBJECTDIR}/_ext/601312841/MotorControl.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/MotorControl.c"   
	
${OBJECTDIR}/_ext/601312841/NightFallHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/NightFallHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/NightFallHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/NightFallHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/NightFallHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/NightFallHSM.c"   
	
${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/OrientingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/OrientingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o.d" -o ${OBJECTDIR}/_ext/601312841/RoachFrameworkEvents.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachFrameworkEvents.c"   
	
${OBJECTDIR}/_ext/601312841/TapeSensors.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeSensors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeSensors.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeSensors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeSensors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeSensors.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeSensors.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeSensors.c"   
	
${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TargetingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TargetingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/WinningSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/WinningSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/WinningSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/WinningSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/WinningSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/Main.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/Main.o.d" -o ${OBJECTDIR}/_ext/601312841/Main.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Main.c"   
	
${OBJECTDIR}/_ext/601312841/BumperControl.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/BumperControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/BumperControl.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/BumperControl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/BumperControl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/BumperControl.o.d" -o ${OBJECTDIR}/_ext/601312841/BumperControl.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/BumperControl.c"   
	
${OBJECTDIR}/_ext/601312841/RoachBumperService.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/RoachBumperService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/RoachBumperService.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/RoachBumperService.o.d" -o ${OBJECTDIR}/_ext/601312841/RoachBumperService.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/RoachBumperService.c"   
	
${OBJECTDIR}/_ext/331920610/roach.o: C:/CMPE118/src/roach.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/roach.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/roach.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/roach.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/roach.o.d" -o ${OBJECTDIR}/_ext/331920610/roach.o C:/CMPE118/src/roach.c   
	
${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/FoundTapeSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/FoundTapeSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/SynchronousSampling.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/SynchronousSampling.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/SynchronousSampling.o.d" -o ${OBJECTDIR}/_ext/601312841/SynchronousSampling.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/SynchronousSampling.c"   
	
${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o.d" -o ${OBJECTDIR}/_ext/601312841/TapeFollowingSubSubHSM.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TapeFollowingSubSubHSM.c"   
	
${OBJECTDIR}/_ext/601312841/Beacon.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/Beacon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/Beacon.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/Beacon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/Beacon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/Beacon.o.d" -o ${OBJECTDIR}/_ext/601312841/Beacon.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/Beacon.c"   
	
${OBJECTDIR}/_ext/601312841/TrackwireService.o: C:/Users/Hieu\ Tran/Desktop/Tinkerbot.X/TrackwireService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/601312841 
	@${RM} ${OBJECTDIR}/_ext/601312841/TrackwireService.o.d 
	@${RM} ${OBJECTDIR}/_ext/601312841/TrackwireService.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/601312841/TrackwireService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/601312841/TrackwireService.o.d" -o ${OBJECTDIR}/_ext/601312841/TrackwireService.o "C:/Users/Hieu Tran/Desktop/Tinkerbot.X/TrackwireService.c"   
	
${OBJECTDIR}/_ext/331920610/RC_Servo.o: C:/CMPE118/src/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -I"." -I"C:/CMPE118/include" -I"C:/CMPE118/src" -MMD -MF "${OBJECTDIR}/_ext/331920610/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/331920610/RC_Servo.o C:/CMPE118/src/RC_Servo.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Tinkerbot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
