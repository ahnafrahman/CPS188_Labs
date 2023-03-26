#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FILE_NAME 100

void strip (char original[], char stripped[]);
void reverse (char original[], char reversed[]);

//Main Program
int main() {

    char userInput [512];
    char strippedOutput [512];
    char reversedOutput [512];
    printf("\nPlease print the string you want to analyse: ");
    gets(userInput);
    
    strip(userInput, strippedOutput);
    printf("\nThe stripped string: %s\n", strippedOutput);
    reverse(strippedOutput, reversedOutput);
    printf("Reversed Stripped String: %s\n\n", reversedOutput);
}

// Function Definition
void strip (char original[], char stripped[]) {

    char temp[512];
    int n = strlen(original);
    int j = 0;

    for (int i = 0; i <= n; i++) {
        temp[i] = original[i];
    }

    for (int i = 0; i <= n; ++i) {

        n = strlen(temp);
        char c = temp[i];

        if (isalnum(temp[i]) == 0) {
            temp[i] = ' ';
        }
        if (isupper(temp[i])) {
            temp[i] = tolower(temp[i]); 
        }
        temp[n] = '\0';
    }

    for (int i = 0; i <= n; i++) {
        if (!isspace(temp[i])) {
            temp[j++] = temp[i];
        }
        stripped[i] = temp[i];
    }
    temp[n] = '\0';  
}

void reverse (char original[], char reversed[]) {

    int originalLength = strlen(original);
    int reversedLength = strlen(reversed);

    int originalIndex = originalLength - reversedLength - 1;
    int reversedIndex = reversedLength;

    if (originalLength > reversedLength) {
        reversed[reversedIndex] = original[originalIndex];
        reversed[reversedIndex + 1] = '\0';
        reverse(original, reversed);
    }
}