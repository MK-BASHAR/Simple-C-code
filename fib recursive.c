#include <stdio.h>
int fib(int n){
 if(n==1){
    return 0;
 }
 else if(n==2){
    return 1;
 }
 else {
    int n1=fib(n-1);
    int n2=fib(n-2);
    return n1+n2;
 }

}
int main(){

 int n;

 printf("enter number:");
 scanf("%d",&n);

 int result=fib(n);

 printf("result=%d",result);

 return 0;
}
