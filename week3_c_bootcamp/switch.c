#include <stdio.h>

int main() {

    int label;
    printf("Choose a label: .\n");
    scanf("%d", &label);
    switch (label) {
        case 0:
            printf("0 was selected .\n");
            break;
        case 1:
            printf("1 was selected.\n");
            break;
        case 2:
            printf("2 was selected. \n");
            break;


    }
}