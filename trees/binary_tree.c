#include <stdio.h>
#include <stdlib.h>

typedef struct BT{
    struct BT *left;
    int data;
    struct BT *right;
}BT;

int count = 0;

BT *inOrder(BT *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ->", root->data);
    inOrder(root->right);
}

BT *preOrder(BT *root){
    if(root == NULL)
        return;
    printf("%d ->", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

BT *postOrder(BT *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ->", root->data);
}

BT *createNode(int value){
    BT *newNode = (BT *) malloc(sizeof(BT));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    count++;
    return newNode;
}

void display(BT *root, int i){
    int j;
    if(root == NULL)
        return;
    display(root->right, i+1);
    for(j = 1; j <= i; j++)
        printf("\t");
    printf("%d (%d:%d)\n", root->data, i, j);
    display(root->left, i+1);
}

BT *createTree(){

    int chk, value;
    printf("Would you like to add a node: 1->YES 2-> NO \n");
    scanf("%d", &chk);

    if(chk == 2)
        return NULL;
    
    printf("Enter value of node: ");
    scanf("%d", &value);

    BT *ptr = createNode(value);

    printf("Enter left node:\n");
    ptr->left = createTree(ptr->left);

    printf("Enter right node: \n");
    ptr->right = createTree(ptr->right);
    return ptr;
}

void main()
{
    BT *root = NULL;
    int choice;
    while(1)
    {
        printf("\n\nBinary Tree Operations");
        printf("\n1. Create");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Display");
		printf("\n6. Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root = createTree();
            break;
        case 2:
            printf("\nInorder Traversal : \n");
            inOrder(root);
            break;
        case 3:
            printf("\nPreorder Traversal : \n");
            preOrder(root);
            break;
        case 4:
            printf("\nPostorder Traversal : \n");
            postOrder(root);
            break;
        case 5:
			display(root,1); 
            break;
		case 6: 
			exit(0); 
            break;
        default:
            printf("\nInvalid Option");
            break;
        }
    }
}