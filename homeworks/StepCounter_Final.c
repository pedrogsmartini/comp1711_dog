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
        int cnt=0;
        while (fgets(line_buffer, buffer_size, file))
        {
            tokeniseRecord(line_buffer, ",", date, time, steps);
            strcpy(initdata[rec].date, date);
            strcpy(initdata[rec].time, time);
            strcpy(initdata[rec].steps, steps);
            cnt++;
        }
        printf("Menu options: \n");
        printf("A: Specify the filename to be imported \n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Quit\n");    

       // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Input filename: \n");
            if (error == 0)
            {
                printf("File successfully loaded.")
            }
            else
            {
                printf("Error: Could not find or open the file.")
            }

            fclose(input);
            break;

        case 'B':
        case 'b':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
                mean = mean + daily_readings[counter].bloodIron;
                counter++;
            }
            printf("Total records: %d\n",counter)
            break;

        case 'C':
        case 'c':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
                mean = mean + daily_readings[counter].bloodIron;
                counter++;
            }
            mean = mean/counter;
            printf("Your average blood iron was %.2f\n", mean);
            fclose(input);
            break;

            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default: 
            printf("Invalid choice. Try again.\n");
            fclose(input);
            break;

   

   
        }
    }
}