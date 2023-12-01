#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record

int sortDescending(const void *a, const void *b) {
    // To sort in descending order, return a negative value if b should come before a
    // Return a positive value if a should come before b
    // Return 0 if they are equal (order doesn't matter for equal elements)
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;

}

void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {

    #define buffer_size 900
    char line[buffer_size];
    char filename [] = "FitnessData_2023.csv";
    FitnessData Fitness [900];
    char strsteps[900];
    FILE*file = NULL;
    int numberOfElements = 0;

    printf("Enter filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: Invalid file.\n");
        return 1;
    }

    int counter = 0;

    while (fgets(line, buffer_size, input))
    {
        tokeniseRecord(line, ',', Fitness[counter].date, Fitness[counter].time, &Fitness[counter].steps);
        counter++;
    }
    numberOfElements = counter;
    printf("File successfully loaded.\n");


    qsort(Fitness, numberOfElements, sizeof(FitnessData), sortDescending);
    
// //writing to another file
    FILE * fp;

    fp = fopen ("file.txt", "w+");
   
    for (int i = 0; i < numberOfElements; i++) {
        fprintf(fp, "%s\t%s\t%d\n", Fitness[i].date, Fitness[i].time, Fitness[i].steps);
    }
    fclose(fp);




    return 0;



}

