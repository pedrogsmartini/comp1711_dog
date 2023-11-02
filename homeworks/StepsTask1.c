#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE *file = fopen(filename,"r");
    if (filename == NULL)
    {
        perror("No such file!");
        return 1;
    }
    int buffer_size = 150;
    char line_buffer[buffer_size];
    FITNESS_DATA initdata[3];
    while (fgets(line_buffer, buffer_size, file))
    {
        
        if (rec<=2)
        {
            tokeniseRecord(line_buffer, ",", date, time, steps);
            strcpy(initdata[rec].date, date);
            strcpy(initdata[rec].time, time);
            strcpy(initdata[rec].steps, steps);
        }
        rec++;
    }
    printf("Number of records in file: %d\n",rec);
    int steps0 = atoi(initdata[0].steps);
    int steps1 = atoi(initdata[1].steps);
    int steps2 = atoi(initdata[2].steps);
    printf("%s/%s/%d\n",initdata[0].date,initdata[0].time,steps0);
    printf("%s/%s/%d\n",initdata[1].date,initdata[1].time,steps1);
    printf("%s/%s/%d\n",initdata[2].date,initdata[2].time,steps2);
    fclose(file);
    return 0;
}