#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char element){
    if(top == MAX - 1){
        printf("Overflow!\n");
    }else{
        stack[++top] = element;
    }
}

char pop(){
    if(top == -1){
        return '#';
    }else{
        return stack[top--];
    }
}

char peek(){
    if(top == -1)
        return '#';
    else
        return stack[top];
}

int priority(char symbol){
    switch(symbol){
        case '#':
            return -1;
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
        case '%':
            return 2;
        case '^':
        case '$':
            return 3;
    }
}

char *infixToPostfix(char *infix, char *postfix){
    int i = 0, j = -1;

    while(infix[i] != '\0'){
        
        if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(isalnum(infix[i]))
        {
            postfix[++j] = infix[i];
        }
        else if(infix[i] == ')')
        {
            while(peek() != '(')
            {
                postfix[++j] = pop();
            }
            pop();
        }
        else{
            while(priority(peek()) >= priority(infix[i]))
            {
                postfix[++j] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(peek() != '#'){
        postfix[++j] = pop();
    }
}

void main(){
    char expr[MAX], postfix[MAX];
    scanf("%s", expr);

    infixToPostfix(expr, postfix);
    printf("\n %s", postfix);
}