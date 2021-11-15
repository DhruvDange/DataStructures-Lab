#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[20];
    int usn;
    struct Student * next;
}Student;

Student *head;

void push(){
    Student *newStudent = (Student *) malloc(sizeof(Student));

    if(!newStudent){
        printf("Cant push item into stack! Memory full.\n");
    }else{
        printf("Enter Student Name: ");
        scanf("%s", newStudent->name);
        printf("Enter Student usn: ");
        scanf("%d", &newStudent->usn);

        if(head == NULL){
            // First elemnt
            newStudent->next = NULL;
            head = newStudent;
        }else{
            newStudent->next = head;
            head = newStudent;
        }
    }
}

void pop(){
    if(head == NULL){
        printf("Stack is empty. Underflow!\n");
    }else{
        Student *ptr = head;
        printf("Student with name: %s and usn: %d deleted!", ptr->name, ptr->usn);
        head = head->next;
        free(ptr);
    }
}

void display(){
    Student *ptr = head;

    if(head == NULL){
        printf("Stack is empty\n");
    }

    while(ptr != NULL){
        printf("Studdent name: %s, usn: %d, next node: %d\n", ptr->name, ptr->usn, ptr->next);
        ptr = ptr->next;
    }

}

void main(){
    head = NULL;
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
                push();
                break;
            case 2:
                pop();
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