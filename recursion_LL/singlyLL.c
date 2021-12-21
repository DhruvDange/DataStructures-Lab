#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Student{
    int data;
    struct Student *next;
}Student;


Student * createStudentNode(Student * ptr){
    Student * newStudent = (Student *) malloc(sizeof(Student));
    printf("Enter details for Student to be added: \n");
    printf("Enter data:");
    scanf("%d", &newStudent->data);
    newStudent->next = ptr;
    return newStudent;
}

Student *addStart(Student *ptr){
    return createStudentNode(ptr);
}

Student *addEnd(Student *ptr){
    if(ptr == NULL){
        return createStudentNode(NULL);
    }else{
        ptr->next = addEnd(ptr->next);
        return ptr;
    }
}

Student *addAhead(Student *ptr, int ins_adj){
    if(ptr == NULL){
        return ptr;
    }else if(ptr->data == ins_adj){
        ptr->next = createStudentNode(ptr->next);
        return ptr;
    }else{
        ptr->next = addAhead(ptr->next, ins_adj);
        return ptr;
    }
}

Student *delete(Student *ptr, int del_data){
    if(ptr == NULL){
        return ptr;
    }else if(ptr->data == del_data){
        return ptr->next;
    }
    else{
        ptr->next = delete(ptr->next, del_data);
        return ptr;
    }
}

void display(Student *ptr){
    if(ptr == NULL)
        return;
    else{
        printf("Data: %d\t Next: %d\n", ptr->data, ptr->next);
        display(ptr->next);
    }
}

Student *search(Student *ptr, int data_to_search){
    if(ptr == NULL){
        return NULL;
    }else{
        if(ptr->data == data_to_search){
            return ptr;
        }else{
            return search(ptr->next, data_to_search);
        }
    }
}

void main(){
    Student *head = NULL, *sptr = NULL;

    int choice, data;

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
                head = addStart(head);
                break;
            case 2:
                head = addEnd(head);
                break;
            case 3:
                printf("Enter data to insert next to: ");
                scanf("%d", &data);
                head = addAhead(head, data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                sptr = search(head, data);
                if(sptr == NULL)
                    printf("Record not found!\n");
                else
                    printf("Record Found!\n");
                break;
            case 6:
                display(head);
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