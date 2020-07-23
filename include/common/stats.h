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
 * @file stats.h
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
#ifndef __STATS_H__
#define __STATS_H__


int print_statistics(unsigned char test[], int size);
/**
 * @brief prints dataset statistics
 *
 * @details Receives dataset and size and call statistics functions and print
 *          their results. Mean is truncated to 2 decimal points.
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return <int> returns 0 at the end of function
 */

int print_array(unsigned char test[], int size);
/**
 * @brief prints dataset given array and array size
 *
 * @details Receives dataset and size and prints the dataset
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return int      returns 0 at the end of function
 */

int find_median(unsigned char test[], int size);
/**
 * @brief finds median of dataset
 *
 * @details Finds median of dataset having received ordered array.
 *          If dataset contains an odd number of data pieces, the median will be
 *          the number in the middle of the set.
 *          If dataset contains an even number of data pieces, the median will be
 *          the average between the two middlemost data pieces.
 *          If the average is not an integer, it will be truncated.
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return int      returns median value
 */

float find_mean(unsigned char test[], int size);
/**
 * @brief finds dataset mean
 *
 * @details Finds mean of dataset by suming all elements and then dividing then
 *          by the dataset size.
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return <mean> returns mean value
 */

int find_maximum(unsigned char test[], int size);
/**
 * @brief finds dataset maximum element
 *
 * @details Scans whole dataset to find largest data.
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return maximum  returns largest element
 */

int find_minimum(unsigned char test[], int size);
/**
 * @brief finds dataset smallest element
 *
 * @details Scans whole dataset to find samallest data element.
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return minimum  returns smallest value
 */

unsigned char * sort_array(unsigned char test[], int size);
/**
 * @brief orders dataset from largest to smallest
 *
 * @details Implementation based on the quicksort algorithm to order array of data
 * from largest to smallest element.
 *
 * @param test[]    char array containing dataset
 * @param size      int variable containing dataset size
 *
 * @return unsigned char *   returns pointer to sorted array
 */

unsigned char * quicksort (unsigned char test[], int first, int last);
/**
 * @brief orders dataset from largest to smallest
 *
 * @details This implmentation is created as an internal function as a mean to
 *          facilitate recursion without the use of dynamic memory allocation.
 *          It is a mixture of bubble sort, quicksort and heapsort, all in one
 *          single algorithm.
 *
 * @param test[]    char array containing dataset
 * @param first     int variable containing first index of interest
 *
 * @return unsigned char *   returns pointer to sorted array
 */
#endif /* __STATS_H__ */
