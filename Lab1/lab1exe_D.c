/*
*  lab1exe_D.c
*  ENCM 339 - Fall 2017 Lab 1, exercise D
*  Completed by: 	Jimmy Truong (30017293)
*  Lab Section:     B04
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
	create_table(velocity);
    
    return 0;
}
void create_table(double velocity) 
{
	printf("Angle\t\tTime\t\tDistance\n");
	printf("(deg)\t\t(sec)\t\t(m)\n");
	for (double theta = 0; theta < 91; theta += 5)
	{
		printf("%lf\t%lf\t%lf\n", theta, Projectile_travel_time(degree_to_radian(theta), velocity), Projectile_travel_distance(degree_to_radian(theta), velocity));
		
		
	}
	
}
double Projectile_travel_time(double angle, double velocity)
{
	return 2 * velocity * sin(angle) / G;
}
double Projectile_travel_distance(double angle, double velocity)
{
	return velocity * velocity * sin(2 * angle) / G;
}

double degree_to_radian (double degree)
{
	return degree * PI / 180;
	
}
/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */

