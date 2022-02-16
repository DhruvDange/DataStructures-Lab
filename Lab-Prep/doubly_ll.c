#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    struct Student *prev;
    int data;
    struct Student *next;
}Student;

Student *head = NULL, *rear = NULL;

Student *createNode(int data, Student* prev, Student *next){
    Student *newNode = (Student *) malloc(sizeof(Student));
    newNode->data = data;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

Student *searchNode(int data){
    Student *ptr = head;
    do{
        if(ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }while(ptr!= NULL);
    return NULL;
}

void addStart(int data){
    
    if(head == NULL){
        head = createNode(data, NULL, NULL);
        rear = head;
    }else{
        head->prev = createNode(data, NULL, head);
        head = head->prev;
    }
}

void addEnd(int data){
    if(rear == NULL){
        printf("List is empty! Please add in the begining first.\n");
        return;
    }

    rear->next = createNode(data, rear, NULL);
    rear = rear->next;
}

void addAny(int data){
    if(head == NULL){
        addStart(data);
    }else{
        int usnToSearch;

        printf("Enter roll no of student to add next to: ");
        scanf("%d", &usnToSearch);

        Student *search = searchNode(usnToSearch);

        if(search){
            int choice;

            printf("Would u like to add student before or after?\n");
            printf("Enter 1 for BEFORE or 2 for AFTER\n");
            scanf("%d", &choice);

            if(choice == 1){
                if(search == head){
                    addStart(data);
                }else{
                    Student *node = createNode(data, search->prev, search);
                    search->prev->next = node;
                    search->prev = node;
                }
            }else if(choice == 2){
                if(search == rear){
                    addEnd(data);
                }else{
                    Student *node = createNode(data, search, search->next);
                    search->next = node;
                    search->next->prev = node;
                }
            }
        }
    }
}

void delete(int data){
    if(head == NULL){
        printf("LL IS EMPTY\n");
        return;
    }

    Student *search = searchNode(data);

    if(search){
        if(search == head){
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
        }else if(search == rear){
            rear = rear->prev;
            rear->next = NULL;
        }else{
            search->prev->next = search->next;
            search->next->prev = search->prev;
        }
    }

}
