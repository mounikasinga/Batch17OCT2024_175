#include "header.h"

int main()
{
    char *array[MAX]; // Initialization of the array
    char search_string[MAX];
    int n, i, ret;

    printf("\nHow many lines do you want to enter: ");
    scanf("%d", &n); // Get input from user
    while ('\n' != getchar()) // Cleaning the buffer
    {
        ;
    }

    printf("\n\nEnter lines:\n");
    for (i = 0; i < n; i++)
    {
        get_string(array, i); // Get each line
    }

    printf("\n\nThe entered lines are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", array[i]); // Displaying the input lines
    }

    bubble_sort(array, n); // Bubble sort the array of strings

    printf("\n\nThe sorted lines are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", array[i]); // Displaying the sorted lines
    }

    // Ask user for line to delete
    printf("\n\nEnter line to be searched and deleted: ");
    fgets(search_string, MAX, stdin);
    int len = strlen(search_string);
    if ('\n' == search_string[len - 1])
    {
        search_string[len - 1] = '\0'; // Replacing '\n' with '\0'
    }
    else
    {
        while (getchar() != '\n') // Clear the buffer
        {
            ;
        }
    }

    ret = delete_line(array, &n, search_string); // Deleting the line
    if (ret == FAILURE)
    {
        printf("\n\nLine not found\n");
    }
    else
    {
        printf("\n\nLine deleted successfully\n");
    }

    // Write the final list of lines to the file
    write_to_file(array, n);

    // Free allocated memory
    for (i = 0; i < n; i++)
    {
        free(array[i]);
    }

    return SUCCESS;
}

