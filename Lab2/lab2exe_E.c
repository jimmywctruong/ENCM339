/*
 *
 * lab2exe_E.c
 * ENCM 339 Fall 2017 - Lab 2 - Execise E
 *
 *  Functions to read numbers with input error detection.
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int read_int(void);
/*
 *  REQUIRES
 *      User has been prompted to type in an int.
 *  PROMISES
 *      If an int can be read from the standard input stream, that
 *      int is the return value.  If not, an error message is printed
 *      and exit is called with an argument of 1.
 */

double read_double(void);
/*
 *  REQUIRES
 *      User has been prompted to type in a double.
 *  PROMISES
 *      If a double can be read from the standard input stream, that
 *      double is the return value.  If not, an error message is printed
 *      and exit is called with an argument of 1.
 */

int main(void)
{
  int the_int;
  double the_double;

  printf("Doing tests of read_int and read_double functions ...\n\n");  
  
  printf("Please try to enter an int: ");
  the_int = read_int();
  
  printf("read_int succeeded.  It read a value of %d.\n", the_int);

  printf("Please try to enter a double: ");
  the_double = read_double();
  
  printf("read_double succeeded.  It read a value of %g.\n", the_double);
  

  return 0;
}


int read_int(void)
{
  int in, c;
  scanf("%d", &in);
  
  c = fgetc(stdin);
  
  if (!((c == '\n') || (c == EOF)))
  {
    printf("Error, input was not an integer. Exiting...");
    exit(1);
  }
  return in;
}

double read_double(void)
{
  double lf;
  int c;
  scanf("%lf", &lf);
  
  c = fgetc(stdin);
  
  if (!((c == '\n') || (c == EOF)))
  {
    printf("Error, input was not a double. Exiting...");
    exit(1);
  }
  return lf;
}
