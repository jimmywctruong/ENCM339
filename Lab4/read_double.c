#include "read_input.h"


int read_real(char* digits, int n, double* num)
{
  int i = 0;
  if (get_string(digits, n) == EOF)
  {
    return -1;
  }
  /* i should be at the index of the first digit */
  if (digits[0] == '+' || digits[0] == '-')
  {
    i = 1;
  }

  if (is_valid_double(&digits[i]))
  {
    if (digits[0] == '-')
      *num = -convert_to_double(&digits[i]);
    *num = convert_to_double(&digits[i]);
    return 1;
  }

  return 0;
}

int is_valid_double(const char* digits)
{
  int decimal = 0;
  // Maximum one decimal place per float.
  for (int i = 0; digits[i] != '\0'; i++)
  {
    if (digits[i] <= '9' && digits[i] >= '0')
    {
      printf("Valid Double");
      continue;
    }
    
    if (digits[i] == '.' && decimal == 0)
    {
      decimal++;
      continue;
    }
    return 0;
  }
  printf("Valid Double");
  return 1;
}
double convert_to_double (const char* digits)
{
  double num = 0;
  int decimal = 0;
  int place = 1;
  while (*digits)
  {
    if (*digits == '.')
      decimal = 1;
    if (decimal == 1)
    {
      num += (*digits - '0')*decimal_place(place);
      place++;
    } 
    else 
    {
      num = num*10 + (*digits - '0');
    }
  }

  return num;
}

double decimal_place (int place)
{
  double value = 1;
  while (place > 0)
  {
    value /= 10;
    place--;
  }
  return value;
}