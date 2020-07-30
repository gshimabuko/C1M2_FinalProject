 ################################################################################
 # @author  Guilherme Shimabuko - Shima's Digital Hardware
 #
 # @brief   Repository for second assignment of Introduction to Embedded Systems
 #          Software and Development Environments:
 #
 # @details This project consisted on the implementation of a makefile that would
 #          receive the platform as a parameter and perform the appropriate
 #          compilation if platform was host or MSP432 ARM.
 #
 # @copyright Copyright (c) 2020 Shima's Digital Hardware
 #
 #     Redistribution and use in source and binary forms, with or without
 #     modification, are permitted provided that the following conditions
 #     are met:
 #     
 #     * Redistributions of source code must retain the above copyright
 #       notice, this list of conditions and the following disclaimer.
 #
 #     * Redistributions in binary form must reproduce the above copyright
 #       notice, this list of conditions and the following disclaimer in the
 #       documentation and/or other materials provided with the distribution.
 #
 #     * Neither the name of Shima's DIgital Hardware  nor the names of its
 #       contributors may be used to endorse or promote products
 #       derived from this software without specific prior written permission.
 #
 #     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 #     IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 #     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTI-
 #     CULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SHIMA'S DIGITAL HARDWARE
 #     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 #     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 #     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 #     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 #     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 #     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 #     THE POSSIBILITY OF SUCH DAMAGE.
 #
 ################################################################################
 

#------------------------------------------------------------------------------
# Makefile for Second Assignment of Introduction to Embedded Systems Software
# and Development Environments. 
#
# Use: make[TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       MSP432 - MSP-EXP432P401R LaunchPad
#       HOST - Linux (tested on x86 architecture)
#
# Platform Overrides:
#       PLATFORM=MSP432 - Starts makefile with MSP432 platform
#       PLATFORM=HOST - Starts makefile with linux platform
# VERBOSE Override:
#       VERBOSE=ENABLED - Enables debug printing
# COURSE Override:
#       COURSE=COURSE1 - Runs course1.c functions to test programme
#
#------------------------------------------------------------------------------
include sources.mk
COURSE = NULL
TARGET = src/c1m2
PLATFORM = HOST
OBJS = $(SOURCES:.c=.o)
GFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -E
DEPS = $(SOURCES:.c=.d)
# Platform Overrides
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE = msp432p401r.lds
	LDFLAGS =  -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	FPU = fpv4-sp-d16
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m \
            -mfloat-abi=hard -mfpu=$(FPU) -D$(PLATFORM)
	OBJDUMP = arm-none-eabi-objdump

	SIZE = arm-none-eabi-size
else
	CC = gcc
	LD = ld
	LDFLAGS =  -Wl,-Map=$(TARGET).map
	CFLAGS = $(GFLAGS) -D$(PLATFORM)
	SIZE = size
	OBJDUMP = objdump
endif

ifeq ($(COURSE), COURSE1)
	DFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE), ENABLE)
	DFLAGS += -DVERBOSE
endif

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) $(DFLAGS) -o $@
%.i: %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) $(DFLAGS) -o $@
%.asm: %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) $(DFLAGS) -o $@
%.d: %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) $(DFLAGS) -o $@

.PHONY: all
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@.out

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) $(CFLAGS) $(DFLAGS) $(LDFLAGS) -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: clean
clean:
	rm -f src/*.o src/*.i src/*.map src/*.out src/*.asm src/*.d

