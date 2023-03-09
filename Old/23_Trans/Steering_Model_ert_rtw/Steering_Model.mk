###########################################################################
## Makefile generated for component 'Steering_Model'. 
## 
## Makefile     : Steering_Model.mk
## Generated on : Wed Feb 08 15:48:48 2023
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Steering_Model.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = Steering_Model
MAKEFILE                  = Steering_Model.mk
MATLAB_ROOT               = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2022b
MATLAB_BIN                = $(MATLAB_WORKSPACE)/C/Program_Files/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = $(MATLAB_WORKSPACE)/C/Git/2023_Tractor_Plant_Models/23_Trans
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
LIBSSC_SLI_OBJS           = ./ssc_sli_0267402d.c.o ./ssc_sli_0763c151.c.o ./ssc_sli_0bd269e6.c.o ./ssc_sli_0d6d0780.c.o ./ssc_sli_136b443c.c.o ./ssc_sli_136f97a1.c.o ./ssc_sli_140b3534.c.o ./ssc_sli_15d5f6ce.c.o ./ssc_sli_1c690f90.c.o ./ssc_sli_1db813e8.c.o ./ssc_sli_256cd4b6.c.o ./ssc_sli_2bbd58a4.c.o ./ssc_sli_2f6ea1cd.c.o ./ssc_sli_360cfd63.c.o ./ssc_sli_3fb4607e.c.o ./ssc_sli_40d56d93.c.o ./ssc_sli_42b14021.c.o ./ssc_sli_43618287.c.o ./ssc_sli_466b08dd.c.o ./ssc_sli_496799bd.c.o ./ssc_sli_4e028390.c.o ./ssc_sli_51dbd3b5.c.o ./ssc_sli_550a4805.c.o ./ssc_sli_5a0cb974.c.o ./ssc_sli_5d63aeeb.c.o ./ssc_sli_62d81790.c.o ./ssc_sli_6305062f.c.o ./ssc_sli_77063d8b.c.o ./ssc_sli_7a618260.c.o ./ssc_sli_7f65db03.c.o ./ssc_sli_880e593a.c.o ./ssc_sli_89d0f30a.c.o ./ssc_sli_8a64c4e2.c.o ./ssc_sli_93019ea6.c.o ./ssc_sli_9abcdb7f.c.o ./ssc_sli_9b67747c.c.o ./ssc_sli_9c030181.c.o ./ssc_sli_c7dda239.c.o ./ssc_sli_d064c978.c.o ./ssc_sli_d80c44d2.c.o ./ssc_sli_dcd66f69.c.o ./ssc_sli_e66fe6d5.c.o ./ssc_sli_e7b327bb.c.o ./ssc_sli_eb0a5702.c.o ./ssc_sli_edbee55c.c.o ./ssc_sli_f6bd9cc8.c.o ./ssc_sli_f9b5dbc5.c.o ./ssc_sli_fa0ce53e.c.o ./ssc_sli_fbdf29da.c.o
LIBSSC_CORE_OBJS          = ./ssc_core_01dcc633.c.o ./ssc_core_04da2c69.c.o ./ssc_core_05058dd9.c.o ./ssc_core_06ba68a6.c.o ./ssc_core_09b5fa6e.c.o ./ssc_core_0bd666aa.c.o ./ssc_core_0d65be6c.c.o ./ssc_core_0f019bd9.c.o ./ssc_core_0f0420a6.c.o ./ssc_core_18bf4d77.c.o ./ssc_core_1b0cafd5.c.o ./ssc_core_1c6b0332.c.o ./ssc_core_1fd25120.c.o ./ssc_core_24b4cdee.c.o ./ssc_core_2568b075.c.o ./ssc_core_280c0222.c.o ./ssc_core_2cd54448.c.o ./ssc_core_3169e4b7.c.o ./ssc_core_32d8b307.c.o ./ssc_core_3306c008.c.o ./ssc_core_360a4baf.c.o ./ssc_core_37d4ea84.c.o ./ssc_core_40db642d.c.o ./ssc_core_40dfdbdc.c.o ./ssc_core_41017299.c.o ./ssc_core_4666b45b.c.o ./ssc_core_48b08af1.c.o ./ssc_core_48b1386a.c.o ./ssc_core_4965213d.c.o ./ssc_core_4ad9135b.c.o ./ssc_core_4db6bd68.c.o ./ssc_core_4db86fcc.c.o ./ssc_core_4e03e39d.c.o ./ssc_core_4e04eecd.c.o ./ssc_core_4e06e3bd.c.o ./ssc_core_54d55ae9.c.o ./ssc_core_5505224d.c.o ./ssc_core_550b4c41.c.o ./ssc_core_56b1a2bf.c.o ./ssc_core_576cd129.c.o ./ssc_core_59b034b8.c.o ./ssc_core_5a046b27.c.o ./ssc_core_5d6ba758.c.o ./ssc_core_67d1f118.c.o ./ssc_core_68da074b.c.o ./ssc_core_6b663a17.c.o ./ssc_core_6b6b89d2.c.o ./ssc_core_6dd833f3.c.o ./ssc_core_7209d3a5.c.o ./ssc_core_73d9c2b7.c.o ./ssc_core_76d825be.c.o ./ssc_core_770cead7.c.o ./ssc_core_79dd08ab.c.o ./ssc_core_7a613edb.c.o ./ssc_core_83db8762.c.o ./ssc_core_856738f2.c.o ./ssc_core_8569edc5.c.o ./ssc_core_89d7fa79.c.o ./ssc_core_8a6471dc.c.o ./ssc_core_8cd9cb37.c.o ./ssc_core_8d0064b8.c.o ./ssc_core_96061071.c.o ./ssc_core_97d767fe.c.o ./ssc_core_990fe1a4.c.o ./ssc_core_9b607b15.c.o ./ssc_core_9b671e57.c.o ./ssc_core_9c016445.c.o ./ssc_core_9c01d168.c.o ./ssc_core_9dd110ad.c.o ./ssc_core_9fb0e229.c.o ./ssc_core_9fb25b4f.c.o ./ssc_core_9fb2e56c.c.o ./ssc_core_a1d393be.c.o ./ssc_core_a269ab09.c.o ./ssc_core_a4d4c45e.c.o ./ssc_core_a4da1d0a.c.o ./ssc_core_a6b78ccc.c.o ./ssc_core_a76299bc.c.o ./ssc_core_a867d880.c.o ./ssc_core_a9bbaecc.c.o ./ssc_core_a9bf1ff2.c.o ./ssc_core_aa09f23c.c.o ./ssc_core_abd05c18.c.o ./ssc_core_abd5e7b4.c.o ./ssc_core_acb64294.c.o ./ssc_core_acb6462e.c.o ./ssc_core_b1038cbb.c.o ./ssc_core_b10e34f4.c.o ./ssc_core_b2b3b239.c.o ./ssc_core_b369cd13.c.o ./ssc_core_b402b40d.c.o ./ssc_core_b7b88213.c.o ./ssc_core_b96ebc21.c.o ./ssc_core_bad68669.c.o ./ssc_core_bc648043.c.o ./ssc_core_bfdb08db.c.o ./ssc_core_c3003040.c.o ./ssc_core_c5b050d7.c.o ./ssc_core_c5b63cb2.c.o ./ssc_core_c607b660.c.o ./ssc_core_c8d83e88.c.o ./ssc_core_cab615c8.c.o ./ssc_core_cabdc251.c.o ./ssc_core_cc067f58.c.o ./ssc_core_cc0bcab0.c.o ./ssc_core_ce6a84bb.c.o ./ssc_core_d06d763c.c.o ./ssc_core_d3d34d7c.c.o ./ssc_core_d4b9397b.c.o ./ssc_core_d70a6a09.c.o ./ssc_core_d807fa59.c.o ./ssc_core_dcda6edd.c.o ./ssc_core_deb7fd8d.c.o ./ssc_core_e0d0866d.c.o ./ssc_core_e2b61d72.c.o ./ssc_core_e400c1c2.c.o ./ssc_core_ead8f455.c.o ./ssc_core_edb836de.c.o ./ssc_core_ee000fbe.c.o ./ssc_core_ee01086d.c.o ./ssc_core_ee0f0141.c.o ./ssc_core_f9b6dbed.c.o ./ssc_core_fa09e9e6.c.o ./ssc_core_fbd34e62.c.o ./ssc_core_ff06d9a4.c.o
LIBSSC_ST_OBJS            = ./ssc_st_7cd93bb6.c.o ./ssc_st_da6cd8f8.c.o
LIBMC_OBJS                = ./mc_026e4f4b.c.o ./mc_03b98f6f.c.o ./mc_0764157d.c.o ./mc_0bd30dee.c.o ./mc_0d6fd085.c.o ./mc_0ed73c49.c.o ./mc_0edc34e3.c.o ./mc_10d4ab75.c.o ./mc_11086079.c.o ./mc_110e6c6c.c.o ./mc_1407e917.c.o ./mc_140e3c4c.c.o ./mc_15d12d95.c.o ./mc_15d828ca.c.o ./mc_220ba961.c.o ./mc_2565d6e0.c.o ./mc_2a642f54.c.o ./mc_2a6a9b24.c.o ./mc_2a6b417d.c.o ./mc_2bbf87e3.c.o ./mc_2cdc96b4.c.o ./mc_32d501e3.c.o ./mc_32dc008a.c.o ./mc_3b6a945d.c.o ./mc_3e66abdf.c.o ./mc_4105189f.c.o ./mc_47b8cebe.c.o ./mc_47b91db1.c.o ./mc_4b0301c6.c.o ./mc_4c6117e3.c.o ./mc_51d4094e.c.o ./mc_52623861.c.o ./mc_52688a58.c.o ./mc_53b1fc84.c.o ./mc_53b6fcf3.c.o ./mc_550847c3.c.o ./mc_5766048f.c.o ./mc_59b6e413.c.o ./mc_5bd2c9c1.c.o ./mc_5d65cd86.c.o ./mc_5edd42ef.c.o ./mc_630208f8.c.o ./mc_630dda0e.c.o ./mc_67da200d.c.o ./mc_67da4f41.c.o ./mc_6b6d311a.c.o ./mc_6e61d16c.c.o ./mc_6fb1c336.c.o ./mc_7207b6f4.c.o ./mc_7809a65c.c.o ./mc_7a613aec.c.o ./mc_7bbf41f0.c.o ./mc_7cd58f0b.c.o ./mc_7cdbe436.c.o ./mc_7d0547c8.c.o ./mc_7d099de7.c.o ./mc_7eb21b39.c.o ./mc_81b0ada5.c.o ./mc_81b5717e.c.o ./mc_84b5f9fb.c.o ./mc_870ec75e.c.o ./mc_89d597cf.c.o ./mc_90b6aa0a.c.o ./mc_95b62b73.c.o ./mc_9ab7d9b0.c.o ./mc_9b6376d1.c.o ./mc_9b6c1529.c.o ./mc_a00e5f46.c.o ./mc_a2647600.c.o ./mc_a26bab1a.c.o ./mc_a3b90582.c.o ./mc_a6b5ed24.c.o ./mc_a7684938.c.o ./mc_a865d1dd.c.o ./mc_acb3fad7.c.o ./mc_af0bc203.c.o ./mc_af0cc4c9.c.o ./mc_b0de9cbc.c.o ./mc_b2b86ae3.c.o ./mc_b362c5eb.c.o ./mc_b7b03d44.c.o ./mc_b96a0bad.c.o ./mc_bb0520ee.c.o ./mc_bdbb9b78.c.o ./mc_c2dbf4b2.c.o ./mc_c7de7352.c.o ./mc_c8d25d23.c.o ./mc_cab8a1f9.c.o ./mc_ce6656ce.c.o ./mc_d20085b7.c.o ./mc_d9d38185.c.o ./mc_dbbb14d2.c.o ./mc_dcdddfae.c.o ./mc_debb448f.c.o ./mc_e7b99cf6.c.o ./mc_e7bc2f1a.c.o ./mc_e9661c4a.c.o ./mc_e969ae87.c.o ./mc_edbf543c.c.o ./mc_ee000fbe.c.o ./mc_efdea3a7.c.o ./mc_f0012953.c.o ./mc_f00d2f9b.c.o ./mc_f3be157c.c.o ./mc_fbd54145.c.o ./mc_fcb15a9b.c.o ./mc_fd619d14.c.o ./mc_fd6341bb.c.o
LIBEX_OBJS                = ./ex_04d5441d.c.o ./ex_0d6d0784.c.o ./ex_136645f8.c.o ./ex_17bc61ac.c.o ./ex_18b4440a.c.o ./ex_1b03ca17.c.o ./ex_2ebcd5b2.c.o ./ex_316a81de.c.o ./ex_36012fa7.c.o ./ex_40d5be33.c.o ./ex_47b11894.c.o ./ex_57660158.c.o ./ex_690b7cd0.c.o ./ex_6dd8e72d.c.o ./ex_770385e6.c.o ./ex_79d100f1.c.o ./ex_8a6fc761.c.o ./ex_98d223a6.c.o ./ex_aed5de1e.c.o ./ex_b2b40ad5.c.o ./ex_bb0efd4b.c.o ./ex_bfdb009c.c.o ./ex_c9069dae.c.o ./ex_d9d686a8.c.o ./ex_debffef2.c.o ./ex_e40d74b8.c.o ./ex_eb0d559b.c.o ./ex_f6bb4c2d.c.o ./ex_f866102d.c.o ./slu_stubbed_definitions.c.o
LIBPM_OBJS                = ./pm_09bc42e2.c.o ./pm_14098e54.c.o ./pm_26dc3230.c.o ./pm_4fd5f5b9.c.o ./pm_9dd7a82d.c.o ./pm_fed8c2c9.c.o

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU GCC Embedded Linux
# Supported Version(s):    
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

