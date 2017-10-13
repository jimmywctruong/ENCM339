/* lab4exB.c
 * ENCM 339 - Fall 2017 lab 4 - exercise B
 */

#include <stdio.h>

void funct (const char x [8], char y[], int n);

int main()
{
    // It is unusual to intialize a string with '\0' in the middle of string,
    // but it's allowed and we did it delibrately for the educational pruposes.
    const char* sc = "\n\0map";
    
    char sa[5] = {'\0'};
    
    while (*sc) sc++;
    
    sc += 3;
    
    // Point One
    
    funct(sc, sa, &sa[5] - &sa[0]);
    
    for(int k = 0; k < 6; k++)
    {
      printf("%d ", sc[1-k]);
    }
    printf("\n");
    for(int k = 0; k < 5; k++)
    {
      printf("%d ", sa[k]);
    }
    
    return 0;
}

void funct (const char x[8], char y[], int n)
{
    
    while (n ) {
        y[0] = x[0];
        n--;
        x--;
        y++;
    }
    printf("%d %d\n", x[1], y[-1]);
    printf("%d %d\n", x[0], y[0]);
    // Point Two
    
}
