#include <stdio.h>

float sum (int a, int b)


int main()
{
    float y = 2.1;
    float z = sum(5,y); //calling our new function

    printf ("The sum of 5 and %f is %.f\n",y,z);

    return 0;
}

int sum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}