CCOUTPUTFLAG = --output_file=
LDOUTPUTFLAG = --output_file=

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lm -lstdc++

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU GCC Embedded Linux Assembler
AS = as

# C Compiler: GNU GCC Embedded Linux C Compiler
CC = gcc

# Linker: GNU GCC Embedded Linux Linker
LD = gcc

# C++ Compiler: GNU GCC Embedded Linux C++ Compiler
CPP = g++

# C++ Linker: GNU GCC Embedded Linux C++ Linker
CPP_LD = g++

# Archiver: GNU GCC Embedded Linux Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE = make


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = -r
ASFLAGS              = -c \
                       $(ASFLAGS_ADDITIONAL) \
                       $(INCLUDES)
CFLAGS               = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -O2
CPPFLAGS             = -c \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -fpermissive  \
                       -O2
CPP_LDFLAGS          = -lrt -lpthread -ldl
CPP_SHAREDLIB_LDFLAGS  = -shared  \
                         -lrt -lpthread -ldl
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -lrt -lpthread -ldl
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j$(($(nproc)+1)) -Otarget -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared  \
                       -lrt -lpthread -ldl



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Steering_Model.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/Steering_Model_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/extern/physmod/win64/ex/include -I$(MATLAB_ROOT)/extern/physmod/win64/lang/include -I$(MATLAB_ROOT)/extern/physmod/win64/mc/include -I$(MATLAB_ROOT)/extern/physmod/win64/pd/include -I$(MATLAB_ROOT)/extern/physmod/win64/pm/include -I$(MATLAB_ROOT)/extern/physmod/win64/pm_log/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_comp/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_core/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_ds/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/include -I$(MATLAB_ROOT)/extern/physmod/win64/ssc_st/include -I$(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/realtime/targets/raspi/include -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -I$(MATLAB_ROOT)/toolbox/target/codertarget/rtos/inc

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_CAN_BITRATE=500000 -DMW_CAN_ALLOWALLMSGS=1
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=Steering_Model -DNUMST=2 -DNCSTATES=10 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_zc.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_il.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_all.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_act.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_exp.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_log.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_dxf.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_mode.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_f.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_duf.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_assert.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_gateway.c $(START_DIR)/Steering_Model_ert_rtw/rt_backsubrr_dbl.c $(START_DIR)/Steering_Model_ert_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/Steering_Model_ert_rtw/rt_lu_real.c $(START_DIR)/Steering_Model_ert_rtw/rt_matrixlib_dbl.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model.c $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_data.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/realtime/targets/raspi/src/MW_raspi_init.c $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/realtime/targets/raspi/src/periphs/MW_Pyserver_control.c $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c

MAIN_SRC = $(START_DIR)/Steering_Model_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Steering_Model_836bb176_1_ds.c.o Steering_Model_836bb176_1_ds_zc.c.o Steering_Model_836bb176_1_ds_obs_il.c.o Steering_Model_836bb176_1_ds_obs_all.c.o Steering_Model_836bb176_1_ds_obs_act.c.o Steering_Model_836bb176_1_ds_obs_exp.c.o Steering_Model_836bb176_1_ds_log.c.o Steering_Model_836bb176_1_ds_dxf.c.o Steering_Model_836bb176_1_ds_mode.c.o Steering_Model_836bb176_1_ds_f.c.o Steering_Model_836bb176_1_ds_duf.c.o Steering_Model_836bb176_1_ds_assert.c.o Steering_Model_836bb176_1.c.o Steering_Model_836bb176_1_gateway.c.o rt_backsubrr_dbl.c.o rt_forwardsubrr_dbl.c.o rt_lu_real.c.o rt_matrixlib_dbl.c.o Steering_Model.c.o Steering_Model_data.c.o MW_raspi_init.c.o MW_Pyserver_control.c.o linuxinitialize.c.o

MAIN_OBJ = ert_main.c.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = ./ssc_sli.lib ./ssc_core.lib ./ssc_st.lib ./mc.lib ./ex.lib ./pm.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL =  
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL =  
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL =  

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL =  

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL =  

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL =  

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.c.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(START_DIR)/Steering_Model_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(START_DIR)/Steering_Model_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(START_DIR)/Steering_Model_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.c.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.s.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.cpp.o : $(MATLAB_ROOT)/extern/physmod/win64/ssc_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_zc.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_zc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_obs_il.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_il.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_obs_all.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_obs_act.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_act.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_obs_exp.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_obs_exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_log.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_log.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_dxf.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_dxf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_mode.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_mode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_f.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_f.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_duf.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_duf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_ds_assert.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_ds_assert.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_836bb176_1_gateway.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_836bb176_1_gateway.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.c.o : $(START_DIR)/Steering_Model_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_backsubrr_dbl.c.o : $(START_DIR)/Steering_Model_ert_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_forwardsubrr_dbl.c.o : $(START_DIR)/Steering_Model_ert_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_lu_real.c.o : $(START_DIR)/Steering_Model_ert_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_matrixlib_dbl.c.o : $(START_DIR)/Steering_Model_ert_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Steering_Model_data.c.o : $(START_DIR)/Steering_Model_ert_rtw/Steering_Model_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_raspi_init.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/realtime/targets/raspi/src/MW_raspi_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_Pyserver_control.c.o : $(MATLAB_WORKSPACE)/C/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/realtime/targets/raspi/src/periphs/MW_Pyserver_control.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linuxinitialize.c.o : $(MATLAB_ROOT)/toolbox/target/codertarget/rtos/src/linuxinitialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

./ssc_sli.lib : $(LIBSSC_SLI_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_SLI_OBJS)


./ssc_core.lib : $(LIBSSC_CORE_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_CORE_OBJS)


./ssc_st.lib : $(LIBSSC_ST_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_ST_OBJS)


./mc.lib : $(LIBMC_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBMC_OBJS)


./ex.lib : $(LIBEX_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBEX_OBJS)


./pm.lib : $(LIBPM_OBJS)
	echo "### Creating static library $@ ..."
	$(AR) $(ARFLAGS)  $@ $(LIBPM_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.c.dep
	$(RM) *.cpp.dep
	$(ECHO) "### Deleted all derived files."


