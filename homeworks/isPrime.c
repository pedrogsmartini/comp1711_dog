#include<stdio.h>

int PrimePredictor(int num)
{
    int i = 1;
    int cnt = 0;
    while (i<=num)
    {
       if (num%i == 0)
       {
        cnt++;
       }
       i++;
    }
    if (cnt ==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    int num;
    printf("Type a number:\n");
    scanf("%d",&num);
    int sol = PrimePredictor(num);
    printf("%d\n",sol);
    
}
