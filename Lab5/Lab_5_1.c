#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_SIZE 3 // Defining Headers

int sortList (int array[], int size, int *min, int *mid, int *max); //Declaring Functions
int sort[ARRAY_SIZE]; //Global variables

int main()
{
    int min, mid, max; //Local variables

    printf ("\n"); 
    for (int i = 0; i < ARRAY_SIZE; ++i) //Loop for user input
    {
        printf ("Please input an integer: ");
        scanf ("%d", &(sort[i]));
    }

    sortList (sort, ARRAY_SIZE, &min, &mid, &max); //Calls Sort

    printf ("\nThe lowest value is: %d \n", min); //Displays output

    printf ("The middle value is: %d \n", mid);

    printf ("The highest value is: %d \n", max);

    printf ("\nThe three numerical values in ascending order are: %d, %d, %d. \n\n", min, mid, max);
    // Displays the final answer in ascending order

    return (0);
}

int sortList (int array[], int size, int *min, int *mid, int *max) //Calls Sort function using loops
{
    int i, j, temp; 
    //Array compared with value beside and exchanged if not in order, loops until done

    for (int i = 0; i < size; ++i) 
    {
        for (j = i; j < size; ++j) 
        {
            if (array[i] > array [j]) 
            {
                temp = array [i];
                array [i] = array [j];
                array [j] = temp;
            }
        }
    }
    *min = array[0];
    *mid = array[1];
    *max = array[2]; //Displays output using pointers

    return (0);
}