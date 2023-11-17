#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
   FitnessData Fitness[900];
   #define buffer_size 900
   char line[buffer_size];
   char steps2[900];
    
    char filename [] = "FitnessData_2023.csv";

    //printf("Input filename: ");
    //fgets(line, buffer_size, stdin);
    //sscanf(line, " %s ", filename);

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }

    int counter = 0;
    while (fgets(line, buffer_size, input))
    {
        tokeniseRecord(line, ",", Fitness[counter].date, Fitness[counter].time, steps2);
        counter++;
        sscanf(steps2, "%d", &Fitness[counter].steps);

    }

    //int numberOfElements = counter;
    char choice;
    fclose(input);

     while (1)
    {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':

            printf("Input filename: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

        break;
        }
    }
}








