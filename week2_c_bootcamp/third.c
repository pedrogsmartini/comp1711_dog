#include<stdio.h>

int main () {
    float var1; 
    float var2;
    printf("Insert base:");
    scanf("%f", &var1);
    printf("Insert length:");
    scanf("%f", &var2);
    float area = var1 * var2;
    printf("Area = %f\n", area);
    return 0;
}