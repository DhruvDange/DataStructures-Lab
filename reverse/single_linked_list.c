#include "forehead_func.c"

void main(){
    head = NULL;
    sCount = 0;

    int usnToSearch;
    Student *ptr = NULL;

    int choice;

    do{
        printf("Menu:\n");
        printf("1. Add beginning\n");
        printf("2. Add end:\n");
        printf("3. Add any:\n");
        printf("4. Delete:\n");
        printf("5. Search:\n");
        printf("6. Reverse:\n");
        printf("7. Display:\n");
        printf("8. Exit:\n");
        printf("Enter Choice: ");
        
        scanf("%d", &choice);
        printf("\n \n");

        switch (choice){
            case 1:
                addStart();
                break;
            case 2:
                addEnd();
                break;
            case 3:
                addAny();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Enter usn to search: ");
                scanf("%d", &usnToSearch);
                ptr = searchStudent(usnToSearch);
                if(ptr){
                    printf("Student found!\n");
                    printf("Name: %s\tusn: %d\n", ptr->name, ptr->usn);
                }
                break;
            case 6:
                reverse();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(1);
}
