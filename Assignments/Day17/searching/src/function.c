#include "header.h"

/*******************************************************************
 *        FUNCTION NAME: get_string
 *        DESCRIPTION: gets a line from standard input to the i-th
 *                      element of the array
 *        ARGUMENTS:    Array of strings to be stored
 *        RETURNS:      returns SUCCESS or FAILURE
 *******************************************************************/

int get_string(char *array[], int i)
{
    int len;
    char buff[SIZE];

    memset(buff, 0, SIZE); // Initializing the buffer to zero

    fgets(buff, SIZE - 1, stdin); // Get input from user
    len = strlen(buff);
    
    if ('\n' == buff[len - 1])   // Replacing '\n' with '\0'
    {
        buff[len - 1] = '\0';
    }
    else
    {
        while (getchar() != '\n') // Cleaning the buffer
        {
            ;
        }
    }

    // Allocating memory for the i-th element
    array[i] = (char *)malloc(len * sizeof(char));
    if (NULL == array[i])
    {
        printf("Memory Allocation Failed\n");
        return FAILURE;
    }
    strcpy(array[i], buff); // Copying the buffer to array[i]

    return SUCCESS;
}

/******************************************************************
 *        FUNCTION NAME: bubble_sort
 *        DESCRIPTION:   Sorts the list of strings in lexicographical order
 *        ARGUMENTS:     Array of strings and number of strings
 *        RETURNS:       SUCCESS after sorting
 *******************************************************************/

int bubble_sort(char *array[], int n)
{
    int i, j;
    int SWAP;
    char *temp;

    for (i = 0; i < (n - 1); i++)
    {
        SWAP = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (strcmp(array[j], array[j + 1]) > 0)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                SWAP = 1;
            }
        }
        if (SWAP == 0)
        {
            break; // No swap, array is already sorted
        }
    }

    printf("\n\nBUBBLE SORT DONE\n");
    return SUCCESS;
}

/******************************************************************
 *        FUNCTION NAME: delete_line
 *        DESCRIPTION:   Searches for a specific line and deletes it
 *        ARGUMENTS:     Array of strings, number of strings, and the line to delete
 *        RETURNS:       SUCCESS if deleted, FAILURE if not found
 *******************************************************************/

int delete_line(char *array[], int *n, char *line)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        if (strcmp(array[i], line) == 0) // Match found
        {
            free(array[i]);
            for (int j = i; j < *n - 1; j++) // Shift elements
            {
                array[j] = array[j + 1];
            }
            (*n)--; // Reduce the number of elements
            return SUCCESS;
        }
    }
    return FAILURE; // Line not found
}

/******************************************************************
 *        FUNCTION NAME: binary_search
 *        DESCRIPTION:   Searches for a line in the given list
 *        ARGUMENTS:     Array of strings, search string, and number of elements
 *        RETURNS:       Index of element or FAILURE
 *******************************************************************/

int binary_search(char *array[], char *find, int n)
{
    int BEG = 0;
    int END = n - 1;
    int MID;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (strcmp(find, array[MID]) == 0)
        {
            return MID;
        }
        if (strcmp(find, array[MID]) < 0)
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
    }

    return FAILURE;
}

/******************************************************************
 *        FUNCTION NAME: write_to_file
 *        DESCRIPTION:   Writes the final list of strings to a file
 *        ARGUMENTS:     Array of strings and number of elements
 *        RETURNS:       None
 *******************************************************************/

void write_to_file(char *array[], int n)
{
    FILE *file = fopen("../data/out.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s\n", array[i]);
    }

    fclose(file);
    printf("\n\nFinal list written to out.txt\n");
}

