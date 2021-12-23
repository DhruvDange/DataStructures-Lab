#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Each element of the List is a term of the polynomial
typedef struct term
{
    int coeff;
    int expo;
    struct term *next;
} term;

term *head = NULL;

term *createNode(int expo)
{
    term *newNode = (term *)malloc(sizeof(term));
    printf("Enter coeff for %d term:", expo);
    scanf("%d", &newNode->coeff);
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

void create_polynomial(int expo)
{
    for (int i = 0; i <= expo; i++)
    {
        term *ptr = head;
        term *temp = createNode(expo - i);
        if (head == NULL)
            head = temp;
        else
        {
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
}

void display_polynomial()
{
    term *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("(%dx^%d) + ", temp->coeff, temp->expo);
            temp = temp->next;
        }
        else
        {
            printf("(%dx^%d) ", temp->coeff, temp->expo); // printing the last term
                                                          //(the if block above prints the terms with a plus '+' sign)
            temp = temp->next;
        }
    }
}

int evaluate_polynomial(int x)
{
    int res = 0;
    term *temp = head;
    while (temp != NULL)
    {
        res = res + (pow(x, temp->expo) * (temp->coeff));
        temp = temp->next;
    }
    return res;
}

int main()
{

    int x, res;
    int deg;
    printf("\nEnter Degree of Polynomial : ");
    scanf("%d", &deg);

    create_polynomial(deg);

    if (head == NULL)
    {
        exit(0);
    }
    else
    {
        printf("\n--------------------------------");
        printf("\nThe polynomial you created is : ");
        display_polynomial(head);
        printf("\nEnter the value of x :");
        scanf("%d", &x);
        res = evaluate_polynomial(x);
        printf("\nResult : %d", res);
    }
    return 0;
}