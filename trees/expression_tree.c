#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

typedef struct eTree{
    struct eTree *left;
    char data;
    struct eTree *right;
}eTree;

eTree *stack[SIZE]; // Array of type struct pointer
int top = 0;


// push to stack
void push(eTree *newNode){
    stack[++top] = newNode;
}

// pop from stack
eTree *pop(){
    return stack[top--];
}

// 1 if alnum, 2 if symbol
int verify(char c){
    if(isalnum(c))
        return 2;
    else 
        return 1;    
}

// if node is operand-> push to stack, make left = right = NULL
void operand(char c){
    eTree *newNode = (eTree *) malloc(sizeof(eTree));
    newNode->data = c;
    newNode->left = newNode->right = NULL;
    push(newNode);
}

// if node is operator-> make right and left stack elements, push to stack
void operator(char c){
    eTree *newNode = (eTree *) malloc(sizeof(eTree));
    newNode->data = c;
    newNode->right = pop();
    newNode->left = pop();
    push(newNode);
}

void inOrder(eTree *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf(" %c ", root->data);
    inOrder(root->right);
}

void preOrder(eTree *root){
    if(root == NULL)
        return;
    printf(" %c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int evaluate(eTree *root){
    int opr = verify(root->data);
    if (opr == 1)
    {
        if (root->data == '+')
        {
            return (evaluate(root->left) + evaluate(root->right));
        }
        else if (root->data == '-')
        {
            return(evaluate(root->left) - evaluate(root->right));
        }
        else if (root->data == '*')
        {
            return(evaluate(root->left) * evaluate(root->right));
        }
        else if (root->data == '/')
        {
            return(evaluate(root->left) / evaluate(root->right));
        }
        else if (root->data == '^' || root->data == '$')
        {
            return(pow(evaluate(root->left),evaluate(root->right)));
        }
    }
    else if (opr == 2)
        return (root->data - '0');
}

int main(){
    char postfix[SIZE];
    printf("\nEnter a valid postfix expression : ");
    scanf("%s", postfix);

    for(int i = 0; postfix[i] != '\0'; i++){
        int opr = verify(postfix[i]);
        if(opr == 1) operator(postfix[i]);
        else if(opr == 2) operand(postfix[i]);
    }
    printf("\nInfix Notation : ");
    inOrder(stack[top]);
    printf("\nPrefix Notation : ");
    preOrder(stack[top]);
    printf("\nResult : %d",evaluate(stack[top]));
}
