/******************************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************************/
/**
 * @file stats.h
 * @brief Includes all function declarations and documentation
 *
 * This header file contains the function declaration (and the their descriptions)
 * which will be envoked from the stats.c file, hence included.
 * The primary aim of the comments is to achieve documentation.
 *
 * @author Armin Etedali
 * @date July 2023
 *
 */


#ifndef __STATS_H__
#define __STATS_H__



/**
 * @brief Find the mean value of a set of numbers
 *
 * Declaration of the function which takes as input a pointer which references
 * to an array with it's length, a set of numbers and finds it's arithmetic mean value.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the mean value from the given data set
 */
int find_mean(unsigned char * ptr, int length);



/**
 * @brief Find the median value of a set of numbers
 *
 * Declaration of the function which takes as input
 * a set of given numbers and finds it's median value.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the median value from the given data set
 */
int find_median(unsigned char * ptr, int length);



/**
 * @brief Find the minimum value of a set of numbers
 *
 * Declaration of the function which takes as input
 * a set of given numbers and finds the minimum value of the array.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the minimum value from the given data set
 */
int find_minimum(unsigned char * ptr, int length);



/**
 * @brief Find the maximum value of a set of numbers
 *
 * Declaration of the function which takes as input
 * a set of given numbers and finds the meximum value of the array.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the maximum value from the given data set
 */
int find_maximum(unsigned char * ptr, int length);



/**
 * @brief Sort the elements of a given set of numbers
 *
 * Given an array of numbers and a length, this function sorts the array from
 * largest to smallest.
 * The output (print) takes place in a consistent formatting.
 * Two parameters, the value of each element and it's associated index
 * will be passed to the print_array function.
 * The formatting takes care of both, indicating the index it occupies
 * in the sequence within the data set and it's associated value,
 * with respect of the integer number of tens (place value) e.g. 1, 10 , 100 etc.
 * The zeroth element represents the largest number of the data set and
 * the last element (n-1) contains the smallest value.
 * The resulting array does not touch / change the original data array,
 * instead creates a sorted version of it as an new array.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param unsigned int An unsigned integer as the size of the array
 *
 * @return An unsigned pointer to the sorted array
 */
unsigned char * sort_array(unsigned char * ptr, int length);



/**
 * @brief Sort the elements of a given set of numbers
 *
 * This function prints a value which was passed to it to the terminal.
 * The value was carried out from other functions of the program based on
 * statistical context.
 * If with the value an associated index was detemined, the output will then
 * be formatted with the help of the second parameter (index).
 * The formatting takes care of both, indicating the index it occupies
 * in the sequence within the data set and it's associated value,
 * with respect of the integer number of tens (place value) e.g. 1, 10 , 100 etc.
 * 
 * @param int An integer which holds the value of each statistical evaluation
 * @param int An integer which prints the index of the value comes with it
 */
void print_statistics(int value, int index);



/**
 * @brief Prints the elements of a given set of numbers as an array
 *
 * Given an array of numbers and a length, this function prints the data set.
 * The output (print) takes place in a consistent formatting.
 * Two parameters, the value of each element and it's associated index
 * will be passed to the print_array function.
 * The formatting takes care of both, indicating the index it occupies
 * in the sequence within the data set and it's associated value,
 * with respect of the integer number of tens (place value) e.g. 1, 10 , 100 etc.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param unsigned int An unsigned integer as the size of the array
 *
 * @return An unsigned pointer to the sorted array
 */
void print_array(unsigned char * array, int length);





#endif /* __STATS_H__ */
