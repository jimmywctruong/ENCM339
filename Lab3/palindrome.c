/* File: palindrome.c
 *  ENCM339 - Fall 2017
 *  Exercise E - Lab 3
 *  Abstract: The program receives a string (one or more words) and indicates
 *  if the string is a palindrome or not. Plaindrome is a phrase that spells the
 *  same from both ends
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


/* function prototypes*/
int is_palindrome (const char *str);
/* REQUIRES: str is pointer to a valid C string.
 * PROMISES: the return value is 1 if the string a is palindrome.*/


void strip_out(char *str);
/* REQUIRES: str points to a valid C string terminated with '\0'.
 * PROMISES: strips out any non-alphanumerical characters in str*/

int main(void)
{
    int p =0;
    char str[SIZE], temp[SIZE];
    
    fgets(str, SIZE, stdin);
    
    /* Remove end-of-line character if there is one in str.*/
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    strcpy(temp,str);
    
    /* This loop is infinite if the string "done" never appears in the
     * input.  That's a bit dangerous, but OK in a test harness where
     * the programmer is controlling the input. */
    
    while(strcmp(str, "done") !=0) /* Keep looping unless str matches "done". */
    {
        
#if 1
        strip_out(str);
        
        p = is_palindrome(str);
#endif
        
        if(!p)
            printf("\n \"%s\" is not a palindrome.", temp);
        else
            printf("\n \"%s\" is a palindrome.", temp);
        
        fgets(str, SIZE, stdin);
        
        /* Remove end-of-line character if there is one in str.*/
        if(str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1]= '\0';
        strcpy(temp, str);
    }
    return 0;
}


void strip_out(char *str)
{
  int i = 0, j = 0;
  while (str[i] != '\0')
  {
    if (isalnum(str[i]))
    {
      str[j] = tolower(str[i]);
      j++;
    }
    i++;
  }
  str[j] = '\0';

}

int is_palindrome (const char *str)
{
  char* start = str;
  char* end = str + strlen(str) - 1;
  int pallindrome = 1; // Assume palindrome unless proven wrong

  while (start < end)
  {
    if (*start != *end)
    {
      pallindrome = 0;
      break;
    }
    start++;
    end--;
  }
  
  return pallindrome;
}


