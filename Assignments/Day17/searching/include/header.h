/******************************************************************
 *	FILE_NAME   : header.h
 * 	DESCRIPTION : the file contains the header files ,
 *                     macro definitions and the function prototypes
 ********************************************************************/

/**********************HEADER_FILES*********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/****************************************************************************
 * 			  MACRO DEFINITIONS
 * **************************************************************************/

#define MAX 20
#define SIZE 100  // Increased buffer size for reading full lines
#define SUCCESS 1
#define FAILURE 0

/********************************************************************
 * 		FUNCTION_PROTOTYPES
 * *****************************************************************/
int get_string(char *array[], int i);
int binary_search(char *array[], char *find, int n);
int bubble_sort(char *array[], int n);
int delete_line(char *array[], int *n, char *line);
void write_to_file(char *array[], int n);

