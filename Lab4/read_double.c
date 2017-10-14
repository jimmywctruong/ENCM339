#include "read_input.h"


int read_real(char* digits, int n, double* num)
{
  int i = 0;
  if (get_string(digits, n) == EOF)
    return -1;

  // i marks the beginning of the first digit
  if ((digits[0] == '+') || (digits[0] == '-'))
    i++;

  if (is_valid_double(&digits[i]))
  {

    if (digits[0] == '-')
      *num = -convert_to_double(&digits[i]);
    else
      *num = convert_to_double(&digits[i]);
    return 1;
  }

  return 0;
  

}

int is_valid_double(const char* digits)
{
  int decimal = 0;
  
  // Invalid double loop
  for (int i = 0; digits[i] != '\0'; i++)
  {
    // Catches and allows first decimal to pass
    if (digits[i] == '.')
    {
      decimal++;
      i++;
      if (decimal > 1)
      {
        return 0;
      }
    }
    // Fails for non-digits
    if (digits[i] < '0' || digits[i] > '9')
      return 0;
  }

  return 1;
}
double convert_to_double (const char* digits)
{
  double num = 0;
  int decimal = 0;
  int place = 1;

  for (int i = 0; digits[i] != '\0'; i++)
  {
    // Changes from integer mode to decimal mode if digits[i] == '.'
    if (digits[i] == '.')
    {
      decimal = 1;
      i++;
    }

    if (decimal == 1)
    {
      // Starts adding the shifted decimal portion
      num += (digits[i] - '0')*decimal_place(place);
      place++;
    } 
    else // Shifts and adds the integer portion
      num = num*10 + (digits[i] - '0');
  }

  return num;
}

double decimal_place (int place)
{
  // Provides the appropriate decimal multiplier. 
  // Ex. decimal_place(2) == 0.01, 0.05 = 5 * 0.01
  double value = 1;
  while (place > 0)
  {
    value /= 10;
    place--;
  }

  return value;
}