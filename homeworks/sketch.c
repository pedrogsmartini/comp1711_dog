#include<stdio.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    fgets(str, 1000, stdin);
    printf("%s",str);
}
