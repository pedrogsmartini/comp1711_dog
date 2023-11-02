#include<stdio.h>
#include <stdlib.h>

int main()
{

    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename,"r");
    if (filename == NULL)
    {
        perror("No such file!");
        return 1;
    }
        //To read files, we need a buffer. What is a buffer?
    //Its the amount that the code will read from your
    //file that you desire.
    int buffer_size = 150;
    char line_buffer[buffer_size];
    int rec = 0;
    int i = 1;
    while (fgets(line_buffer, buffer_size, file) !=NULL & i<=3)
    {
        char var = 'o';
        int cnt=-1;
        while (var!='\0')
        {
            cnt++;
            var=line_buffer[cnt];
            if (var==',')
            {
                line_buffer[cnt] = '/';
            }
        
        }
        printf("%s", line_buffer);       
        //Right on! Right now, you are on the loop of the file reading
        //line by line. Do the commands you want referring to the 
        //current line of the loop.
        i++;
        //printf("%s\n",line_buffer);
        //int a = atoi(line_buffer);
    }

    buffer_size = 150;
    line_buffer[buffer_size];
    rec = 0;
    i = 1;

    while (fgets(line_buffer, buffer_size, file) !=NULL)
    {
        rec++;
    }
    printf("Number of records: %d\n",rec);
    fclose(file);
    
    return 0;
}