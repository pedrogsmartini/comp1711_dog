#include<stdio.h>

int main()
{
    char filename [] = "squares.dat";
    FILE *file = fopen(filename,"w");
    //check if there is no error in code!!
    if (file==NULL)
    {
        perror("No such file!");
        return 1;
    }
    //After you opened or created a new file, you are able to edit it 
    //and add things on it. How do you do that? With fprintf command.
    //Everything in C you have to specify, always. So, you do:
    //fprintf(file,"something",*specify something variable*)
    int n;
    printf("Select a number:\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        int a = i*i;
        fprintf(file,"%d\n",a);
    }
    fclose(file);
    return 0;
}