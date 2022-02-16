#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int top = -1;
int stack[SIZE];

void push(int item)
{
    if(top == SIZE - 1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    return(stack[top--]);
}

void display()
{
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    for(int i = 0; i <= top; i++){
        printf("%d \t", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, item, item_del;
    for (;;)
    {
        printf("Enter the choice -\n1. Push\n2. Pop\n3. Display\n4. Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter element-");
            scanf("%d", &item);
            push(item);
            break;
        }
        case 2:
        {
            item_del = pop();
            if (item_del)
            {
                printf("Item Deleted : %d\n", item_del);
            }
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Invalid Choice. Please Try Again");
        }
        }
    }
    return 0;
}