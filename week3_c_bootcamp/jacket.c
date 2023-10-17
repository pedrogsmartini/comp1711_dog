#include <stdio.h>

int main () {
    float temperature;
    printf("What is the temperature?");
    scanf("%f", &temperature);

    if (temperature >10)
        printf("No need for a jacket.\n");
    else if(temperature > 20)
        printf("Good weather for a light jacket. \n");
    return 0;



}