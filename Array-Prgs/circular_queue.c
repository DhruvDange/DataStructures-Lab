#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enQueue(){

    int item;
    if(front == rear + 1 || (front == 0 && rear == SIZE -1)){
        printf("QUEUE IS FULL!! OVERFLOW\n");
    }else{
        if(front == -1)
            front = 0;
        printf("Enter element to insert: ");
        scanf("%d", &item);
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

void deQueue(){

    int item;

    if(front == -1){
        printf("Queue is empty! Underflow\n");
        return;
    }else{
        item = queue[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % SIZE;
        }
        printf("Item %d removed from queue!\n", item);
    }
}

void display(){

    if(front == -1){
        printf("Queue is empty!\n");
    }else{
        if(rear > front){
            for(int i = front; i <= rear; i++){
                printf("%d \t", queue[i]);
            }
        }else{
            for(int i = front; i <= SIZE-1; i++){
                printf("%d \t", queue[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d \t", queue[i]);
            }
        }
        printf("\n");
    }
}

int main()
{

    int choice;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            enQueue();
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
