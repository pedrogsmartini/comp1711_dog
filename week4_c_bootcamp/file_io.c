#include <stdio.h>

int main () {
    char filename [] = "data.txt";
    FILE *file = fopen(filename,"w");
    fprintf("Hello world!")
    fclose(file);
    return 0;
}