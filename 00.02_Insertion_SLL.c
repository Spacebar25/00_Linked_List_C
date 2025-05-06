// creating a singly linked list and inserting nodes at beginning, end and specific index (0 indexing)

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

void insertAtBeginning(Node** head_ref,int data);
void insertAtIndex(Node** head_ref,int data,int index);

int isEmpty(Node* head_ref);
int lenList(Node* head_ref);

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

    //testing the functions
    // insertAtBeginning(&head,100);

    insertAtIndex(&head,200,0);

    printf("\n");
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

int isEmpty(Node* head_ref)
{
    return head_ref == NULL;
}

int lenList(Node* head_ref)
{
    if(isEmpty(head_ref))
    {
        return 0;
    }
    int len = 0;
    Node* temp = head_ref;
    while(temp!=NULL)
    {
        ++len;
        temp = temp->link;
    }
    return len;
}

void insertAtBeginning(Node** head_ref,int data)
{
    //check if list is empty or not
    if(isEmpty(*head_ref))
    {
        return;
    }


    Node* new = createNode(data);
    new->link = *head_ref;
    *head_ref = new;
}


void insertAtIndex(Node** head_ref,int data,int index)
{
    //check if list is empty or not
    if(isEmpty(*head_ref))
    {
        return;
    }

    //Check boundary conditions 
    if(index < 0 || index > lenList(*head_ref)) //we need lenList function
    {
        printf("Invalid Index!");
        return;
    }

    //check if index is 0
    if(index == 0)
    {
        insertAtBeginning(head_ref,data);
    }

    else
    {
        Node* new = createNode(data);
        Node* temp = *head_ref;
        int i ;
        for(i = 1;i<=index-1;++i) // traverse temp to position of index - 1
        {
            temp = temp->link;
        }

        new ->link = temp-> link;
        temp->link = new;
    }
}