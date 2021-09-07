#include<stdio.h>

int gcd(int a , int b){

if(a == 0){
    return b;
}
else if(b == 0){
    return a;
}else{
    gcd(b, a%b);
}

}

int main(){

int a,b,result;

printf("Input first number: ");
scanf("%d",&a);
printf("Input second number: ");
scanf("%d",&b);
result = gcd(a,b);
printf("Output GCD: %d",result);

return 0;

}

int gcd(int a , int b){

if(a == 0){
    return b;
}
else if(b == 0){
    return a;
}else{
    gcd(b, a%b);
}

}
