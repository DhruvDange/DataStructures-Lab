#include <stdio.h>

typedef struct Btree{
    struct Btree *left;
    struct Btree *right;
    int data;
}Btree;

void display(Btree *root, int i){
    int j;
    if(root == NULL)
        return;
    display(root->right, i+1);
    for(j = 1; j <= i; j++){
        printf("\t");
    }
    printf("%d (%d:%d)\n", root->data, i, j);
    display(root->left, i+1);
}

Btree *createNode(int data){
    Btree *newNode = (Btree *) malloc(sizeof(Btree));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Btree *addLeaf(Btree *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(root->data > data)
        root->left = addLeaf(root->left, data);
    if(root->data < data)
        root->right = addLeaf(root->right, data);
    return root;
}

void main()
{
    Btree *root = NULL;
    int choice, value;
    while(1)
    {
        printf("\n\nBinary Tree Operations");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter value of node: ");
            scanf("%d", &value);
            root = addLeaf(root, value);
            break;
        case 2:
			display(root,1); 
            break;
        default:
            printf("\nInvalid Option");
            break;
        }
    }
}