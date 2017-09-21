#
# File    : rappid_metrowerks.tmf
#
# Abstract:
#	Real-Time Workshop template makefile used to create <model>.mk
#	file for RAppID target.
#
#	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk" which then is
#	passed to nmake to produce <model>.mak
#
#	The following defines can be used to modify the behavior of the build:
#    OPTS           - Additional user defines.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="/I where-ever1 /I where-ever2")
# Copyright 2008 
# Freescale Semiconductor Inc
# All Rights Reserved 
#
# $Log: rappid_metrowerks.tmf,v $
# Revision 1.30  2008/10/13 16:41:03  r61406
# Issue:000
# Update for R2008A/B MATLAB Updates
#
# Revision 1.26  2006/10/27 14:00:35  r66544
# issue:000
#
# Support for Matlab 2006B
#
# Revision 1.25  2006/08/25 17:03:36  r66544
# issue:000
#
# removed multiple display of options from all make files to speed up build process
#
# Revision 1.24  2006/08/08 19:29:36  r66544
# issue:000
# wd dev work continue
#
# Revision 1.23  2006/07/26 21:28:40  B04043
# Delete .bin files on make, to prevent old binaries existing after failed build.
#
# Revision 1.22  2006/07/25 19:19:43  FSL\b04043
# Library module skipping.  Specify .o files in LIB_SKIP, not .c files.
#
# Revision 1.21  2006/07/25 18:21:59  FSL\b04043
# Changes to allow model referencing, library building, etc.
#
# Revision 1.20  2006/07/20 15:46:23  r61406
# PWM:Update copyright notice and Log tag.
#
#



#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  MEM_ALLOC       - Either RT_MALLOC or RT_STATIC indicating the style of the
#                    generated code. Statically allocated data is only useful
#                    for one instance of the model.
#  COMPUTER        - Computer type. See the MATLAB computer command.
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE        - yes (1) or no (0): MAT file logging
#  EXT_MODE        - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.

MODEL           = VirtualWall
MODULES         = EMIOS_library.c Exceptions.c GPIO_library.c IntcInterrupts.c IntcIsrVectors.c MPC5554_HWInit.c MPC55xx_init_debug.c VirtualWall_data.c __ppc_eabi_init.c cpu_init_func.c eTPU_library.c eTPU_util.c emios_init.c etpu_init_fcn.c etpu_qd.c intc_init.c msr_init.c rappid_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c siu_init.c sys_init.c 
MAKEFILE        = VirtualWall.mk
ALT_MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2011b
MATLAB_ROOT     = C:\Program Files\MATLAB\R2011b
S_FUNCTIONS     = 
S_FUNCTIONS_OBJ = 
S_FUNCTIONS_LIB = 
SOLVER          = 
NUMST           = 1
TID01EQ         = 0
NCSTATES        = 0
MEM_ALLOC       = RT_STATIC
COMPUTER        = PCWIN
BUILDARGS       =  GENERATE_REPORT=1 INCLUDE_MDL_TERMINATE_FCN=1 COMBINE_OUTPUT_UPDATE_FCNS=1 MULTI_INSTANCE_CODE=0 INTEGER_CODE=0 PORTABLE_WORDSIZES=0 GENERATE_ERT_S_FUNCTION=0
MULTITASKING    = 0
MAT_FILE        = 0
GENERATE_ASAP2 	= 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
LIB_SKIP                = rt_logging.o avi_rt.o


#--------------------------- Model and reference models -----------------------
MODELLIB                  = VirtualWalllib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif



#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = rappid.tlc
BUILD_SUCCESS	= *** Created executable:

#----------------------------- External mode -----------------------------------

# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC = ext_svr.c updown.c ext_work.c ext_svr_tcpip_transport.c
    EXT_LIB = $(MATLAB_ROOT)\sys\lcc\lib\wsock32.lib
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c ext_serial_win32_port.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC 
-DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif



#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I"$(MATLAB)"\simulink\include \
	-I"$(MATLAB)"\extern\include \
	-I"$(MATLAB)"\rtw\c\src \
	-I"$(MATLAB)"\rtw\c\libsrc \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\common \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\tcpip \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\serial \
	-I"$(MATLAB)"\rtw\c\src\ext_mode\custom

