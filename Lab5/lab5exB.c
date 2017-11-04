//  ENCM 339 - fall 2017 - lab 5 -exercise B
//  lab5exB.c

#include <stdio.h>
#include "lab5exB.h"

const Date cd = {1, 1, 1970};
void printDate (Date *date);
void printTime (Time *time);
void printTimestamp (Timestamp *timestamp);

int main() {
    Timestamp *tsp;
    Time t = {0, 0, 24};
    Timestamp ts = {cd, &t};
    tsp = & ts;
    change_date_time(&tsp->date, &t);
    
    printf("Timestamp ts: \n");
    printTimestamp(&ts);
    printf("Time t \n");
    printTime(&t);
    printf("Timestamp pt tsp: \n");
    printTimestamp(tsp);

    printf("Program Terminted.\n");
    return 0;
}

void change_date_time(Date *arg1, Time *arg2){
    
    arg1 -> day = 29;
    arg1 -> month = 10;
    arg1 -> year = 2016;
    (*arg2).second = 5;
    (*arg2).minute = 59;
    (*arg2).hour = 23;
    


    // Point one
}

void printDate (Date *date) {
    printf("Day: %d, Month: %d, Year: %d \n", date -> day, date -> month,
        date -> year);
}

void printTime (Time *time) {
    printf("Second: %d, Minute: %d, Hour: %d \n", time -> second, time ->
        minute, time -> hour);
}

void printTimestamp (Timestamp *timestamp)
{
    printf("Timestamp Date: ");
    printDate(&timestamp -> date);

    printf("Timestamp Time: ");
    printTime(timestamp -> time);
}