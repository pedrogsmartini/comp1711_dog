#include <stdio.h>

int main () {
    int a;
    printf("Select a number:");
    scanf("%d", &a);
    int c = a%4;
    int d = a%5;
    if (c==0 && d==0)
    {
        printf("The number is divisible by 4 and 5 .\n");
    }
}