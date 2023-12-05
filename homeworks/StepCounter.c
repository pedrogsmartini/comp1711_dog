#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[6]; 
} FITNESS_DATA;

typedef struct {
	int big_length;
	int start;
	int end; 
} f_command;

// Define any additional variables here
char date[100]; 
char time[100];   
char steps[100];
char choice;
int bigsteps[100];
char bigintervals[1000];

int rec = 0;
int i = 1;
int error = 0;
float sum = 0;
int max = 0;
int min = 100000;
int few = 0;
int lng = 0;
int a;
int mean_rnd;
int period = 0;
int interval = 0;
FILE *input;
int rep = 0;
char filename[1000];
int buffer_size = 150;
char line_buffer[150];
FITNESS_DATA data[6000];
f_command lng_interval[1000];
int cnt=0;

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
        printf("Menu options: \n");
        printf("A: Specify the filename to be imported \n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Quit\n");
        printf("Enter choice: ");    
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
            fgets(filename, 1000, stdin);
            size_t newlinePos = strcspn(filename, "\n");
            if (newlinePos < strlen(filename)) 
            {
                filename[newlinePos] = '\0';
            }          
            input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                break;
            }
            else
            {
                printf("File successfully loaded.\n");
            }
            while (fgets(line_buffer, buffer_size, input))
            {
                tokeniseRecord(line_buffer, ",", date, time, steps);
                strcpy(data[cnt].date, date);
                strcpy(data[cnt].time, time);
                strcpy(data[cnt].steps, steps);
                if (rep==0)
                {
                    cnt++;
                }
            }
            fclose(input);
            fflush(stdin);
            rep++;
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n",cnt);
            break;
            break;

        case 'C':
        case 'c':
            max = 0;
            min = 10000;
            for (int i = 0; i<cnt; i++)
            {
                if (atoi(data[i].steps)<min)
                {
                    few=i;
                    min = atoi(data[i].steps);
                }
            }
            printf("Fewest steps: %s %s\n",data[few].date,data[few].time);
            break;

        case 'D':
        case 'd':
            max = 0;
            min = 10000;
            for (int i = 0; i<cnt; i++)
            {
                if (atoi(data[i].steps)>max)
                {
                    lng=i;
                    max = atoi(data[i].steps);
                }
            }
            printf("Largest steps: %s %s\n",data[lng].date,data[lng].time);
            break;

        case 'E':
        case 'e':
            sum = 0;
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
            break;

        case 'F':
        case 'f':
            max = 0;
            min = 10000;
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
                        lng_interval[k].end = i;
                        lng_interval[k].big_length = interval;
                        k++;
                        interval = 0;
                    }
                }
            }
            int max_index;
            for (int i = 0; i<k;i++)
            {
                if (lng_interval[i].big_length>max)
                {
                    max = lng_interval[i].big_length;
                    max_index=i;
                }
            }
            printf("Longest period start: %s %s\n",data[lng_interval[max_index].start+1].date,data[lng_interval[max_index].start].time);
            printf("Longest period end: %s %s\n",data[lng_interval[max_index].end+1].date,data[lng_interval[max_index].end].time);
            break;

        case 'Q':
        case 'q':
            return 1;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
}