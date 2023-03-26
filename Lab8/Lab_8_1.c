//Header Definitions
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

//Structure Definitions
typedef struct address_t {
    int A;
    int B;
    int C;
    int ID;
    char nickname[500];
} ipAddress;

//Function Declarations
int localnet (ipAddress a[], ipAddress b[]);

//Main Program
int main() {

    ipAddress addresses[500]; // array with structured IP addresses

    char filename[MAX_FILE_NAME]; //for user input of data file
    char c; //for user input of data file

    char sentinel[500] = "0.0.0.0 sentinel"; 
    char sentineltest[500]; 
    int count = 0; 

    int tester; 

    #pragma region //data extraction

    // Open File from User Input, With Input Confirmation
    printf("Enter Name of File Containing IPv4 Address Data to Analyze: ");
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

    if (c == EOF) {
        system("CLS");
        printf("Data File is Empty!");
        return(0);

    } else {
        fseek(dataFile, 0, SEEK_SET);
        system("CLS");
    }

    #pragma endregion

    //increment line counter until sentinel is encountered
    while (tester != 0) {
        fgets(sentineltest, 60, dataFile);
        tester = strcmp(sentinel, sentineltest);
        count++;
    }

    fseek(dataFile, 0, SEEK_SET); //reset scanner to begining of datafile

}