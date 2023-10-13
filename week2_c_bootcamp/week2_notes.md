int is always a integer function, because it returns 0
0 is a convention to know if the program is working
Look at the following code:

#include<stdio.h>

int main () {
    printf("Hello world!\n");
    return 0;
}

Line 5 means to get from the library the printf command. 
you always have to use ";" on each lines
the \n command just skip a line in the termina;

    //This is a comment! 
    /*
    This is also a comment!
    */

    Now look at this code we just did:

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

This code calculates the area of a rectangle. So, firstly, we
need to know what are the commands or functions we want to use.
Some of them are ready already. For instance, printf. You get
that function declaring a library, which is writing 
#include<stdio.h>. It means standard input output. The h, i dont
know
Then, we define the main function. It is always an integer. 
We are not interesting on their inputs, since we dont want
to specify it. Then, it is an int, main(no inputs), then
you define variables. Float for rational numbers in general. 
define the variables. scanf will scan something that you will
type on the computer. You start definining what it will scan.
So you write "%f" so the computer knows it has to read a 
float from the terminal. Then, &var1 to say that the value 
you putted will be stored in var1. 
The same thing for var 2. Now, we want the code to print 
the area. Just as the main languages, the star * is the symbol
to do multiplication. define area as a float which is the product
of the two variables inserted.  Then, you print it, 
area, just as you print anything you have stored as a variable.

SAVING FILES ON GIT - VERY IMPORTANT

If you want to save everything you did, here are the commands 
with the right order:
git add .
git commit -m "Type the description of what u want to save"
git push

So, thats it. And the dot at add . is to save everything