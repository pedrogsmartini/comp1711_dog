#include <stdio.h>

void printArray(int a[][3] ){ //it specifies where to jump the lines. The compile can infer line numbers, but not column numbers. Thats why we only specify column numbers
  for (size_t i = 0; i <= 1; ++i) { //size_t is a definer, but u could also use int type as well
     for (size_t j = 0; j <= 2; ++j) {
        if (j==1){
            a[i][j]=0;
        }
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

//now lets say you want to change an array, specifically setting the values at 0 for the second column. 
//How do you do that? Lets find this out.

int main() {
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("Values in array1 by row are:\n");
  printArray(array1);

  int array2[2][3] = {1, 2, 3, 4, 5};
  printf("Values in array2 by row are:\n");
  printArray(array2);


  int array3[2][3] = {{1, 2}, {4}};
  printf("Values in array3 by row are:\n");
  printArray(array3);
  
  int array4[5][3] = {{1,2,3},{5,66,12341},1,2,3};
  printf("Values in array 4 by row are:\n");
  printArray(array4);
  return 0;
}