//creating a singly linked list

#include <stdio.h>
#include <stdlib.h>

//structure definition

typedef struct Node
{
    int data;
    struct Node* link;
}Node;

//function prototypes

Node* createNode(int data);
void appendNode(Node** head_ref,int data);
void displayList(Node* head_ref);

// main function

int main()
{
    struct Node* head = NULL;
    int n,value;
    printf("How many nodes ?->");
    scanf("%d",&n);

    int i;
    for(i = 0; i< n;++i)
    {
        printf("Enter data at position %d->",i);
        scanf("%d",&value);
        appendNode(&head,value);
    }
    printf("The Linked List is ->\n");
    displayList(head);
    return 0;

}

//Function to create a node

Node* createNode(int data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    new->data = data;
    new->link = NULL;
    return new;
}


//Function to append a node at end of list

void appendNode(Node** head_ref, int data)
{
    Node* new = createNode(data);

    if(*head_ref == NULL)
    {
        *head_ref = new;
    }
    else
    {
        Node* temp = *head_ref;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}


//Function to display the list 
void displayList(Node* head_ref)
{
    Node* temp = head_ref;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}