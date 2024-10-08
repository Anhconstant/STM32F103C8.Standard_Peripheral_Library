##################################################
# Edited by Tran Tuan Anh
# github : anhconstant 
##################################################
######################################
# target
######################################
TARGET = template
######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og
#######################################
# paths
GCC_PATH := C:/gcc-arm/bin
#######################################
# Build path
BUILD_DIR = build
######################################
# source
######################################
# C sources
C_SOURCES =  
C_SOURCES += Src/main.c 
C_SOURCES += Src/stm32f10x_it.c 
C_SOURCES += Src/system_stm32f10x.c  
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/misc.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_adc.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_bkp.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_can.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_cec.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_crc.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_dac.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_dbgmcu.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_flash.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_fsmc.c 
C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_iwdg.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_pwr.c 
C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_rtc.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_sdio.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c 
# C_SOURCES += Drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_wwdg.c 


# ASM sources
ASM_SOURCES =  \
startup_stm32f103xb.s


#######################################
# binaries
#######################################

PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DSTM32F10X_MD \
-DUSE_STDPERIPH_DRIVER


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-IInc \
-IDrivers/STM32F10x_StdPeriph_Driver/inc \
-IDrivers/CMSIS/Device/ST/STM32F1xx/Include \
-IDrivers/CMSIS/Include


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F103C8Tx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@

#######################################
# st-flash added by Ngo Hung Cuong
#######################################		
flash: $(BUILD_DIR)/$(TARGET).bin
	st-flash write $< 0x08000000
#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***