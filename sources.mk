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

# Add your Source files to this variable
ifeq ($(PLATFORM), MSP432)
	SOURCES =   src/main.c \
				src/memory.c \
	            src/data.c \
				src/stats.c \
				src/interrupts_msp432p401r_gcc.c \
                src/startup_msp432p401r_gcc.c \
				src/system_msp432p401r.c \
				src/course1.c
else
	SOURCES =   src/main.c \
				src/memory.c \
	            src/data.c \
	            src/stats.c \
	            src/course1.c

endif

# Add your include paths to this variable
ifeq ($(PLATFORM), MSP432)
	INCLUDES =  -I ./include/CMSIS \
				-I ./include/common \
				-I ./include/msp432 \
                -I ./
else
	INCLUDES =  -I ./include/common
endif
