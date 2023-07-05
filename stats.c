/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Basic statistical operation on a set of numbers
 *
 * A C-Programming code that does certain operations on a set of numbers
 * on a statistical bases on the data set in order to print out the desired ouput.
 * 
 * These statistics are for exercise purposes of features in C-Programming which
 * have among structural focus, inferential characteristics, which include:
 *   - Mean (Arithmetic)
 *   - Median
 *   - Minimum
 *   - Maximum
 *   
 * Among functions which precess statistical calculations,other functions take care of:
 *   - Sort the array
 *   - print the array
 *   - print the statistics from the above functions
 *
 * @author Armin Etedali
 * @date July 2023
 *
 */


#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

/* #define NULL (0) */


void main() {

  /* Definition of an array with 40 elements */ 
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  /* Variable Declarations */
int i;
unsigned char *ptr;
ptr = test;


  /* The following section of the code contain Statistics and Printing Functions */
void print_statistics(int value, int index) {
	if (index == (SIZE-1) || index == (SIZE-SIZE)) {		
		if (index >= 0 && index < 10) {
			if (value >= 0 && value < 10) {
				printf("Index:  %d, Value:   %d   \n", index, value);
			} if (value > 9 && value < 100) {
				printf("Index:  %d, Value:  %d   \n", index, value);
			} if (value > 99 && value < 1000) {
				printf("Index:  %d, Value: %d   \n", index, value);
			}

		}
		
		if (index >= 10 && index < 100) {
			if (value >= 0 && value < 10) {
				printf("Index: %d, Value:   %d   \n", index, value);
			} if (value > 9 && value < 100) {
				printf("Index: %d, Value:  %d   \n", index, value);
			} if (value > 99 && value < 1000) {
				printf("Index: %d, Value: %d   \n", index, value);
			}
		}
	} else {
		printf("%d\n", value);
	}

}


/**
 * This function prints a given array, taking into account of the formatting.
 * The formatting takes care of both, indicating the index it occupies
 * in the sequence within the data set and it's associated value,
 * with respect of the integer number of tens (place value) e.g. 1, 10 , 100 etc.
 */
void print_array(unsigned char * array, int length) {

	int i;
	int sum = 0;
	int val = 0;

	/* Iterate through the array */
	for (i = 0; i < length; i++) {
		val = *(array + i);
		
		/* The formatting of the indexes between 0-9 are handeled in this conditional block */
		if (i >= 0 && i < 10) {
			/* This block of code takes care of the formatting of values depending to their number of tens */
			if (val >= 0 && val < 10) {
				printf("Index:  %d, Value:   %d   \n", i, *(array + i));
			} if (val > 9 && val < 100) {
				printf("Index:  %d, Value:  %d   \n", i, *(array + i));
			} if (val > 99 && val < 1000) {
				printf("Index:  %d, Value: %d   \n", i, *(array + i));
			}

		}
		
		/* The formatting of the indexes between 10-99 are handeled in this conditional block */
		if (i >= 10 && i < 100) {
			/* This block of code takes care of the formatting of values depending to their number of tens */
			if (val >= 0 && val < 10) {
				printf("Index: %d, Value:   %d   \n", i, *(array + i));
			} if (val > 9 && val < 100) {
				printf("Index: %d, Value:  %d   \n", i, *(array + i));
			} if (val > 99 && val < 1000) {
				printf("Index: %d, Value: %d   \n", i, *(array + i));
			}
		}
	}


}


/**
 * Checks if the initial array is empty 
 * If so then exits the void main function
 */
if (test == NULL) {
	printf("Original array resulted in NULL pointer\nProgram terminated");
	exit (0);
}


  /* First of all, printing the given original array */
printf("Original array:\n");
print_array(test, SIZE);


/**
 * As next step, calling the sorting function to sort in required descending order
 * This procedure is necessary at this time to meet the condition for the following
 * statistical applications
 */
unsigned char *sorted_array = sort_array(ptr, SIZE);


/**
 * Call the find_mean function to evaluate the mean value on the sorted array
 * Then call the print_statistics function to print the mean value
 */
printf("\n");
int mean_val = find_mean(test, SIZE);
printf("Arithmetic mean value of the array:\n");
print_statistics(mean_val, 99999);


/**
 * Call the find_median function to evaluate the median value on the sorted array
 * Then call the print_statistics function to print the median value
 */
printf("\n");
int median_val = find_median(sorted_array, SIZE);
printf("The median value:\n");
print_statistics(median_val, 99999);


/**
 * Call the find_minimum function to evaluate the minimum value on the sorted array
 * Then call the print_statistics function to print the minimum value
 * To make the print_statistics function printing in a consistent formatting,
 * a second parameter (index) is provided to it, to distinguish if either an index
 * is available or not
 * When an index of the value is available, it's integer index is provided to the
 * print_statistics function to have a nicely printed formatting.
 * The index of the minimum value is the highest of the data set due to the descending order.
 */
printf("\n");
int min_val = find_minimum(sorted_array, SIZE);
printf("Minimum value:\n");
print_statistics(min_val, SIZE-1);


/**
 * Call the find_maximum function to evaluate the maximum value on the sorted array
 * Then call the print_statistics function to print the maximum value
 * To make the print_statistics function printing in a consistent formatting,
 * a second parameter (index) is provided to it, to distinguish if either an index
 * is available or not
 * When an index of the value is available, it's integer index is provided to the
 * print_statistics function to have a nicely printed formatting.
 * The index of the minimum value is the lowest of the data set due to the descending order.
 */
printf("\n");
int max_val = find_maximum(sorted_array, SIZE);
printf("Maximum value:\n");
print_statistics(max_val, SIZE-SIZE);



  /* Finally print the sorted function to the terminal */
printf("\n");
printf("Sorted array in descending order:\n");
print_array(sorted_array, SIZE);

free(sorted_array);
}


