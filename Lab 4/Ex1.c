#include<stdio.h>

int pw(int b, int p){

if(p==0){
    return 1;
}else{
    return b*pw(b,p-1);
}

}
int main(){

int b , p , result;

printf("Input a number: ");
scanf("%d",&b);
printf("Input power: ");
scanf("%d",&p);
result = pw(b,p);
printf("Result: %d",result);

return 0;

}


