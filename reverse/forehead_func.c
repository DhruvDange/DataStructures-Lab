#include "forehead.h"
#include <stdio.h>
#include <stdlib.h>

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

    while(ptr != NULL){
        if(ptr -> usn == usnToSearch)
                return ptr; // Break and return only 1st occurance
        ptr = ptr -> next;
    }
    
    return NULL;
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

void reverse(){
    Student *revHead = head;

    if (head != NULL){   
        Student *ptr = head->next;
        Student *temp = ptr;
        
        revHead->next = NULL; // make first node point to null *Similar to stack*

        while(temp != NULL){
            temp = ptr->next;
            ptr->next = revHead;
            revHead = ptr;
            ptr = temp;
        }
        head = revHead;
    }
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