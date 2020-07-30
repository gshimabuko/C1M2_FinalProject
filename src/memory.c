/*********************************************************************************
 * @copyright Copyright (c) 2020 by Guilherme Shimabuko - Shima's Digital Hardware
 *
 *     Redistribution and use in source and binary forms, with or without
 *     modification, are permitted provided that the following conditions
 *     are met:
 *     
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of Shima's DIgital Hardware  nor the names of its
 *       contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *     IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTI-
 *     CULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SHIMA'S DIGITAL HARDWARE
 *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 *     THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *********************************************************************************
 *
 * @file memory.c
 * @brief  Memory manipulation functions
 *
 * @details This file implements functions to manipulate memory for the final
 *          project of Introduction to Embedded Systems Software and Developement
 *          Environments. Some of these functions were provided by the instructor,
 *          MSc. Alex Fosdick in the template. Below, information on the function 
 *          will be detailed including the author of each function.
 *
 *          Functions:
 *              1.  set_value - Uses array indexing to load data in a memory space
 *                  By MSc. Alex Fosdick
 *              2.  clear_value - Uses array indexing to clear memory space.
 *                  By MSc. Alex Fosdick       
 *              3.  get_value - Uses array indexing to read from memory.
 *                  By MSc Alex Fosdick
 *              4.  set_all - Uses array indexing to load same value to all memory
 *                  spaces.
 *                  By MSc Alex Fosdick
 *              5.  clear_all - Uses array indexing to clear memory
 *                  By Msc Alex Fosdick
 *              6.  my_memmove - Uses pointer arithmetic to move data from one
 *                  memory location to another.
 *                  By Guilherme Shimabuko
 *              7.  my_memcopy - Uses pointer arithmetic to copy data from one
 *                  memory location to another.
 *                  By Guilherme Shimabuko
 *              8.  my_memset - Uses pointer arithmetic to load data to a memory
 *                  location
 *                  By Guilherme Shimabuko
 *              9.  my_memzero - Uses pointer arithmetic to zero out the memory
 *                  By Guilherme Shimabuko
 *              10. my_reverse - Uses pointer arithmetic to reverse the order of
 *                  bytes in a memory location.
 *                  By Guilherme Shimabuko
 *              11. reserve_words - Uses pointer arithmetic to allocate dynamic
 *                  memory.
 *                  By Guilherme Shimabuko
 *              12. free_words - Uses pointer arithmetic to free memory
 *                  By Guilherme Shimabuko
 *
 * @author Alex Fosdick
 * @author Guilherme Shimabuko
 * 
 * date in yy-mm-dd format
 *
 * @date 2020-30-07
 *
 *********************************************************************************
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}


void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
    int i = 0;
    uint8_t size = (int) length;
    uint8_t *tmp;
    tmp = (uint8_t *) malloc(length*sizeof(uint8_t));
    for (i = 0; i < size; i++)
    {
        *(tmp + i) = *(src + i);
    }
    for (i = 0; i < size; i++)
    {
        *(dst + i) = *(tmp + i);
    }
    free(tmp);
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
    int i = 0;
    uint8_t size = (int) length;
    for (i = 0; i < size; i++)
    {
        *(dst + i) = *(src + i);
    }
    return dst;
}
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
    int i = 0;
    uint8_t size = (int) length;
    for (i = 0; i < size; i++)
    {
        *(src + i) = value;
    }
    return src;
}
uint8_t * my_memzero(uint8_t * src, size_t length){
    src = my_memset(src, length, 0);
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
    int i = 0;
    uint8_t size = (uint8_t) length;
    uint8_t temp;
    while(i < size - i - 1)
    {
        temp = *(src + i);
        *(src + i) = *(src + size - i - 1);
        *(src + size - i - 1) = temp;
        i++;
    }
    return src;
}

uint32_t * reserve_words (size_t length){
    uint32_t *ptr;
    ptr = (uint32_t *) malloc(length * sizeof(uint32_t));
    return ptr;
}

void free_words(uint32_t * src){
    free(src);
}
