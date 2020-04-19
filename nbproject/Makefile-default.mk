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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=DEV_Config.c EPD_2in7.c GUI_Paint.c font12.c font12CN.c font16.c font20.c font24.c font24CN.c font8.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/DEV_Config.o ${OBJECTDIR}/EPD_2in7.o ${OBJECTDIR}/GUI_Paint.o ${OBJECTDIR}/font12.o ${OBJECTDIR}/font12CN.o ${OBJECTDIR}/font16.o ${OBJECTDIR}/font20.o ${OBJECTDIR}/font24.o ${OBJECTDIR}/font24CN.o ${OBJECTDIR}/font8.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/DEV_Config.o.d ${OBJECTDIR}/EPD_2in7.o.d ${OBJECTDIR}/GUI_Paint.o.d ${OBJECTDIR}/font12.o.d ${OBJECTDIR}/font12CN.o.d ${OBJECTDIR}/font16.o.d ${OBJECTDIR}/font20.o.d ${OBJECTDIR}/font24.o.d ${OBJECTDIR}/font24CN.o.d ${OBJECTDIR}/font8.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/DEV_Config.o ${OBJECTDIR}/EPD_2in7.o ${OBJECTDIR}/GUI_Paint.o ${OBJECTDIR}/font12.o ${OBJECTDIR}/font12CN.o ${OBJECTDIR}/font16.o ${OBJECTDIR}/font20.o ${OBJECTDIR}/font24.o ${OBJECTDIR}/font24CN.o ${OBJECTDIR}/font8.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=DEV_Config.c EPD_2in7.c GUI_Paint.c font12.c font12CN.c font16.c font20.c font24.c font24CN.c font8.c main.c

# Pack Options 
PACK_COMMON_OPTIONS=-I ${CMSIS_DIR}\CMSIS\Core\Include



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAMD21G18A
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
${OBJECTDIR}/DEV_Config.o: DEV_Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DEV_Config.o.d 
	@${RM} ${OBJECTDIR}/DEV_Config.o 
	@${FIXDEPS} "${OBJECTDIR}/DEV_Config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DEV_Config.o.d" -o ${OBJECTDIR}/DEV_Config.o DEV_Config.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/EPD_2in7.o: EPD_2in7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EPD_2in7.o.d 
	@${RM} ${OBJECTDIR}/EPD_2in7.o 
	@${FIXDEPS} "${OBJECTDIR}/EPD_2in7.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EPD_2in7.o.d" -o ${OBJECTDIR}/EPD_2in7.o EPD_2in7.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/GUI_Paint.o: GUI_Paint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GUI_Paint.o.d 
	@${RM} ${OBJECTDIR}/GUI_Paint.o 
	@${FIXDEPS} "${OBJECTDIR}/GUI_Paint.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GUI_Paint.o.d" -o ${OBJECTDIR}/GUI_Paint.o GUI_Paint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font12.o: font12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font12.o.d 
	@${RM} ${OBJECTDIR}/font12.o 
	@${FIXDEPS} "${OBJECTDIR}/font12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font12.o.d" -o ${OBJECTDIR}/font12.o font12.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font12CN.o: font12CN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font12CN.o.d 
	@${RM} ${OBJECTDIR}/font12CN.o 
	@${FIXDEPS} "${OBJECTDIR}/font12CN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font12CN.o.d" -o ${OBJECTDIR}/font12CN.o font12CN.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font16.o: font16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font16.o.d 
	@${RM} ${OBJECTDIR}/font16.o 
	@${FIXDEPS} "${OBJECTDIR}/font16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font16.o.d" -o ${OBJECTDIR}/font16.o font16.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font20.o: font20.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font20.o.d 
	@${RM} ${OBJECTDIR}/font20.o 
	@${FIXDEPS} "${OBJECTDIR}/font20.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font20.o.d" -o ${OBJECTDIR}/font20.o font20.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font24.o: font24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font24.o.d 
	@${RM} ${OBJECTDIR}/font24.o 
	@${FIXDEPS} "${OBJECTDIR}/font24.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font24.o.d" -o ${OBJECTDIR}/font24.o font24.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font24CN.o: font24CN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font24CN.o.d 
	@${RM} ${OBJECTDIR}/font24CN.o 
	@${FIXDEPS} "${OBJECTDIR}/font24CN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font24CN.o.d" -o ${OBJECTDIR}/font24CN.o font24CN.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font8.o: font8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font8.o.d 
	@${RM} ${OBJECTDIR}/font8.o 
	@${FIXDEPS} "${OBJECTDIR}/font8.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font8.o.d" -o ${OBJECTDIR}/font8.o font8.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/DEV_Config.o: DEV_Config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DEV_Config.o.d 
	@${RM} ${OBJECTDIR}/DEV_Config.o 
	@${FIXDEPS} "${OBJECTDIR}/DEV_Config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DEV_Config.o.d" -o ${OBJECTDIR}/DEV_Config.o DEV_Config.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/EPD_2in7.o: EPD_2in7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EPD_2in7.o.d 
	@${RM} ${OBJECTDIR}/EPD_2in7.o 
	@${FIXDEPS} "${OBJECTDIR}/EPD_2in7.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EPD_2in7.o.d" -o ${OBJECTDIR}/EPD_2in7.o EPD_2in7.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/GUI_Paint.o: GUI_Paint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/GUI_Paint.o.d 
	@${RM} ${OBJECTDIR}/GUI_Paint.o 
	@${FIXDEPS} "${OBJECTDIR}/GUI_Paint.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/GUI_Paint.o.d" -o ${OBJECTDIR}/GUI_Paint.o GUI_Paint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font12.o: font12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font12.o.d 
	@${RM} ${OBJECTDIR}/font12.o 
	@${FIXDEPS} "${OBJECTDIR}/font12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font12.o.d" -o ${OBJECTDIR}/font12.o font12.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font12CN.o: font12CN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font12CN.o.d 
	@${RM} ${OBJECTDIR}/font12CN.o 
	@${FIXDEPS} "${OBJECTDIR}/font12CN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font12CN.o.d" -o ${OBJECTDIR}/font12CN.o font12CN.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font16.o: font16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font16.o.d 
	@${RM} ${OBJECTDIR}/font16.o 
	@${FIXDEPS} "${OBJECTDIR}/font16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font16.o.d" -o ${OBJECTDIR}/font16.o font16.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font20.o: font20.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font20.o.d 
	@${RM} ${OBJECTDIR}/font20.o 
	@${FIXDEPS} "${OBJECTDIR}/font20.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font20.o.d" -o ${OBJECTDIR}/font20.o font20.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font24.o: font24.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font24.o.d 
	@${RM} ${OBJECTDIR}/font24.o 
	@${FIXDEPS} "${OBJECTDIR}/font24.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font24.o.d" -o ${OBJECTDIR}/font24.o font24.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font24CN.o: font24CN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font24CN.o.d 
	@${RM} ${OBJECTDIR}/font24CN.o 
	@${FIXDEPS} "${OBJECTDIR}/font24CN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font24CN.o.d" -o ${OBJECTDIR}/font24CN.o font24CN.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/font8.o: font8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/font8.o.d 
	@${RM} ${OBJECTDIR}/font8.o 
	@${FIXDEPS} "${OBJECTDIR}/font8.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/font8.o.d" -o ${OBJECTDIR}/font8.o font8.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}/samd21a ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=8000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp=${DFP_DIR}/samd21a
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=8000,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp=${DFP_DIR}/samd21a
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/weeklychores.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
