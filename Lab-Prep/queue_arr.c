#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enQueue(int item)
{
    if(rear == SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = item;
}

int deQueue()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    { 
        if(front == rear)
        {
            front = rear = -1;
        }
        else{
            front ++;
        }
    }
}

void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!\n");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int element, ch;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n...");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be enqueued: ");
            scanf("%d", &element);
            enQueue(element);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
