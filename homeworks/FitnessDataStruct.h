#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdlib.h>
#include <stdio.h>


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

// Helper function prototypes
int *FindUpThreshold(int steps [500], int threshold, int size)
{
	int* indicator = (int*)malloc(size * sizeof(int));
    for (int i = 0; i<size;i++)
    {
        indicator[i] = 0;
    }
    for (int i = 0; i<size;i++)
    {
        if (steps[i]>500)
        {
            indicator[i]=1;
        }
    }
	return indicator;
}


#endif // FITNESS_DATA_STRUCT_H