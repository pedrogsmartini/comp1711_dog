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

typedef struct {
	char big_length[11];
	char start[11];
	char end[11]; 
} f_command;

// Define any additional variables here
char date[100]; 
char time[100];   
char steps[100];
char filename[] = "FitnessData_2023.csv";
char choice;
char bigsteps[100];
char bigintervals[1000];

int rec = 0;
int i = 1;
int error = 0;
int sum = 0;
int max = 0;
int min = 100000;
int few = 0;
int lng = 0;
int a;
int mean_rnd;
int period = 0;
int interval = 0;

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
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        error = 1;
        return 1;
    }
    int buffer_size = 150;
    char line_buffer[buffer_size];
    FITNESS_DATA data[6000];
    f_command lng_interval[1000];
    int cnt=0;
    while (fgets(line_buffer, buffer_size, input))
    {
        tokeniseRecord(line_buffer, ",", date, time, steps);
        strcpy(data[cnt].date, date);
        strcpy(data[cnt].time, time);
        strcpy(data[cnt].steps, steps);
        cnt++;
    }
    fclose(input);
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
        printf("Input filename: "); //You dont have to write that. The code will!!
        if (error == 0)
        {
            printf("File successfully loaded.\n");
        }
        else
        {
            printf("Error: Could not find or open the file.\n");
        }
        return 1;
        break;

    case 'B':
    case 'b':
        printf("Total records: %d\n",cnt);
        return 1;
        break;

    case 'C': //GET THE FEWEST STEPS. Question: can it be repeated? If so, how to be printed???
    case 'c':
        for (int i = 0; i<cnt; i++)
        {
            if (atoi(data[i].steps)<min)
            {
                few=i;
                min = atoi(data[i].steps);
            }
        }
        printf("Fewest steps: %d\n",min);
        return 1;
        break;

    case 'D': //GET THE LARGEST STEPS. Question: can it be repeated? If so, how to be printed???
    case 'd':
        for (int i = 0; i<cnt; i++)
        {
            if (atoi(data[i].steps)>max)
            {
                lng=i;
                max = atoi(data[i].steps);
            }
        }
        printf("Longest steps: %s\n",data[lng].steps);
        return 1;
        break;

    case 'E': //MEAN STEP COUNT
    case 'e':
        for (int i = 0; i<cnt;i++)
        {
            sum = sum + atoi(data[i].steps);
        }
        float mean = sum/cnt;
        //Round mean
        a = (int) mean;
        if (mean - a < 0.5)
        {
            mean_rnd=a;
        }
        else
        {
            mean_rnd=a+1;
        }
        printf("Mean step count: %d\n",mean_rnd);
        return 1;
        break;

    case 'F': //LONG PERIOD START-END
    case 'f':
    for (int i = 0; i<cnt;i++)
    {
        bigsteps[i] = 0;
    }
    for (int i = 0; i<cnt;i++)
    {
        if (atoi(data[i].steps)>500)
        {
            bigsteps[i]=1;
        }
    }
    for (int i = 0; i<cnt;i++)
    {
        printf("%d\n",bigsteps[i]);
    }
    int k=0;
    for (int i = 0; i<cnt;i++) //NEXT STEP: learn how to put integers in array structs, bc its not working
    {
        if (bigsteps[i]==1)
        {
            interval++;
            if (interval==1)
            {
                lng_interval[k].start = i;
            }
            if (bigsteps[i+1]==0)
            {
                lng_interval[k].end = 0;
                lng_interval[k].big_length = interval;
                k++;
                interval = 0;
            }
        }
    }
    for (int i = 0; i<k;i++)
    {
        printf("%d\n",lng_interval[i].big_length);
    }
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
