#include <stdint.h>
#include "data.h"
#include "memory.h"
#include <stdio.h>
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
        printf("Dividing data: %d\n", data);
        digit = data % base;
        printf("Remainder is: %d\n", digit);
        data = data / base;
        printf("Division result is %d\n", data);
        if (digit > 9){
            *(ptr + length) = digit + 55;
        }
        else{
            *(ptr + length) = digit + 48;
        }
        printf("new digit is: %d\n", *(ptr + length));
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
        printf("negative");
        stop = 1;
    }
    while(i >= stop){
        if ((*(ptr + i) <= 57) && (*(ptr + 1) >= 48))
        {
            for(j = digits - i - 1; j > 0; j--)
            {
                printf("j is: %d \n", j);
                power = power*base;
                printf("power is: %d \n", power);
            }
            printf("digit is %d\n", *(ptr + i) - 48);
            data = data + ((*(ptr + i) - 48) * power);
            power = 1;
            printf("Data is %d\n", data);
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

