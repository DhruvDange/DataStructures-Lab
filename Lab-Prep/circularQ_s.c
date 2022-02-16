#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    struct student *next;
    int data;
}student;

student *head = NULL;

student *createNode(int data, student* next){
    student *newNode = (student *) malloc(sizeof(student));
    newNode->next = next;
    newNode->data = data;
    return newNode;
}

student* searchNode(int data){
    student *ptr = head;
    do{
        if(ptr->data == data)
            return ptr;
        ptr = ptr->next;
    }while(ptr != head);

    return NULL;
}

void addAny(int data){
    if(head == NULL){
        head = createNode(data, head); // here head is null
        head->next = head; // upadte next to point to head
    }else{
        int pos, rno;
        student *ptr = head;
        printf("Enter roll no to insert next to: ");
        scanf("%d", &rno);

        student* search = searchNode(rno);
        
        if(search)
        {
            printf("Enter 1 to insert before, 2 for afetr\n");
            scanf("%d", &pos);

            if(pos == 1)
            {
                while(ptr->next != search)
                    ptr = ptr->next; // go to search
                ptr->next = createNode(data, search);

                if(search == head) // add bewfore 1st node
                {
                    head = ptr->next;
                }
            }
            else if (pos == 2)
            {
                search->next = createNode(data, search->next); // I hope this works casue its one line
            }
        }
        else{
            printf("Node with roll no: %d not found\n", rno);
        }
    }
}

void delete(int data){

    if(head == NULL){
        printf("LL is MT\n");
        return;
    }

    student *search = searchNode(data);
    student *ptr = head;

    if(!search){
        printf("Node not found!\n");
        return;
    }
 
    while(ptr->next != search) // works even ifsearch == head
        ptr = ptr->next;
    ptr->next = search->next;

    if(search == head){
        head = head->next;
    }

    if(search->next == search){
        head = NULL;
    }
    free(search);

}

void display(){
    if(head == NULL){
        printf("Q is MT");
        return;
    }
    student *ptr = head;
    do{
        printf("Curr:%x\t Data: %d\t Next: %x\n", ptr, ptr->data, ptr->next);
        ptr = ptr->next;
    }while(ptr != head);
}

void main(){

    int ch, element;
    while (1)
    {
        printf("\nEnter choice-  \n");
        printf("1: AddAny\n2: DeleteAny\n3: Display\n4: Exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be added: ");
            scanf("%d", &element);
            addAny(element);
            break;
        case 2:
            printf("\nEnter the element to be deleted: ");
            scanf("%d", &element);
            delete(element);
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