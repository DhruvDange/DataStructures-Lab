#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    struct Student *prev;
    char name[20];
    int usn;
    struct Student *next;
}Student;

int sCount;
Student *head;
Student *rear;

Student * createNewNode(){
    Student *newStudent  = (Student *) malloc(sizeof(Student));
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student usn: ");
    scanf("%d", &newStudent->usn);
    sCount++;
    return newStudent;
}

Student * search(int usnToSearch){

    Student *ptr = head;

    while(ptr != NULL){
        if(ptr -> usn == usnToSearch)
            return ptr; // Break and return only 1st occurance
        ptr = ptr -> next;
    }

    return NULL;
}

void addFront(){

    Student *newStudent = createNewNode();

    if(head == NULL){
        newStudent->next = newStudent->prev = NULL;
        head = rear = newStudent;
    }else{
        newStudent->prev = NULL;
        newStudent->next = head;
        head->prev = newStudent;
        head = newStudent;
    }

}

void addEnd(){

    if(rear == NULL){
        printf("List is empty! Please add in the begining first.\n");
        return;
    }

    Student *newStudent = createNewNode();

    newStudent->prev = rear;
    rear->next = newStudent;
    newStudent->next = NULL;
    rear = newStudent;

}

void addAny(){

    if(head == NULL){
        addFront();
    }else{
        int usnToSearch;

        printf("Enter roll no of student to add next to: ");
        scanf("%d", &usnToSearch);

        Student *addNextTo = search(usnToSearch);

        if(addNextTo){
            int choice = -1;

            printf("Would u like to add student before or after?\n");
            printf("Enter 1 for BEFORE or 2 for AFTER\n");
            scanf("%d", &choice);

            if(choice == 1){
                if(addNextTo == head)
                    addFront();
                else{
                    Student *newStudent = createNewNode();
                    addNextTo->prev->next = newStudent;
                    newStudent->prev = addNextTo->prev;
                    newStudent->next = addNextTo;
                    addNextTo->prev = newStudent;
                }
            }else if(choice == 2){
                if(addNextTo == rear)
                    addEnd();
                else{
                    Student *newStudent = createNewNode();
                    addNextTo->next->prev = newStudent;
                    newStudent->next = addNextTo->next;
                    addNextTo->next = newStudent;
                    newStudent->prev = addNextTo;
                }
            }else{
                printf("Invalid choice... try again.\n");
            }
        }
    }
}



void deleteAny(){

    int usnToDelete;

    printf("Enter usn to delete:");
    scanf("%d", &usnToDelete);

    Student *nodeToDelete = search(usnToDelete);

    if(nodeToDelete){
        if(nodeToDelete == head){
            head = nodeToDelete->next;
            if(head != NULL)
                head->prev = NULL;
        }else if(nodeToDelete == rear){
            nodeToDelete->prev->next = NULL;
            rear = rear->prev;
        }else{    
            nodeToDelete->next->prev = nodeToDelete->prev;
            nodeToDelete->prev->next = nodeToDelete->next;  
        }
        printf("Stdudent with name: %s and usn %d deleted!", nodeToDelete->name, nodeToDelete->usn);
        sCount--;
        free(nodeToDelete);
    }

}

void display(){

    Student *ptr = head;

    if(ptr == NULL){
        printf("List is empty!\n");
        return;
    }else{
        while(ptr != NULL){
            printf("Prev: %d\t Student name: %s\t usn: %d\t Next: %d\n", ptr->prev, ptr->name, ptr->usn, ptr->next);
            ptr = ptr->next;
        }
    }

}

void main(){

    head = NULL;
    rear = NULL;
    sCount = 0;

    int usnToSearch;
    Student *ptr = NULL;

    int choice;

    do{
        printf("Menu:\n");
        printf("1. Add beginning\n");
        printf("2. Add end:\n");
        printf("3. Add any:\n");
        printf("4. Delete:\n");
        printf("5. Search:\n");
        printf("6. Display:\n");
        printf("7. Exit:\n");
        printf("Enter Choice: ");
        
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addFront();
                break;
            case 2:
                addEnd();
                break;
            case 3:
                addAny();
                break;
            case 4:
                deleteAny();
                break;
            case 5:
                printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                ptr = search(usnToSearch);
                if(ptr){
                    printf("Student found!\n");
                    printf("Name: %s\tusn: %d\n", ptr->name, ptr->usn);
                }
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }while(1);


}
