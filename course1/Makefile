#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile to generate builds for host or MSP432 
#
# Use: make build PLATFORM=HOST or make build PLATFORM=MSP432
#
# Build Targets (Default - HOST):
# 
# 		make compile-all
# 		
# 		make build PLATFORM=HOST
# 		make build VERBOSE=1 PLATFORM=HOST
# 		make clean PLATFORM=HOST
#
# 		make build PLATFORM=MSP432
# 		make build VERBOSE=1 PLATFORM=432
# 		make clean PLATFORM=MSP432
#
# Platform Overrides:
#
#      HOST or MSP432
#------------------------------------------------------------------------------

# Platform Overrides
PLATFORM ?= HOST

# Import SOURCES and INCLUDES
include sources.mk

# Name of the final target
TARGET = c1

# Conditional check to define CFLAGS
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LINKER_FILE = -T ./msp432p401r.lds
	CPU = -mcpu=cortex-m4
	ARCH_FLAGS = -mthumb \
							 -march=armv7e-m \
							 -mfloat-abi=hard \
							 -mfpu=fpv4-sp-d16 \
							 --specs=nosys.specs
	CPPFLAGS = -DMSP432 -DCOURSE1
	LDFLAGS = $(LINKER_FILE) -Wl,-Map=$(TARGET).map
endif

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CPU =
	ARCH_FLAGS =
	CPPFLAGS = -DHOST -DCOURSE1
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

# Adding verbose option
ifeq ($(VERBOSE),1)
	CPPFLAGS += -DVERBOSE
endif

CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPU) $(ARCH_FLAGS)

# Defining variables to generate files
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
PPFILES = $(SOURCES:.c=.i)
ASMFILES = $(SOURCES:.c=.asm)

# Recipes
%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MMD -MP -MF $*.d -c $< -o $@

# Make commands
.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) -o $@
	size $@

.PHONY: $(TARGET).asm
$(TARGET).asm: $(TARGET).out
	objdump -S $< > $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(DEPS) $(PPFILES) $(ASMFILES) $(TARGET).out $(TARGET).map $(TARGET).asm
