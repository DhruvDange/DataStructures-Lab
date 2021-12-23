#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    struct Student *prev;
    int data;
    struct Student *next;
} Student;

Student *createNode(Student *prev, Student *next)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    printf("Enter student data: ");
    scanf("%d", &newStudent->data);
    newStudent->next = next;
    newStudent->prev = prev;
    return newStudent;
}

Student *search(Student *head, int val)
{
    if (head == NULL)
        return NULL;
    else if (head->data == val)
        return head;
    else
        return search(head->next, val);
}

Student *addStart(Student *head, Student **rear)
{
    Student *newNode = createNode(NULL, head);
    if (head == NULL)
    {
        *rear = newNode;
        return newNode;
    }
    else
    {
        head->prev = newNode;
        return newNode;
    }
}

Student *addEnd(Student *rear)
{
    if (rear != NULL)
        rear = rear->next = createNode(rear, NULL);
    return rear;
}

Student *addAny(Student *head, int ins_next_to)
{
    if (head == NULL)
    {
        printf("Node not found\n");
        return NULL;
    }
    else if (head->data == ins_next_to)
    {
        int choice;
        printf("Enter 1 to add before, 2 for after\n");
        scanf("%d", &choice);

        if (choice == 2)
        {
            if (head->next == NULL)
                head->next = createNode(head, head->next);
            else
                head->next = head->next->prev = createNode(head, head->next);
            return head;
        }
        else if (choice == 1)
        {
            if (head->prev == NULL)
                head->prev = createNode(NULL, head);
            else
                head->prev = head->prev->next = createNode(head->prev, head);
            head = head->prev;
            return head;
        }
    }
    else
    {
        head->next = addAny(head->next, ins_next_to);
        return head;
    }
}

Student *delete (Student *head, int val_to_delete)
{
    if (head == NULL)
    {
        printf("Node not found\n");
        return NULL;
    }
    else if (val_to_delete == head->data)
    {
        Student *ptr = head;
        if (head->prev == NULL)
        {
            if (head->next)
                head->next->prev = NULL;
            head = head->next;
            free(ptr);
            return head;
        }
        else if (head->next == NULL)
        {
            head->prev->next = NULL;
            free(head);
            return NULL;
        }
        else
        {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            free(ptr);
            return head;
        }
    }
    else
    {
        head->next = delete (head->next, val_to_delete);
        return head;
    }
}

void display(Student *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        printf("Prev: %d\t data: %d\t Next: %d\n", head->prev, head->data, head->next);
        display(head->next);
    }
}

void main()
{

    Student *head = NULL;
    Student *rear = NULL;

    int usnToSearch;
    Student *ptr = NULL;

    int choice, val;

    do
    {
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

        switch (choice)
        {
        case 1:
            head = addStart(head, &rear);
            break;
        case 2:
            rear = addEnd(rear);
            break;
        case 3:
            printf("Enter value to insert next to: ");
            scanf("%d", &val);
            head = addAny(head, val);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            head = delete (head, val);
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &val);
            ptr = search(head, val);
            if(head == NULL)
                printf("Node not found!\n");
            else
                printf("Node found!\n");
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
        printf("\n");
    } while (1);
}
