#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[5];
} FitnessData;

// Define any additional variables here



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

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("");
        return 1;
    }


    int buffer_size = 2000;
    int counter = 0;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, file) != NULL) {
    tokeniseRecord(line_buffer,",",Fitness[counter].date, Fitness[counter].time, Fitness[counter].steps);
    counter++;
    }

    printf("Number of records in file: %d\n",counter);
    for (counter = 0; counter < 3; counter++) {
        printf("%s/%s/%d\n",Fitness[counter].date,Fitness[counter].time,atoi(Fitness[counter].steps));
    }

    fclose(file);
    return 0;
}