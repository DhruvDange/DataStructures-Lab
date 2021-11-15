#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[20];
    int usn;
    struct Student *next;
}Student;

Student *front;
Student *rear;

void enQueue(){

    Student *newStudent = (Student *) malloc(sizeof(Student));
    printf("Enter Student name: ");
    scanf("%s", newStudent->name);
    printf("Enter Student usn: ");
    scanf("%d", &newStudent->usn);
    newStudent->next = NULL;

    if(front == NULL){
        front = rear = newStudent;
    }else{
        rear->next = newStudent;
        rear = newStudent;
    }

}

void deQueue(){

    Student *ptr = front;

    if(ptr == NULL){
        printf("Queue is empty! Underflow\n");
        return;
    }else{
        front = front->next;
        printf("Student with name: %s, usn: %d deleted!\n", ptr->name, ptr->usn);
        free(ptr);
    }

}

void display(){

    Student *ptr = front;
    if(ptr == NULL){
        printf("Queue is empty");
    }else{
        while(ptr != NULL){
            printf("Student name: %s\t usn: %d\t next:%d\n", ptr->name, ptr->usn, ptr->next);
            ptr = ptr->next;
        }
    }

}

void main(){
    front = rear = NULL;
    int choice;
    printf("Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do{
        
        printf("\nEnter choice: \n");
        scanf("%d", &choice);

        switch(choice){
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
                break;
            default:
                printf("Invalid choice...enter again!");
        }
    }while(1);
}
