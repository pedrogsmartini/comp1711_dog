#include <stdio.h>
int main() 
{
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        perror("");
        return 1;
        }
    fclose(file);
    return 0;
    }

    //so w is going to exclude everything and create the file.
    //If u putted instead letter "a", it would append, write
    //on the file if it was already created. Just letter r does
    //not create a file, all of the others do.