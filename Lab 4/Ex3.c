#include<stdio.h>

int lcm(int a , int b){

static int mp = 0;
mp = mp + a;
if(mp%a == 0 && mp%b == 0){
    return mp;
}else{
    return lcm(a,b);
}

}

int main(){

int a,b,result;

printf("Input first number: ");
scanf("%d",&a);
printf("Input second number: ");
scanf("%d",&b);
result = lcm(a,b);
printf("Output LCM: %d",result);

return 0;

}


