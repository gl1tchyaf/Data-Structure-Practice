#include<stdio.h>
#include<stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL){
            temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}


void Print() {
	struct Node* temp = head;

	while(temp != NULL) {
		printf(" => %d ",temp->data);
		temp = temp->next;
	}
	printf("\n");

}
void insertAtAnyPos(int num, int pos)
{
    int i;
    struct Node * newnode, *tmp;
    if(head == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        tmp = head;
        i=1;
        while(i<pos-1 && tmp!=NULL)
        {
            tmp = tmp->next;
            i++;
        }
        if(pos == 1)
        {
            InsertAtHead(num);
        }
        else if(tmp == head)
        {
            InsertAtTail(num);
        }
        else if(tmp!=NULL)
        {
            newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->data = num;
            newnode->next = tmp->next;
            newnode->prev = tmp;
            if(tmp->next != NULL)
            {
                tmp->next->prev = newnode;
            }
            tmp->next = newnode;
        }
        else
        {
            printf(" The position is invalid \n");
        }
    }

}

void DeleteFirstNode()
{
    struct node * temp;
    if(head == NULL)
    {
        printf(" The Linked List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

}

void deleteLastNode()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("\n The Linked list is empty\n");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted\n");
    }
    else
    {
        temp = head;
        if(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = NULL;
        free(temp);
        printf("\nNode Deleted\n");
    }

}

void deleteFromAnyPosition(int position)
{
    struct Node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        DeleteFirstNode();
    }
    else if(current == head)
    {
        deleteLastNode();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }

}

int main() {
	head = NULL;

	int n;
    bg:
    printf("Enter your Choice: \n");
    printf("Enter 0 to display the linked list: \n");
    printf("Enter 1 to add an element (At last): \n");
    printf("Enter 2 to add an element at any position: \n");
    printf("Enter 3 to delete from beginning: \n");
    printf("Enter 4 to delete from any position: \n");
    printf("Enter 5 to delete from last: \n");

    scanf("%d",&n);
    if(n==0){
        Print();
        goto bg;
    }
    if(n==1){
            int data;
        printf("Enter data: ");
        scanf("%d",&data);
       InsertAtTail(data);
       goto bg;
    }
    if(n==2){
            int data,pos;
            printf("Enter position: ");
            scanf("%d",&pos);
            printf("Enter data: ");
            scanf("%d",&data);
            insertAtAnyPos(data,pos);
            goto bg;
    }
    if(n==3){
            DeleteFirstNode();
            goto bg;

    }
     if(n==4){
            int pos;
            printf("Enter position: ");
            scanf("%d",&pos);
            deleteFromAnyPosition(pos);
            goto bg;
    }
    if(n==5){
            deleteLastNode();
            goto bg;
    }


}
