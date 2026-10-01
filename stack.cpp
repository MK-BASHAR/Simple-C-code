#include<stdio.h>

#include<iostream>
using namespace std;

#include<string.h>

class Stack{
    public:
    int top = -1;
    char arr[50];
    int size = 50;


    void push(char n){
    if(top+1==size){
        printf("Stack Overflow");
        return;
    }
    top++;
    arr[top]=n;
    }

    char pop(){
        if(top==-1){
            printf("Stack Underflow");
            return '\0';
        }
        top--;
        return arr[top+1];
    }

    void printStack(){
        printf("\n**************\n");
        for(int i=0;i<=top;i++){
            printf("%c ",arr[i]);
        }
        printf("\n**************\n");

    }

};

int main(){
    char str[20];
//    cin>>str;
//    cout<<str;
    gets(str);
    cout<<"You entered the string "<<str<<endl;

    Stack s1;

    for(int i=0; str[i]!='\0' ; i++){
        s1.push(str[i]);
    }

    s1.printStack();

    for(int i=0; str[i]!='\0' ; i++){
        str[i]=s1.pop();
    }

    cout<<"The condition of str"<<endl;
    puts(str);

    return 0;
}
