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
   char strsteps[900];
    
    char filename [] = "FitnessData_2023.csv";

    int numberOfElements = 0;
    char choice;

    int counter = 0;
    int minimum = 0;
    int maximum = 0;
    float mean = 0;
    float sum = 0;
    int maxcount = 0;
    int stepcount = 0;

     while (1)
    {
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit the program\n");

        choice = getchar();

        while (getchar() != '\n');

        switch (choice)
        {

        case 'A':
        case 'a':

            printf("Input filename: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }

            int counter = 0;
            while (fgets(line, buffer_size, input))
            {
                tokeniseRecord(line, ",", Fitness[counter].date, Fitness[counter].time, strsteps);
                sscanf(strsteps, "%d", &Fitness[counter].steps);

                counter++;
            }
            numberOfElements = counter;
            printf("File successfully loaded.\n");

             break;
        

        case 'B':
        case 'b':
            
        printf("Total records: %d\n", numberOfElements);
            
            break;


        case 'C':
        case 'c':

            for (int i = 0; i< numberOfElements; i++)
            {
                if (Fitness[i].steps < Fitness[minimum].steps) 
                {
                    minimum = i;
                }
            }
        printf("Fewest steps: %s %s\n", Fitness[minimum].date, Fitness[minimum].time);
            break;

        case 'D':
        case 'd':

            for (int i = 0; i< numberOfElements; i++)
            {
                if (Fitness[i].steps > Fitness[maximum].steps) 
                {
                    maximum = i;
                }
            }
            printf("Largest steps: %s %s\n", Fitness[maximum].date, Fitness[maximum].time);
            break;

        case 'E':
        case 'e':

        sum = 0;
        mean = 0;

            for (int i = 0; i < numberOfElements; i++)
            {      
                sum += Fitness[i].steps;
            }
            mean = sum / numberOfElements;
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
        
         maxcount = 0;
         stepcount = 0;
         int i_end = 0;
         int i_start = 0;

         for (int i = 0; i< numberOfElements; i++) 
         {
            if (Fitness[i].steps > 500)
            {
                printf("indicies of steps > 500 = %d stepcount = %d maxcount = %d\n",i, stepcount, maxcount);
                stepcount += 1;
                if (stepcount > maxcount)
                {

                    maxcount = stepcount;
                    i_end = i;
                }
            }
            else
            {
                stepcount = 0;
            }
            
         }

        i_start = i_end - (maxcount -1);

        printf("Longest period start: %s %s\n", Fitness[i_start].date, Fitness[i_start].time);
        printf("Longest period end: %s %s\n", Fitness[i_end].date, Fitness[i_end].time);
        break;

        case 'Q':
        case 'q':

            return 0;

            break;

        default:

            printf("Invalid choice. Try again.\n");

            break;

        }
    }
}








