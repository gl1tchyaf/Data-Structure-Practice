#include<stdio.h>

int pf(int num , int result){

if(num == 0){
    return result;
}
result = (result*10)+(num%10);
return pf(num/10,result);

}

int main(){

int num,palindrome;

printf("Enter a value: ");
scanf("%d",&num);
palindrome = pf(num,0);
if(palindrome == num){
    printf("%d : palindrome",num);
}else{
    printf("%d : not palindrome",num);
}

return 0;

}


