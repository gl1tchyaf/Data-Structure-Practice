#include <stdio.h>


int main()
{
   int n, c, k;
  for (c = 1; c <= 5; c++)
  {
    for (k = 1; k <= 5-c; k++)
      printf(" ");
    for (k = 1; k < c; k++)
      printf("* ");
    printf("*\n");
  }
  return 0;
}
