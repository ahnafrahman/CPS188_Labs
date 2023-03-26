#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_FILE_NAME 50 //Defining Headers

void sortList (double inputArray[], double sortedArray[], int size); //sort an array using bubble sort and store in serperate array
void normalize (double inputArray[], double normalizedArrayOutput[], double rangedArrayOutput[], int size, double minimum, double maximum); //normalize an array

int main() 
{
    char filename[MAX_FILE_NAME]; 
    char c;
    int count = 0;
    double min, max; //Local Variables and Array Definitions

    printf("Enter Name of File Containing Data to Normalize: "); // Opens User Inputted File
    scanf("%s", filename);

    FILE *dataFile;
    dataFile = fopen(filename, "r");

    if (dataFile == NULL)
    {
        system("CLS");
        printf("Could Not Find/Open File Named '%s' \n", filename);
        return 0;
    }

    c = fgetc(dataFile);

    if (c == EOF) 
    {
        system("CLS");
        printf("Data File is Empty!");
        return(0);
    } 
    
    else 
    {
        fseek(dataFile, 0, SEEK_SET);
        system("CLS");
        printf ("\nRaw Input Data\t\tNormalized Data \n\n", 27, 27);
    }

    fscanf (dataFile, "%d", &count); 
    fscanf (dataFile, "%lf", &min);
    fscanf (dataFile, "%lf", &max); // Takes data point count information from file

    double rawInput[count]; 
    double rangedOutput[count];
    double normalizedOutput[count]; //Defining Local Arrays

    for (int n = 0; n < count; ++n) 
    {
        fscanf (dataFile, "%lf", &rawInput[n]);
    }

    fclose(dataFile);
	
    // Calls normalize function
	normalize(rawInput, normalizedOutput, rangedOutput, count, min, max);

    // Prints normalized array
    for(int i=0; i < count; i++) 
    {
        printf(" %10.6lf\t\t %10.6lf\n\n", rawInput[i], normalizedOutput[i]);
    }

    printf("\n Normalized Range: %lf to %lf \n\n", 27, min, max, 27);
}

void sortList (double inputArray[], double sortedArray[], int size) 
{
    int i, j;
    double temp;

    //Array compared with value beside and exchanged if not in order, loops until done
    for (int k = 0; k < size; k++) 
    {
	    sortedArray[k] = inputArray[k];
    }

    for (int i = 0; i < size; i++) 
    {
        for (j = 0; j < (size - 1); j++) 
        {
            if (sortedArray[j] > sortedArray [j + 1]) 
            {
                temp = sortedArray [j];
                sortedArray [j] = sortedArray [j + 1];
                sortedArray [j + 1] = temp;
            }
        }
    }
}

void normalize (double inputArray[], double normalizedArrayOutput[], double rangedArrayOutput[], int size, double minimum, double maximum) {
	
    sortList(inputArray, rangedArrayOutput, size);

    for (int n = 0; n < size; n++) //sorts array using normalization and puts outputs in normalized array output
    {
        normalizedArrayOutput[n] = minimum + (inputArray[n] - rangedArrayOutput[0]) * (maximum - minimum) / (rangedArrayOutput[size - 1] - rangedArrayOutput[0]);
    }
}