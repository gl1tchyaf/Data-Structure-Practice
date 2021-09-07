#include <stdio.h>

int main()
{
    int n,s=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i=i+2){
        s=s+(i+1)*i;
    }
    printf("%d",s);
}
