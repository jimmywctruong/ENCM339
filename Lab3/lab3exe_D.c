/* lab3exe_D.c
 * ENCM 339 Fall 2017, Lab 3 Exercise D
 */

#include <stdio.h>
#include <string.h>

int substring(const char *s1, const char *s2);
/* REQUIRES
 * s1 and s2 are valid C-string terminated with '\0';
 * PROMISES
 * returns one if s2 is a substring of s2). Otherwise returns zero.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 *   n_source >= 0.
 *   Elements source[0], source[1], ..., source[n_source - 1] exist.
 *   Elements negatives_only[0], negatives_only[1], ..., 
 negatives_only[n_source - 1] exist.
 * PROMISES
 *   number_of_negatives == number of negative values in source[0], ..., 
 source[n_source - 1].
 *   negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain 
 those negative values, in
 *   the same order as in the source array. 
 */

int main(void)
{
    char s[] = "Knock knock! Who's there?";
    int a[] = { -10, 9, -17, 0, -15 };
    int size_a;
    int i;
    int negative[5];
    int n_negative;
    
    size_a = sizeof(a) / sizeof(a[0]);
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    select_negatives(a, size_a, negative, &n_negative);
    printf("\nnegative elements from array a are as follows:");
    for (i = 0; i < n_negative; i++)
        printf("  %d", negative[i]);
    printf("\n");
    
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Who"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "knowk"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "knock"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, ""));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "ck! Who's"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "ck!Who's"));
    return 0;
}

int substring(const char *s1, const char* s2)
{
  if (strlen(s1) < strlen(s2))
  {
    return 0;
  }
  int i = 0, j, match = 0;
  
  
  while (s1[i] != '\0')
  {
    j = 0;
    
    if (s1[i] == s2[j]) // When true, assume match = 1 unless proven wrong
    {
      int marker = i;
      match = 1;
      
      while((s2[j] != '\0')) // Verifies whether match = 1 is true
      {
        if (s1[marker] != s2[j]) // Match = 1 was wrong
        {
          match = 0;
          break;
        }
        marker++;
        j++;
      }
    }
    
    if (match == 1) // One match is enough
      break;
    i++;
  }
  return match;
}

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives)
{

  int i = 0, j = 0;
  *number_of_negatives = 0;
  
  while (i < n_source)
  {
    if (source[i] < 0)
    {
      (*number_of_negatives)++;
      negatives_only[j] = source[i];
      j++;
    }
    i++;
  }
  
  
  return;
}

