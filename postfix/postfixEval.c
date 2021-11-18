#include<stdio.h>
#include<math.h>

#define MAX 50

double stack[MAX];
int top = -1;

void push(double element){
    if(top == MAX - 1){
        printf("Stack ovwrflow");
    }else{
        stack[++top] = element;
    }
}

double pop(){
    if(top == -1){
        return 0;
    }else{
        return stack[top--];
    }
}

double evaluate(double op1, double op2, char symbol){
    switch(symbol){
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '^':
        case '$':
            return pow(op1, op2);
    }
}

int isDigit(char op){
    return (op >= '0' && op <= '9');
}

double evalPostfix(char *postfix){
    int i = 0;
    double op1, op2, res;
    char symbol;

    while(postfix[i] != '\0'){
        symbol = postfix[i];
        if(isDigit(symbol)){
            push(symbol - '0');
        }else{
            op2 = pop();
            op1 = pop();
            res = evaluate(op1, op2, symbol);
            push(res);
        }
        i++;
    }
    return pop();
}

void main(){
    char expr[MAX];
    double res;

    scanf("%s", expr);
    res = evalPostfix(expr);
    printf("resilt is: %lf", res);
}