#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};


struct node *head = NULL;
struct node *tail = NULL;


void addVoteCount(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void minimumVoteCount()
{
    struct node *current = head;
    int min = head->data;
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        do
        {
            if(min > current->data)
            {
                min = current->data;
            }
            current= current->next;
        }
        while(current != head);

        printf("Minimum vote count: %d", min);
    }
}

void maximumVoteCount()
{
    struct node *current = head;
    int max = head->data;
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        do
        {
            if(max < current->data)
            {
                max = current->data;
            }
            current= current->next;
        }
        while(current != head);

        printf("\nMaximum vote count: %d", max);
    }
}



int main()
{
    int i,input,j[50];
    printf("How many state you want?");
    scanf("%d",&input);
    for(i=0;i<input;i++){
            printf("Enter vote count: ");
            scanf("%d",&j[i]);
            addVoteCount(j[i]);
    }
    printf("Videns vote count in different States: ");
    for(i=0;i<input;i++){
        printf("%d, ",j[i]);
    }
    printf(" \n");
    minimumVoteCount();
    maximumVoteCount();

    return 0;
}
