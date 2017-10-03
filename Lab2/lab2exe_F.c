#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void get_user_input(double* distance, double* speed);
/* 
  REQUIRES:
    distance and speed have variable addresses.
  PROMISES: 
    Stores the first valid user input in km into distance.
    If the input is not a double, reprompts the user for a valid
    distance.
    
    Stores the second valid user input in km/hr into speed.
    If the input is not a double, reprompts the user for a valid speed.
*/
void travel_time_hours_and_minutes(double distance, double speed, double* hours,
 double* minutes);
/* 
  PROMISES: Calculates the time as distance/speed.
    Converts the time to hours and minutes, and stores them in hours and minutes
*/

void display_info(double distance, double speed, double hours, double minutes);
/*  
  PROMISES: 
    Prints the distance, speed, hours and minutes in a readable format on the 
    screen.
*/

void clean_buffer(void);
/* 
  PROMISES: 
    Cleans the buffer for a new scanf call.
    If the next character in the buffer is not a '\n' or an EOF,
    all non '\n' or EOF characters are removed.
*/

int main()
{
  double distance, speed, hours, minutes;
  
  get_user_input(&distance, &speed);
  travel_time_hours_and_minutes(distance, speed, &hours, &minutes);
  display_info(distance, speed, hours, minutes);
  
  return 0;
}

void get_user_input(double* distance, double* speed)
{
  char c = 0;
  do
  {
    
    printf("Please enter a travel distance in km: ");
    scanf("%lf", distance);
    c = fgetc(stdin);
    
    if ((c == '\n') || (c == EOF)) // if (input is double)
    {
      break;
    } else {
      clean_buffer();
    }
    
    
  } while(1);
  
  do
  {
    printf("Please enter a travel speed in km/hr: ");
    scanf("%lf", speed);
    c = fgetc(stdin);
    
    if ((c == '\n') || (c == EOF)) // if (input is double)
    {
      break;
    } else {
      clean_buffer();
    }
    
    
  } while(1);
}

void clean_buffer(void)
{
  char c;
  while(1)
  {
    c = fgetc(stdin);
    if ((c == '\n') || (c == EOF))
    {
      break;
    }
  }
}

void travel_time_hours_and_minutes(double distance, double speed, double* hours, double* minutes)
{
  double time = distance/speed;
  *hours = floor(time);
  *minutes = (time - *hours) * 60;
  
}

void display_info(double distance, double speed, double hours, double minutes)
{
  printf("Travelling %.2lf km at %.2lf km/h will take %.2lf hour(s) and %.2lf"
         " minute(s).", distance, speed, hours, minutes);  
}