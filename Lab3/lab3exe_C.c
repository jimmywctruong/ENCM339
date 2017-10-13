/*
 *  lab1exe_C.c
 *  ENCM 339 Fall 2017 lab2 Exercise C
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Student must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
  int nrow;
  // These are ALL of the variables you need!
  printf("Enter the number of rows (Max 20): ");
  scanf("%d", &nrow);
  if(nrow <= 0 || nrow > 20) {
    printf("Error: the maximum number of rows can be 20.\n");
    exit(1);
  }
  
  pascal_triangle(nrow);
  return 0;
}

void pascal_triangle(int n) {
  // STUDENTS MUST COMPLETE THE REST OF IMPLEMENATION OF THIS FUNCTION
  int i = 0;
  int array1 [20] = {0};
  int array2 [20] = {0};
  int* p1 = array1; // Points to the current array
  int* p2 = array2; // Points to the previous array
  
  
  while (i<n)
  {
    int j = 0;
    int* swap;
    printf("row %d:\t", i);
    
    do 
    {
      // Calculate the current array values
      if ((j == 0) || (j == i))
      {
        p1[j] = 1;
      }
      else
      {
        p1[j] = p2[j - 1] + p2[j];
      }
      printf("%d\t", p1[j]);
      j++;
    } while (j <= i);
    
    // Write new data to the previous array by swapping them
    swap = p1;
    p1 = p2;
    p2 = swap;
    printf("\n");
    i++;
  }
}
