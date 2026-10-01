#include<stdio.h>
void printReverse(int n){
    if(n==1){
        printf("%d ",n);
    }else{
        printf("%d ",n);
        printReverse(n-1);
    }
}

void printNormal(int n){
    if(n==1){
        printf("%d ",n);
    }else{
        printNormal(n-1);
        printf("%d ",n);
    }
}

int main(){
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);

    printReverse(n);
    printf("\n");
    printNormal(n);
    return 0;
}


