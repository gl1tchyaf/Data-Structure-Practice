#include <stdio.h>
int main()
{
    double i, s = 0.0;
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
      s = s + 1/i;
      }
    printf("Sum is %.2f", s);
    return 0;
}
