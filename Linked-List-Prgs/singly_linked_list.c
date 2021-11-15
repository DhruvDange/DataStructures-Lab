// Author: Dhurv Dange

#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int usn;
    struct Student * next;
}Student;

Student *head;

int sCount;

Student * createStudentNode(Student * ptr){

    // Create a new node
    Student * newStudent = (Student *) malloc(sizeof(Student));
    // Enter details
    printf("Enter details for Student to be added: \n");
    printf("Enter student name:");
    scanf("%s", newStudent->name);
    printf("Enter student usn:");
    scanf("%d", &newStudent->usn);
    newStudent->next = ptr;
    sCount++;

    return newStudent;
}

Student * searchStudent(int usnToSearch){
    Student *ptr = head;
    int chk = 0;
    
    if(ptr != NULL)
        do{
            if(ptr -> usn == usnToSearch)
                return ptr; // Break and return only 1st occurance
            ptr = ptr -> next;
        }while(ptr != NULL);

    if(chk == 0)
        printf("Student with usn %d not found!\n", usnToSearch);

    return 0;
}


void addStart(){
    Student * newStudent = createStudentNode(head);

    // Move head to new node as its first node in LL now
    head = newStudent;
}

void addEnd(){
    // Find last node
    Student *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    Student * newStudent = createStudentNode(NULL);
    // new node doesnt point at any node. Add new node to LL
    ptr->next = newStudent;
}

void addAny(){
    int usnToSearch;
    int pos = -1;
    Student * addNextTo = NULL;
    Student *ptr = head;

    if(ptr == NULL){
        addStart();
        return;
    }
    
    // get info about where to add
    do{
        printf("\nEnter student usn you want to insert next to: ");
        scanf("%d", &usnToSearch);
        addNextTo = searchStudent(usnToSearch);
    }while(!addNextTo); // if it returns a value (true), we negate to stop the loop(false)

    do{
        printf("\nWould u like to insert before or after this student?\n");
        printf("Enter 1 for BEFORE or 2 for AFTER\n");
        scanf("%d", &pos);
    }while(!(pos != 1 || pos != 2)); // if pos is 1 or 2 we get true...so we negate the value and vice-versa

    // Possible insert locations and logic
    if(pos == 1){
        if(addNextTo == head){
            addStart();
        }else{
            while(ptr->next != addNextTo)
                ptr = ptr->next;
            Student * newStudent = createStudentNode(addNextTo);
            ptr->next = newStudent;
        }
    }else if(pos == 2){
        if(addNextTo->next == NULL){
            addEnd();
        }else{
            Student * newStudent = createStudentNode(addNextTo->next);
            addNextTo->next = newStudent;
        }
    }
}

void deleteStudent(){
    int usnToDelete;
    Student *nodeToDelete = NULL;
    Student *prevNode = head; /* used to traverse thro LL to find node before the one to be deleted */
    
    do{
        printf("Enter usn to delete.\n");
        scanf("%d", &usnToDelete);
        nodeToDelete = searchStudent(usnToDelete);
    }while(!nodeToDelete);

    if(nodeToDelete == head){
        printf("Deleting first node...\n");
        head = head->next;
        free(nodeToDelete);
    } else if(nodeToDelete->next == NULL){
        printf("Deleting last node...\n");
        while(prevNode->next != nodeToDelete)
            prevNode = prevNode->next;
        prevNode->next = NULL;
        free(nodeToDelete);
    }else{
        while(prevNode -> next != nodeToDelete)
            prevNode = prevNode->next;
        prevNode->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    sCount--;
}

void display(){
    Student *ptr = head;

    if(ptr == NULL){
        printf("No students in the list!\n");
        return;
    }

    while(ptr != NULL){
        printf("Name: %s\tusn: %d\t next: %d\n", ptr->name, ptr->usn, ptr->next);
        ptr = ptr -> next;
    }
    printf("\n");
}

void main(){
    head = NULL;
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
        printf("\n \n");

        switch (choice){
            case 1:
                addStart();
                break;
            case 2:
                addEnd();
                break;
            case 3:
                addAny();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                ptr = searchStudent(usnToSearch);
                if(ptr){
                    printf("Student found!\n");
                    printf("Name: %s\tusn: %d\n", ptr->name, ptr->usn);
                    free(ptr);
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
    }while(1);
}