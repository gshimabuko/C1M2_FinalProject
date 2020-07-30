#include <stdint.h>
#include "data.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    int length = 1;
    int digit = 0;
    if (data == 0)
    {
        *ptr = 48;
    }
    else if(data < 0){
        *ptr = 45;
        length++;
        data = data * (-1);
    }
    while ( data > 0){
        digit = data % base;
        data = data / base;
        if (digit > 9){
            *(ptr + length - 1) = digit + 55;
        }
        else{
            *(ptr + length - 1) = digit + 48;
        }
        length++;
    }
    *(ptr + length) = '\0';
    return length;
}
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
    return 0;
}

