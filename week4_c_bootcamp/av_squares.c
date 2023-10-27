#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename [] = "squares.dat";
    FILE *file = fopen(filename,"r");
    if (file==NULL)
    {
        perror("No such file available!");
        return 1;
    }
    //To read files, we need a buffer. What is a buffer?
    //Its the amount that the code will read from your
    //file that you desire.
    int buffer_size = 150;
    char line_buffer[buffer_size];
    float avrg = 0;
    int cnt = 0;
    while (fgets(line_buffer, buffer_size, file) !=NULL)
    {
        //Right on! Right now, you are on the loop of the file reading
        //line by line. Do the commands you want referring to the 
        //current line of the loop.
        cnt++;
        printf("%s\n",line_buffer);
        int a = atoi(line_buffer);
        avrg = avrg + a;
    }
    avrg = avrg/cnt;
    printf("Your average value is %f\n",avrg);
    return 0;
}