# Additional file include paths
ADD_INCLUDES = \
	-IC:\Users\Embed_Sys_course\git\lab\lab7\prelab2\VirtualWall_rappid_rtw \
	-IC:\Users\Embed_Sys_course\git\lab\lab7\prelab2 \


USER_INCLUDES=

SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif


#------------------------------ Libraries -----------------------------------

LIBS =
 
 

WR_LIBS =
 
 


#---------------------------------TOOLCHAIN------------------------------------
#---------- Define metrowerks tools to build using command line ---------------
#------------------------------------------------------------------------------
TOOL_ROOT=$(MW_TOOL)
CMDLINE_TOOLS=$(TOOL_ROOT)/PowerPC_EABI_Tools/Command_Line_Tools
TOOL_SPECIFIC_FILES=Metrowerks_specific_files
COMPILE_TOOL=$(CMDLINE_TOOLS)/mwcceppc
ASSEMBLY_TOOL=$(CMDLINE_TOOLS)/mwasmeppc
ARCHIVER_TOOL=$(CMDLINE_TOOLS)/mwldeppc
LINK_TOOL=$(CMDLINE_TOOLS)/mwldeppc
TOOL_OPTS= -proc Zen
COMPILE_TOOL_OPTS= -search -gdwarf-2 -fp efpu -char signed $(TOOL_OPTS) -gccincludes -nostdinc -nosyspath -ansi off -opt all -Cpp_exceptions off -spe_vector
ASSEMBLY_TOOL_OPTS=$(TOOL_OPTS) -gccincludes -nostdinc
LIBRARY_OPTS = $(TOOL_OPTS) -library -nostdlib -gdwarf-2 -fp efpu -char signed
LINK_TOOL_OPTS= -gdwarf-2 -fp efpu -char signed $(TOOL_OPTS) -nostdlib -srec -lcf MPC5554_DEBUG.lcf
#LINK_TOOL_OPTS= -gdwarf-2 -fp efpu -char signed $(TOOL_OPTS) -nostdlib -srec -lcf MPC5554.lcf \
#	-romaddr 0x00010000 -rambuffer 0x00010000
TOOL_INCLUDES=-I$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Include \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Src \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Lib \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Lib \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/PPC_EABI/Include \
	-I$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C++/MSL_Common/Include
PLIB_TEMP = precomp
LIB_TEMP  = libs
LIB_SUFFIX = MW

TOOL_CFiles=__ppc_eabi_init.c MPC5554_HWInit.c Exceptions.c IntcInterrupts.c MPC55xx_init_debug.c
#TOOL_CFiles=__ppc_eabi_init.c MPC5554_HWInit.c Exceptions.c IntcInterrupts.c MPC55xx_init.c

TOOL_LIB=\
	$(TOOL_ROOT)/PowerPC_EABI_Support/Runtime/Lib/Runtime.PPCEABI.E.a \
	$(TOOL_ROOT)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib/MSL_C.PPCEABI.bare.E.a

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------



INCLUDES =  -I. \
	-I$(RELATIVE_PATH_TO_ANCHOR) \
	$(MATLAB_INCLUDES) \
	$(TOOL_INCLUDES) \
	$(ADD_INCLUDES) \
	$(USER_INCLUDES) \
	$(MODELREF_INC_PATH) \
	$(SHARED_INCLUDES)


#------------------------ rtModel ----------------------------------------------

CPP_REQ_DEFINES = -DUSE_RTMODEL -DMODEL=$(MODEL) -DREAL_T=float -DRT -DNUMST=$(NUMST) \
	-DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
	-DMT=$(MULTITASKING) -DHAVESTDIO



#-------------------- Definitons for application files: -----------------------
#
# C_FILES       = all application specific C source files.
# S_FILES       = all application specific assembly source files.
# APP_INCS      = all application specific include files.
#

C_FILES =   $(MODEL).c \
			$(MODULES) \
			$(SOLVER) \
			$(S_FUNCTIONS) \
			$(EXT_SRC)
#			$(TOOL_CFiles)

S_FILES = handlers_fit.s handlers_intc_svm.s handlers_wd_method2.s handlers_wd_method3.s

CFLAGS =	$(INCLUDES) \
			$(CPP_REQ_DEFINES) \
            		-c \
			$(EXT_CC_OPTS)