/**
 * Declaration of the function which takes as input a pointer which references
 * to an array with it's length, a set of numbers and finds it's arithmetic mean value.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the mean value from the given data set
 */
int find_mean(unsigned char * ar, int length) {
	int i;
	int sum = 0;
	float mean_float = 0;
	int mean_int = 0;

	for (i = 0; i < length; i++) {
		//printf("%d\n", val);
		
		sum = sum + *(ar+i);

	}
	
	//mean_val = (int)floor(sum / length);
	mean_float = sum/length;
	mean_int = (int)mean_float;
	return (int) mean_int;

}


/**
 * Declaration of the function which takes as input a pointer which references
 * to an array with it's length, a set of numbers and finds it's mediani.
 * In this case of fixed length of the data set, the value of the median
 * the mean of the indexes 19 and 20.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the mean value from the given data set
 */
int find_median(unsigned char * ptr, int length) {
	int first_val = *(ptr+(length/2)-1);
	int second_val = *(ptr+(length/2));
	int median_int = 0;
	
	if (first_val != second_val) {
		median_int = (first_val + second_val) / 2;
	}

	if (first_val == second_val) {
		median_int = first_val;
	}
	
	return median_int;
}


/**
 * Declaration of the function which takes as input a pointer which references
 * to an array with it's length, a set of numbers and finds the element
 * with the minimum value.
 * Because of the descending order of the data set, the minimum value
 * occupies at the highest index.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the mean value from the given data set
 */
int find_minimum(unsigned char * ptr, int length){
	int min_val = 0;
	min_val = *(ptr+(length-1));

	return min_val;
	
}


/**
 * Declaration of the function which takes as input a pointer which references
 * to an array with it's length, a set of numbers and finds the element
 * with the maximum value.
 * Because of the descending order of the data set, the maximum value
 * occupies at the lowest index.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return int An integer that holds the mean value from the given data set
 */
int find_maximum(unsigned char * ptr, int length) {
	int max_val =  0;
	max_val = *(ptr+0);

	return max_val;
	
}


/**
 * The sort_array function is provided with a pointer which references
 * to a data set of 40 numbers.
 * The mixed number set is then sorted using the selection sort algorithm,
 * in the way of copying the values of the original array as a new sorted
 * data set, with the help of the malloc function.
 *
 * @param unsigned char pointer A pointer to a data array with 40 elements
 * @param int An integer as the size of the array.
 *
 * @return unsigned char pointer An unsigned char pointer returns the sorted data set
 */
unsigned char * sort_array(unsigned char * ptr, int length) {

	char i;
	char j;
	char temp;

	unsigned char *array_copy = malloc(length * sizeof(char));
	
	/* First, a copy of the provided data set is copied to the allocated memory */
	for (i = 0; i < length; i++) {
		array_copy[i] = ptr[i];	
	}

	/**
	 * After copying the initial array, the sorting of the values take place
	 * in descending order.
	*/
	for (i = 0; i < length; i++) {
		for (j=i+1; j<length; j++) {
			if (array_copy[j] > array_copy[i]) {
				temp = array_copy[i];
				array_copy[i] = array_copy[j];
				array_copy[j] = temp;			
			}
		}
	}

	/**
	 * A preemtive check, if the pointer holds data and is not NULL
	 * If so, the program terminates with the respective information
	 */
	if (array_copy == NULL) {
		printf("Sorted copy (malloc) of the original array resulted in NULL pointer\nProgram terminated");
		exit (0);
	}

	return array_copy;
		
}

