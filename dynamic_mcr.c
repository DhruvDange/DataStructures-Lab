#include <stdio.h>
#include <stdlib.h>

struct student{
    // char name[20];
    int age;
};

void main(){
    struct student *d_malloc, *d_calloc;
    int size;

    printf("Size of structure is: %d\n", sizeof(struct student));

    printf("Enter size / no of elements: ");
    scanf("%d", &size);

    d_malloc = (struct student *) malloc(size * sizeof(struct student));
    d_calloc = (struct student *) calloc(size, sizeof(struct student));

    printf("The memory addresses alloted by malloc:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", d_malloc + i);
    }

    printf("The memory addresses alloted by calloc:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", d_calloc + i);
    }

    printf("\nEnter the new size: ");
    scanf("%d", &size);

    d_calloc = realloc(d_calloc, size * sizeof(struct student));
    printf("The memory addresses reallocated by realloc:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", d_calloc + i);
    }

}