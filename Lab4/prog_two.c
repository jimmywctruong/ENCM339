#include <stdio.h>
#include "read_input.h"
#define SIZE 50

int main()
{
  int input_code = 0;
  int n_double;
  char* digits[SIZE];
  while(1)
  {
    printf("Enter a double or press Ctrl-D to quit: ");
    input_code = read_real(digits, SIZE, &n_double);

    if (input_code == 1)
    {
      printf("Your double value is: %f\n", n_double);

    }
    else if (input_code == 0)
    {
      printf("%s is an invalid double.\n", digits);
    }
    else if (input_code == -1)
    {
      printf("Good Bye.\n");
      break;
    }

  }
  return 0;
}