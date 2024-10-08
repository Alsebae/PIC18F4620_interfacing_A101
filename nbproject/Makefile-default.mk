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
FINAL_IMAGE=${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=_APP/application.c _HAL/Drivers/button/button.c _HAL/Drivers/DCmotor/DCmotor.c _HAL/Drivers/keypad/keypad.c _HAL/Drivers/LCD/LCD.c _HAL/Drivers/LED/LED.c _HAL/Drivers/relay/relay.c _HAL/Drivers/SSD/SSD.c _HAL/MCAL/GPIO/HAL_GPIO.c _HAL/MCAL/Interrupt/internal_interrupt.c _HAL/MCAL/Interrupt/external_interrupt.c _HAL/MCAL/Interrupt/interrupt_manager.c _HAL/MCAL/device_config.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_APP/application.p1 ${OBJECTDIR}/_HAL/Drivers/button/button.p1 ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 ${OBJECTDIR}/_HAL/MCAL/device_config.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_APP/application.p1.d ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_APP/application.p1 ${OBJECTDIR}/_HAL/Drivers/button/button.p1 ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 ${OBJECTDIR}/_HAL/MCAL/device_config.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=_APP/application.c _HAL/Drivers/button/button.c _HAL/Drivers/DCmotor/DCmotor.c _HAL/Drivers/keypad/keypad.c _HAL/Drivers/LCD/LCD.c _HAL/Drivers/LED/LED.c _HAL/Drivers/relay/relay.c _HAL/Drivers/SSD/SSD.c _HAL/MCAL/GPIO/HAL_GPIO.c _HAL/MCAL/Interrupt/internal_interrupt.c _HAL/MCAL/Interrupt/external_interrupt.c _HAL/MCAL/Interrupt/interrupt_manager.c _HAL/MCAL/device_config.c main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_APP/application.p1: _APP/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_APP" 
	@${RM} ${OBJECTDIR}/_APP/application.p1.d 
	@${RM} ${OBJECTDIR}/_APP/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_APP/application.p1 _APP/application.c 
	@-${MV} ${OBJECTDIR}/_APP/application.d ${OBJECTDIR}/_APP/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_APP/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/button/button.p1: _HAL/Drivers/button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/button" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/button/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/button/button.p1 _HAL/Drivers/button/button.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/button/button.d ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1: _HAL/Drivers/DCmotor/DCmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/DCmotor" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 _HAL/Drivers/DCmotor/DCmotor.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.d ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1: _HAL/Drivers/keypad/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/keypad" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 _HAL/Drivers/keypad/keypad.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.d ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1: _HAL/Drivers/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/LCD" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 _HAL/Drivers/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.d ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/LED/LED.p1: _HAL/Drivers/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/LED" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 _HAL/Drivers/LED/LED.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/LED/LED.d ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/relay/relay.p1: _HAL/Drivers/relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/relay" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 _HAL/Drivers/relay/relay.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/relay/relay.d ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1: _HAL/Drivers/SSD/SSD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/SSD" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 _HAL/Drivers/SSD/SSD.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.d ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1: _HAL/MCAL/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 _HAL/MCAL/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.d ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1: _HAL/MCAL/Interrupt/internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 _HAL/MCAL/Interrupt/internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1: _HAL/MCAL/Interrupt/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 _HAL/MCAL/Interrupt/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1: _HAL/MCAL/Interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 _HAL/MCAL/Interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/device_config.p1: _HAL/MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/device_config.p1 _HAL/MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/device_config.d ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_APP/application.p1: _APP/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_APP" 
	@${RM} ${OBJECTDIR}/_APP/application.p1.d 
	@${RM} ${OBJECTDIR}/_APP/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_APP/application.p1 _APP/application.c 
	@-${MV} ${OBJECTDIR}/_APP/application.d ${OBJECTDIR}/_APP/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_APP/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/button/button.p1: _HAL/Drivers/button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/button" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/button/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/button/button.p1 _HAL/Drivers/button/button.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/button/button.d ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/button/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1: _HAL/Drivers/DCmotor/DCmotor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/DCmotor" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1 _HAL/Drivers/DCmotor/DCmotor.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.d ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/DCmotor/DCmotor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1: _HAL/Drivers/keypad/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/keypad" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1 _HAL/Drivers/keypad/keypad.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.d ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/keypad/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1: _HAL/Drivers/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/LCD" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1 _HAL/Drivers/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.d ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/LED/LED.p1: _HAL/Drivers/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/LED" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1 _HAL/Drivers/LED/LED.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/LED/LED.d ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/relay/relay.p1: _HAL/Drivers/relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/relay" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1 _HAL/Drivers/relay/relay.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/relay/relay.d ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1: _HAL/Drivers/SSD/SSD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/Drivers/SSD" 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1 _HAL/Drivers/SSD/SSD.c 
	@-${MV} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.d ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/Drivers/SSD/SSD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1: _HAL/MCAL/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1 _HAL/MCAL/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.d ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1: _HAL/MCAL/Interrupt/internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1 _HAL/MCAL/Interrupt/internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1: _HAL/MCAL/Interrupt/external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1 _HAL/MCAL/Interrupt/external_interrupt.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1: _HAL/MCAL/Interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL/Interrupt" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1 _HAL/MCAL/Interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.d ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/Interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_HAL/MCAL/device_config.p1: _HAL/MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_HAL/MCAL" 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/_HAL/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_HAL/MCAL/device_config.p1 _HAL/MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/_HAL/MCAL/device_config.d ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_HAL/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -mrom=default,-fd30-ffff -mram=default,-ef4-eff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v6.15/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.15/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.hex -o${DISTDIR}/PIC18F4620_interfacing_A101.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
