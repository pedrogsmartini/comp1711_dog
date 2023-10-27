#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student;
    //newstudent.name = "Name Surname"; --> Doesnt work! "Variable newstudent.name not specified"
    //newstudent.student_id = "13902178"; --> Doesnt work! "Variable newstudent.student_id not specified"
    //Try to understand better how to label and create strings to get that...
    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902178");
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}