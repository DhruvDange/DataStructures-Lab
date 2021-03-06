#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top;
int s[SIZE];
int item;

void push()
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s[++top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("UnderFlow\n");
        return 0;
    }
    return s[top--];
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Contents of the Stack :\n");
    for (i = 0; i <= top; i++)
    {
        printf("%d\n", s[i]);
    }
}

int main()
{
    int item_del, choice;
    top = -1;
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
            push();
            break;
        }
        case 2:
        {
            item_del = pop();
            if (item_del == 0)
            {
                printf("Stack Underflow\n");
            }
            else
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