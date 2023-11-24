#include<stdio.h>
#include <stdlib.h>

int main()
{
    int array[]={100,22,13,4,35,46,7};
    int min = 2000000;
    int size = sizeof(array)/sizeof(array[0]);
    int max = 0;
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        sum = sum + array[i];
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    float mean = sum /size;
    printf("O arranjo a se considerar é: ");
    for (int i = 0; i < size; ++i) 
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("O menor número do arranjo é %d\n",min);
    printf("O maior número do arranjo é %d\n",max);
    printf("A média do arranjo é %f\n",mean);
}
