/* File: lab5exD.c
 * ENCM 339 Fall 2017- lab 5 - Exercise D
 */

#include "lab5ExD.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point alpha = { "A1", 2.3, 4.5, 56.0 } ;
    Point beta = { "B1", 25.9, 30.0, 97.0 } ;
    printf ("Display the values in alpha, and beta: ");
    display_struct_point(alpha);
    display_struct_point(beta);
    
    Point *stp = &alpha;
    printf ("\n\nDisplay the values in *stp: ");
    display_struct_point(*stp);
    
    Point gamma = mid_point(stp, &beta, "M1");
    printf ("\n\nDisplay the values in gamma after calling mid_point function.");
    printf ("Expected result is: M1 <14.10, 17.25, 76.50>");
    
    printf("\n\nThe actual result of calling mid_point function is: ");
    display_struct_point(gamma);
    
    swap (stp, &beta);
    printf ("\n\nDisplay the values in *stp, and beta after calling swap function.");
    printf ("Expected to be:\nB1 <25.90, 30.00, 97.00>\nA1 <2.30, 4.50, 56.00>");
    
    
    printf("\n\nThe actual result of calling swap function is: ");
    display_struct_point(*stp);
    display_struct_point(beta);
    
    
    printf("\n\nThe distance between alpha and beta is: %.2f. ", distance(&alpha, &beta));
    printf ("(Expected to be: 53.74)");
    printf("\nThe distance between gamma and beta is: %.2f. ", distance(&gamma, &beta));
    printf ("(Expected to be: 26.87)");
    return 0;
}

void display_struct_point(const Point x)
{
    printf("\n%s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


Point mid_point(const Point* p1, const Point* p2, const char* label)
{
    // This function is incomplete and must be completed by the students
    // YOU ARE NOT ALLOWED TO USE ANY STRING LIBRARY FUNCTIONS IN THIS FUNCTION
    
    Point middle;

    // copy up to and including the first 9 characters of label into middle.label
    // leaving room for '\0'
    int i = 0;
    // stop on the '\0' of label or after the 9th write operation
    while ( label[i] && (i < 9) ) 
    {
        middle.label[i] = label[i];
        i++;
    }
    // add the '\0' at the end
    middle.label[i] = '\0';

    // midpoint of two numbers is (a1 + a2)/2
    middle.x = ((*p1).x + (*p2).x)/2;
    middle.y = ((*p1).y + (*p2).y)/2;
    middle.z = ((*p1).z + (*p2).z)/2;
    
    return middle;
}

void swap(Point* p1, Point *p2)
{
 
    // This function is incomplete and must be completed by the students

    // points are user structures that must be copied subvalue by subvalue
    // or entire point sized memory chunks at a time
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return;
}

double distance(const Point* p1, const Point* p2)
{

    // This function is incomplete and must be completed by the students
    // NOTE: IN THIS FUNCTION YOU ARE NOT ALLOWED TO USE THE ARROW OPERATOR ->

    // 3 dimension distance between two points formula
    return sqrt(
        pow( (*p1).x - (*p2).x, 2 ) + 
        pow( (*p1).y - (*p2).y, 2 ) + 
        pow( (*p1).z - (*p2).z, 2 ) );
}

