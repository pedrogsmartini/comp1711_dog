#include<stdio.h>

int main()
{
    float num;
    int rnd_num;
    printf("Type float number to be rounded:");
    scanf("%f",&num);
    int a = (int) num;
    if (num - a < 0.5)
    {
        rnd_num=a;
    }
    else
    {
        rnd_num=a+1;
    }
    printf("Rounded number: %d\n",rnd_num);

}