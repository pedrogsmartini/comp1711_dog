#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student student1 = {"Name Surname", "28932123", 35}; 
    //WHat is happening here? Didnt we define the variable 
    //student already? No, we didnt! We defined a type of struct!
    //Not the variable. So you define a type of struct, in this case,
    //of type "student", and thennn, you define a variable inside this 
    //type of scruct, which in this case is the student1.
    printf("Student name: %s\n", student1.name);
    printf("Student ID:   %s\n", student1.student_id);
    printf("Final mark:   %u\n", student1.mark);
    return 0;
}