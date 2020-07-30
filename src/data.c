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
 * @file    data.c
 * @brief   Memory manipulation functions
 *
 * @details This file implements functions to manipulate data for the final
 *          project of Introduction to Embedded Systems Software and Developement
 *          Environments. Below, information on the function 
 *          will be detailed including the author of each function.
 *
 *          Functions:
 *              1.  my_itoa - Receives integer in decimal base, converts it to
 *                  any base upto hexadecimal, and transforms it into an ASCII
 *                  string.
 *                  By Guilherme Shimabuko
 *              2.  my_atoi - Receives pointer to ASCII string and converts it to
 *                  integer in decimal base.
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
#include <stdint.h>
#include "data.h"
#include "memory.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    int length = 0;
    int digit = 0;
    int neg = 0;
    
    if (data == 0)
    {
        *ptr = 48;
    }
    else if(data < 0){
        *ptr = 45;
        length++;
        data = data * (-1);
        neg = 1;
    }
    else
    {
        
    }
    while ( data > 0){
        digit = data % base;
        data = data / base;
        if (digit > 9){
            *(ptr + length) = digit + 55;
        }
        else{
            *(ptr + length) = digit + 48;
        }
        length++;
    }
    *(ptr + length) = '\0';
    if (neg == 0){
        my_reverse(ptr, length);
    }
    else{
        my_reverse((ptr + 1), length - 1);
    }
    return length;
}
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
    int32_t data = 0;
    int i = digits - 1;
    int stop = 0;
    int j = 0;
    int power = 1;
    if(!ptr)
    {
        return -1;
    }
    else if(*(ptr) == 45)
    {
        stop = 1;
    }
    while(i >= stop){
        if ((*(ptr + i) <= 57) && (*(ptr + 1) >= 48))
        {
            for(j = digits - i - 1; j > 0; j--)
            {
                power = power*base;
            }
            data = data + ((*(ptr + i) - 48) * power);
            power = 1;
        }
        else if ((*(ptr + i) <= 70) && (*(ptr + 1) >= 65))
        {
            data += (*(ptr + i) - 55) * base;
        }
        i--;
    }
    if (stop == 1){
        data = (-1)*data;
    }
    return data;
}

