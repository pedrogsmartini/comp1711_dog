#include<stdio.h>

int main () {
    float radius;
    printf("Insert radius: ");
    scanf("%f",&radius);
    float pi = 3.14159265359;
    float area= pi * radius * radius;
    printf("Area = %f\n", area);
    return 0;
}