#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50

double arr[SIZE];
int top = -1;

void push(double num)
{
    if(top == SIZE - 1){
        printf("Overflow");
        return;
    }
    arr[++top] = num;
}

double pop(){
    if(top == -1){
        printf("Underflow");
        return;
    }
    return arr[top--];
}

int isDigit(char symbol){
    return (symbol >= '0' && symbol <= '9');
}

double op(double num1, double num2, char symbol){
    switch(symbol){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
        case '$':
            return pow(num1, num2);
    }
}

double eval(char *postfix){
    int i = 0;
    while(postfix[i] != '\0'){
        char sym = postfix[i];
        if(isDigit(sym)){
            push(sym - '0');
        }else{
            double num2 = pop();
            double num1 = pop();
            push(op(num1, num2, sym));
        }
        i++;
    }
    return pop();
}

void main(){
    char expr[SIZE];
    double res;

    scanf("%s", expr);
    res = eval(expr);
    printf("resilt is: %lf", res);
}