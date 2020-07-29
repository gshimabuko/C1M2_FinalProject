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
 *
 * @file stats.c 
 * @brief Implementation of functions to perform statistical analysis of data
 *
 * @details This file implements functions to analyse an array of unsigned
 *          data items and report analytics on the maximum, minimum, mean and
 *          median of the data set.
 *          There is also a recursive implementation of a sorting function based
 *          on the quicksort algorithm to order the array from largest to smallest
 *          element.
 *
 *          The implemented functions are as followed:
 *              1. main() - Main entry point for the programme;
 *              2. print_statistics() - Prints all statistics of a dataset;
 *              3. print_array() - Prints the dataset given an array and length;
 *              3. find median() - Returns median of dataset;
 *              4. find_mean() - Returns mean of dataset;
 *              5. find_maximum - returns maximum of dataset;
 *              6. find mininmum - returns minimum of dataset;
 *              7. sort_array - Sort array using recursive quicksort.
 *
 * @author Guilherme Shimabuko
 * 
 * date in yy-mm-dd format
 *
 * @date 2020-09-07
 *
 *********************************************************************************
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                 7,  87, 250, 230,  99,   3, 100,  90};
    print_array(test, SIZE);
    print_statistics(test, SIZE);
    return 0;
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

int print_statistics(unsigned char test[], int size) {
    int i;
    unsigned char sorted[size];
    *sorted = *sort_array(test,size);
    print_array(test, SIZE);
    printf("Median: %d\n", find_median(test, size));
    printf("Average: %.2f\n", find_mean(test, size));
    printf("Maximum: %d\n", find_maximum(test, size));
    printf("Minimum: %d\n", find_minimum(test, size));
    return 0;
}
int print_array(unsigned char test[], int size) {
    #ifdef DVERBOSE
        int i;
        for (i = 0; i < size; i++)
        {
            printf("%d ",test[i]);
        }
        printf("\n");
    #endif
    return 0;
}
int find_median(unsigned char test[], int size) {
    int medianElement = 0;
    medianElement = size/2;
    if (size % 2 != 0 )
    {
        return(test[medianElement]);
    }else
    {
        return((test[medianElement - 1] + test[medianElement])/2);
    }
}
float find_mean(unsigned char test[], int size) {
    int i;
    float average = 0;
    for (i = 0; i < size; i++)
    {
        average = average + test[i];
    }
    average = average/size;
    return average;
}
int find_maximum(unsigned char test[], int size) {
    int i;
    int maximum = 0;
    for (i = 0; i < size; i++)
    {
        if (test[i] > maximum)
        {
            maximum = test[i];
        }
    }
    return maximum;
}
int find_minimum(unsigned char test[], int size) {
    int i;
    int minimum = 255;
    for (i = 0; i < size; i++)
    {
        if (test[i] < minimum)
        {
            minimum = test[i];
        }
    }
    return minimum;
}
unsigned char * sort_array(unsigned char test[], int size) {
    *test = *quicksort(test, 0, size - 1);
    return (test);
}
unsigned char * quicksort(unsigned char test[], int first, int last){
    int i = first;
    int j = last;
    int k = 0;
    int temp = 0;
    int temp1 = first;
    int temp2 = last;
    int size = last - first + 1;
    int mid = first + size/2;
    int swap = 0;
    int swapMax = 0;
    int swapMin = 0;
    int redo = 0;

    // For size < 2, last and first are the same, therefor, nothing to order
    if(size < 2){
        return(test);
    }
    //for size = 2, array has only two elements to order
    else if(size == 2){
        if (test[first] < test[last]){
	        temp = test[first];
	        test[first] = test[last];
	        test[last] = temp;
	        swap = 1;
	    }
	    return (test);
    }
    else
    {
        //Wait for i or j to converge to mid
	    while((i < mid) && (j > mid))
	    {
            //if no longer at first iteration, tests to see if current left element
            //is larger than last left element (bubble sort behaviour);
            if((i > first) && (test[i] > test[i - 1])){
                temp = test[i - 1];
                test[i - 1] = test[i];
                test[i] = temp;
                swap = 1;
	        }
            //if no longer at first iteration, tests to see if current right 
            //element is smaller than last right element (bubble sort behaviour);
            if((j < last) && (test[j] < test[j + 1])){
                temp = test[j + 1];
                test[j + 1] = test[j];
                test[j] = temp;
                swap = 1;
            }
            //Block below tests for possible relations between current left
            //element, middle element, and current right element. Intention here
            //is ensure that the element in the middle has nothing bigger than it
            //to its right, and nothing smaller to the left (quicksort behaviour).
            //It differs from quicksort because pivot position is fixed, but not
            //its value.
            if (test[i] < test[mid]){
                if(test[mid] < test[j]){
                    temp = test[i];
                    test[i] = test[j];
                    test[j] = temp;
                    swap = 1;
                }
                else if(test[j] < test[i]){
                    temp = test[i];
                    test[i] = test[mid];
                    test[mid] = temp;
                    swap = 1;
                    redo = 1;
           	    }
                else{
                    temp = test[i];
                    test[i] = test[mid];
                    test[mid] = test[j];
                    test[j] = temp;
                    swap = 1;
                    redo = 1;
                }
            }
            else if (test[i] > test[mid]){
                if (test[j] > test[i]){
                    temp = test[i];
                    test[i] = test[j];
                    test[j] = test[mid];
                    test[mid] = temp;
                    swap = 1;
                    redo = 1;
                }
                else if((test[j] > test[mid])){
                    temp = test[mid];
                    test[mid] = test[j];
                    test[j] = temp;
                    swap = 1;
                    redo = 1;
	            }
            }
            //Reapplies bubble sort behaviour in case there was any swap
            if((i > first) && (test[i] > test[i - 1])){
                temp = test[i - 1];
                test[i - 1] = test[i];
                test[i] = temp;
                swap = 1;
            }
            if((j < last) && (test[j] < test[j + 1])){
                temp = test[j + 1];
                test[j + 1] = test[j];
                test[j] = temp;
                swap = 1;
            }
            //checks to see if there's a new max
            if((i > first) && (test[i - 1] > test[temp1])){
                temp1 = i - 1;
                swapMax = 1;
            }
            //checks to see if there is a new min
            if((j < last) && (test[j + 1] < test[temp2])){
                temp2 = j + 1;
                swapMin = 1;
            }
            i++;
            j--;
        }
        if (swapMax == 1)
        {
            temp = test[first];
            test[first] = test[temp1];
            test[temp1] = temp;
        }
        if (swapMin == 1)
        {
           temp = test[last];
            test[last] = test[temp2];
            test[temp2] = temp;
        }
        //finishes sorting in case there were no swaps made
    	if(swap == 0)
	    {
            return(test);
    	}
        //Checks if mid was swapped. If it was, then there may be smaller elements
        //to the left or bigger to the right.
        //if mid was not swapped, there are three elements in position (first, mid
        //and last), so it divides the array in two smaller arrays excluding these
        //elements and starts sorting again (Heapsort behaviour).
	    else if(redo == 0){
            *test = *quicksort(test, first + 1, mid - 1);
            *test = *quicksort(test, mid + 1, last - 1);
            return(test);
	    }
        //if mid was swapped, first and last elements are in position, but mid is
        //not. Must make a new iteration in the full array, minus the first and
        //last elements.
        else{
            *test = *quicksort(test, first + 1, last - 1);
	        return(test);
	    }
    }
}/* Add other Implementation File Code Here */
