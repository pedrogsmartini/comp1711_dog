#include <stdio.h>

int main() {
    float mark;
    printf("What is your mark?");
    scanf("%f", &mark);
    if (mark >= 0 &&  mark <= 100) {
        if (mark >= 40)
        {
            printf("%f is a pass \n", mark);
        }
        else
        {
            printf("%f is a fail\n", mark);
        }
    }
    else
    {
        printf("Mark is not valid.");
    }
    return 0;
}