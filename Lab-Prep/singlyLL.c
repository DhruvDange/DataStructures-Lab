#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int data;
    struct Student *next;
}student;

student *head = NULL;

student *createNode(int data, student *next){
    student *newNode = (student *) malloc(sizeof(student));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

student *searchNode(int data){
    student *ptr = head;
    do{
        if(ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }while(ptr != NULL);
    return NULL;
}

void addStart(int data){
    head = createNode(data, head);
}

void addEnd(int data){
    student *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr ->next;
    }
    ptr->next = createNode(data, NULL);
}

void addAny(int data){
    if(head == NULL){
        addStart(data);
        return;
    }else{
        int rno;
        printf("Enter roll no to insert necf to");
        scanf("%d", &rno);

        student *search = searchNode(rno);

        if(search){
            int chk;
            student *ptr = head;

            printf("1-B 2-A\n");
            scanf("%d", &chk);

            if(chk == 1){
                if(search == head){
                    addStart(data);
                }else{
                    while(ptr->next != search)
                        ptr = ptr->next;
                    ptr->next = createNode(data, ptr->next);
                }
            }else if(chk == 2){
                if(search ->next == NULL){
                    addEnd(data);
                }else{
                    search->next = createNode(data, search->next);
                }
            }
        }
    }
}

void delete(int data){

    if(head == NULL){
        printf("Empty\n");
        return;
    }else{
        student* search = searchNode(data);
        if(search == head){
            head = head->next;
            free(search);
        }else{
            student *ptr = head;
            while(ptr->next != search)
                ptr = ptr->next;
            ptr->next = search->next;
            free(search);
        }
    }
}
void reverse(){

    if(head == NULL || head->next == NULL){
        return;
    }

    student *revHead = head;
    student *ptr = head->next;
    student *temp = ptr;

    revHead->next = NULL;

    while(temp != NULL){
        temp = temp->next;
        ptr->next = revHead;
        revHead = ptr;
        ptr = temp;
    }
    head = revHead;
    
}

void display(){
    student *ptr = head;

    if(ptr == NULL){
        printf("No students in the list!\n");
        return;
    }

    while(ptr != NULL){
        printf("data: %d\t next: %d\n", ptr->data, ptr->next);
        ptr = ptr -> next;
    }
    printf("\n");
}

void main(){

    int usnToSearch;
    student *ptr = NULL;

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
                printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                addStart(usnToSearch);
                break;
            case 2:
            printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                addEnd(usnToSearch);
                break;
            case 3:
            printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                addAny(usnToSearch);
                break;
            case 4:
            printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                delete(usnToSearch);
                break;
            case 5:
                printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                ptr = searchNode(usnToSearch);
                if(ptr){
                    printf("Student found!\n");
                }
                break;
            case 6:
                display();
                break;
            case 7:
                reverse();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(1);
}