AFLAGS = -c 

######################################################################
# The remainder of this makefile is generally not specific to
# a particular application and normally need not be changed.
######################################################################


LFLAGS    = $(TOOL_LIB) \
			$(LIBS) \
			$(EXT_LIB) \
			-Map $(MODEL).map \
			$(S_FUNCTIONS_LIB)

#
#------------------------ Construct the object file lists------------------------
#
C_OBJECTS = $(C_FILES:.c=.o)
S_OBJECTS = $(S_FILES:.s=.o)
OBJ_FILES = $(S_OBJECTS) $(C_OBJECTS) 

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))
#
#----------------------- make all variables available to sub-makes---------------
#
export


#
#---------------------------------------Build rules------------------------------
#
ifeq ($(MODELREF_TARGET_TYPE), NONE)
  # Top-level model for RTW
  PRODUCT            = $(MODEL).elf
  BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT) $(SYSLIBS) 
  BUILD_PRODUCT_TYPE = "executable"
  SRCS               += $(MODEL).c ert_main.c
else
  # sub-model for RTW
  PRODUCT            = $(MODELLIB)
  BUILD_PRODUCT_TYPE = "library"
endif

all : clean SetupFiles $(PRODUCT)
	@echo Building target $@
	@echo $(BUILD_SUCCESS) $(PRODUCT)

clean:
	@echo clean
	@echo RELATIVE_PATH_TO_ANCHOR is $(RELATIVE_PATH_TO_ANCHOR)
	@echo ==== Removing object files from build directory ====
	@if exist *.o del *.o
	@if exist *.elf del *.elf
	@if exist *.s19 del *.s19
	@if exist *.out del *.out
	@if exist *.mot del *.mot
	@if exist *.bin del *.bin
	@if exist *.srz del *.srz
	@if exist *.d del *.d
	@if exist *.dbo del *.dbo
	@if exist *.rsp del *.rsp
	@if exist err.log del err.log
	@if exist $(LIB_TEMP)\*.o del $(LIB_TEMP)\*.o

SetupFiles:
	@echo Copying necessary files to build directory...
	@echo Compiler details : $(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS)
	@echo Assembler details : $(ASSEMBLY_TOOL) $(ASSEMBLY_TOOL_OPTS) $(AFLAGS)

$(MODELLIB): $(OBJ_FILES) $(WR_LIBS)
	$(ARCHIVER_TOOL) -o $@ $(LIBRARY_OPTS) $(OBJ_FILES)
	@echo Created library: $(MODELLIB)

$(MODEL).elf: $(OBJ_FILES) $(WR_LIBS)
	@echo ==== Creating $(MODEL).out from obj files ====
	$(LINK_TOOL) $(OBJ_FILES) -o $@ $(LINK_TOOL_OPTS) $(LFLAGS)
	@echo Created executable: $(MODEL).elf

##$(C_OBJECTS) : $(C_FILES)
##	@echo Building file $@...
##	$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

$(S_OBJECTS) : $(S_FILES)
	@echo Building assembly file $@...
	@$(ASSEMBLY_TOOL) $(ASSEMBLY_TOOL_OPTS) $(AFLAGS) -o $@ $(@:.o=.s)

%.o : %.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : %.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : ../%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : ../%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/rtw/c/tornado/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@echo Building file $@...
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ $(@:.o=.c)

###################################
$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating $@ "
	@$(AR) r $@ $(SHARED_OBJS)
	@$(ARCHIVER_TOOL) -q $@ $(LIBRARY_OPTS) $(SHARED_OBJS) > $@.lst
	@echo "### $@ Created "


###################################

$(LIB_TEMP)/%.o: $(MATLAB_ROOT)\rtw\c\src/%.c
	@echo ### "$(MATLAB_ROOT)\rtw\c\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<
$(PLIB_TEMP)/%.o: $(MATLAB_ROOT)\rtw\c\src/%.c
	@echo ### "$(MATLAB_ROOT)\rtw\c\src\$*.c"
	@$(COMPILE_TOOL) $(COMPILE_TOOL_OPTS) $(CFLAGS) -o $@ -c $<





###################################

                                                                          

###################################


# EOF: rappid_metrowerks.tmf
