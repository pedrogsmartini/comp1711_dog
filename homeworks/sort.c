#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//REAPRENDA A ARMAZENAR UM ARQUIVO, TÁ FALTANDO ISSO

int error = 0;
int main() 
{
    char filename[] = "timelines.csv";
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        error = 1;
        return 1;
    }
    int buffer_size = 150;
    char line_buffer[buffer_size];
    char data[1000];
    int cnt=0;
    while (fgets(line_buffer, buffer_size, input))
    {
        data[cnt] = strdup(line_buffer);
        cnt++;
        printf("%s\n",line_buffer);

    }
    for (int i =0; i<cnt; i++)
    {
        printf("%d\n",data[i]);
    }
    
}