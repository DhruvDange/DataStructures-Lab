#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int arr[SIZE];
int front = -1, rear = -1;

void enQueue(int item){
    if(front == rear + 1 || (front == 0 && rear == SIZE - 1)){
        printf("Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    arr[rear] = item;
}

int deQueue(){
    if(front == -1){
        printf("Underflow\n");
        return;
    }
    int item = arr[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % SIZE;
    }
    return item;
}

void display(){

    if(front == -1){
        printf("Queue is empty!\n");
    }else{
        if(rear >= front){
            for(int i = front; i <= rear; i++){
                printf("%d \t", arr[i]);
            }
        }else{
            for(int i = front; i <= SIZE-1; i++){
                printf("%d \t", arr[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d \t", arr[i]);
            }
        }
        printf("\n");
    }
}

int main()
{

    int choice, item;

    while (1)
    {
        printf("\nEnter choice-\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            enQueue(item);
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