//write a menu driven program to insert a node in a single linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
 int   insert_beg(struct node *start,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    start=temp;
    printf("Node inserted at the beginning is %d",temp->info);
    return 0;
}

void main()
{
    struct node *start=NULL;
    int i=0,n,choice,el;
    printf("Enter the data to be entered");
    scanf("%d",el);
    printf("How many times will the code run?");
    scanf("%d",&n);
    do
    {
        printf("\nMENU\n");
        printf("1. Insertion\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("%d\n",el);
            insert_beg(start,el);
            break;
            case 2:
            exit(0);
            break;
            default:
            printf("Sorry\n");


        }
    }while(i<=n);
}


