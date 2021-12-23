#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    struct Student *prev;
    int data;
    struct Student *next;
} Student;

Student *rear;

Student *createNode(Student *prev, Student *next)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    printf("Enter student data: ");
    scanf("%d", &newStudent->data);
    newStudent->next = next;
    newStudent->prev = prev;
    return newStudent;
}

Student *addStart(Student *head)
{
    Student *newNode = createNode(NULL, head);
    if (head == NULL){
        rear = newNode;
        return newNode;
    }
    else{
        head->prev = newNode;
        return newNode;
    };
}

Student *addEnd(Student *head)
{
    if (rear != NULL)
        rear = rear->next = createNode(rear, NULL);
    return head;
}

void display(Student *head)
{

    Student *ptr = head;

    if (ptr == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("Prev: %d\t data: %d\t Next: %d\n", ptr->prev, ptr->data, ptr->next);
            ptr = ptr->next;
        }
    }
}

void main()
{
    Student *head = NULL;

    head = addStart(head);
    head = addStart(head);
    head = addStart(head);
    head = addEnd(head);
    head = addEnd(head);
    display(head);
}