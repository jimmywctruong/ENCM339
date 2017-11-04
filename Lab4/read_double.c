#include "read_input.h"
#include <math.h>


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
  
  // Invalid checking loop
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
    // Finds non-digits
    if (digits[i] < '0' || digits[i] > '9')
      return 0;
  }

  return 1;
}

double convert_to_double (const char* digits)
{
  double num = 0;
  double fraction = 0;
  int decimal = 0;

  for (int i = 0; digits[i] != '\0'; i++)
  {
    // Changes from integer mode to decimal mode if digits[i] == '.'
    if (digits[i] == '.')
    {
      decimal = 1;
      i++; // '.' is processed, move to the next number
    }

    if (decimal > 0)
    {
      // Reads the fraction component
      fraction = fraction*10 + (digits[i] - '0');
      decimal++;
    } 
    else // Reads the integer component
      num = num*10 + (digits[i] - '0');
  }
  // outputs the integer and fractional component
  return num + fraction/pow(10, decimal);
}

