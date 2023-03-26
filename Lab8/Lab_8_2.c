// Header Definitions
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "mylib.h"

#define MAX_FILE_NAME 100
#define DATA_ROWS 10
#define DATA_COLUMNS 10 

//Function Declarations
int dataExtract (char filename[MAX_FILE_NAME], double outputArray[DATA_ROWS][DATA_COLUMNS]); //data extract function

//Main Program
int main () {

    // Local variables/arrays/structures
    double results[5];
    double resultsFromFile[5];
    char filename[MAX_FILE_NAME];
    double realData[DATA_ROWS][DATA_COLUMNS]; 

    // Data Extraction w/ Input Validation
    do {
        system("CLS");
        printf("Enter Name of File Containing Real Number Data: ");
        scanf("%s", filename); 
    } while (dataExtract (filename, realData) == 0);
    
    printf ("\n\n%c[4mThe Array w/ Real Numbers From The File%c[0m \n\n", 27, 27); //Print the 10 x 10 array which the numbers from the file have been put into  w/ a title
    for (int i = 0; i < DATA_ROWS; ++i) {  
        for (int j = 0; j < DATA_COLUMNS; ++j) { 
            printf ("%7.1lf ", realData[i][j]); 
        }

        printf ("\n"); //prints on next terminal line once one complete row has been printed 
    }

    //stores results of functions into an array
    results[0] = sumdiag(realData);
    results[1] = sumall(realData);
    results[2] = avright(realData);
    results[3] = corners(realData);
    results[4] = largeanti(realData);

    FILE* binary;
    binary = fopen ("results.bin", "wb"); //writes results array to binary file
    fwrite (results, sizeof(results), 1, binary);
    fclose (binary);

    binary = fopen ("results.bin", "rb");
    fread (resultsFromFile, sizeof(resultsFromFile), 1, binary); //reads results array from binary file. stores in separate array
    fclose (binary);   

    printf ("\n\n%c[4mCalculations Based On Array%c[0m \n", 27, 27); //Displays the results from the results array extracted from results.bin

    printf("\nThe sum of diagonal of the array is: \e[1m%.1lf\e[0m\n", resultsFromFile[0]);
    printf("\nThe sum of all numbers in the array is: \e[1m%.1lf\e[0m\n", resultsFromFile[1]);
    printf("\nThe average of numbers in the rightmost column is: \e[1m%.1lf\e[0m\n", resultsFromFile[2]);
    printf("\nThe sum of the numbers in the four corners of the array is: \e[1m%.1lf\e[0m\n", resultsFromFile[3]);
    printf("\nThe largest number in the antidiagonal is: \e[1m%.1lf\e[0m\n\n", resultsFromFile[4]);

    return (0);
}

int dataExtract (char filename[MAX_FILE_NAME], double outputArray[DATA_ROWS][DATA_COLUMNS]) {
    
    FILE *dataFile;

    char c;

    dataFile = fopen(filename, "r");

    system("CLS");

    if (dataFile == NULL)
    {
        printf("Could Not Find/Open File Named '%s' \nPress Any Key To Re-enter File Name \n", filename);
        //getch();
        return (0);
    }

    //Check If Data File Has Content, Then Proceed

    c = fgetc(dataFile);

    if (c == EOF) {
        printf("Data File is Empty! \nPress Any Key To Re-enter File Name \n");
        //getch();
        return (0);
    } else {
        fseek(dataFile, 0, SEEK_SET); //Reset File Pointer To Begining of File
    }

    //Main Loop
    while (c != EOF) {
        
        for (int i = 0; i < DATA_ROWS; ++i) { //tracks & iterates horizontal (row) position of 2D matrix
            for (int j = 0; j < DATA_COLUMNS; ++j) { //tracks & iterates vertical (column) position of 2D matrix
                fscanf (dataFile, " %lf", &outputArray[i][j]); //fills given cell with integer 77 each iteration
            }
        }

        c = fgetc(dataFile);
    }

    fclose(dataFile);
    return(1);
}