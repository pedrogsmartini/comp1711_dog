#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char mec[100];
    for (int i = 0; i<10; i++)
    {
        mec[i] = i;
    }
    for (int i = 10; i<100;i++)
    {
        mec[i]=0;
    }
    for (int i = 0; i<100;i++)
    {
        printf("%d\n",mec[i]);
    }
    printf("%d\n",mec[101]);
}