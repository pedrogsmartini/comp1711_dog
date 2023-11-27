#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "FitnessDataStruct.h"

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[6]; 
} FITNESS_DATA;

// Define any additional variables here
char date[100]; 
char time[100];   
char steps[100];

char filename[] = "FitnessData_2023.csv";
int rec = 0;
int i = 1;
int error = 0;

// Struct moved to header file

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
int main() 
{
    while (1)
    {
        FILE *input = fopen(filename, "r");
        if (!input)
        {
            error = 1;
            return 1;
        }
        int buffer_size = 150;
        char line_buffer[buffer_size];
        FITNESS_DATA data[6000];
        while (fgets(line_buffer, buffer_size, input))
        {
            tokeniseRecord(line_buffer, ",", date, time, steps);
            strcpy(data[rec].date, date);
            strcpy(data[rec].time, time);
            strcpy(data[rec].steps, steps);
        }
        printf("For the first record, we have the following steps: %s\n",data[0].steps);
        fclose(input);
        break;
    }
}