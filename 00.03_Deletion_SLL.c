// Deletion of node from beginning, end and specific index (0 indexing) in a singly Linked List

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

void delBeg(Node** head_ref);
void delEnd(Node** head_ref);
void delAtIndex(Node** head_ref, int index);
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

    //testing functions
    // delBeg(&head);
    // delEnd(&head);

    // delAtIndex(&head,2);
    delAtIndex(&head,2);

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

//Function to check list is empty or not

int isEmpty(Node* head_ref)
{
    return(head_ref == NULL);
}

//Function to calculate length of the list

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

//Function to delete node from beginning

void delBeg(Node** head_ref)
{
    //check if list is empty
    if(isEmpty(*head_ref))
    {
        return;
    }

    Node* temp = *head_ref;
    *head_ref = temp->link;
    free(temp); //free memory pointed by temp
    //printf("Node deleted from beginng"); //optional confirmation 
}

//Function to delete node from end 

void delEnd(Node** head_ref)
{
    //check if linked list is empty
    if(isEmpty(*head_ref))
    {
        return;
    }
    //check if only one node is present
    if((*head_ref)->link == NULL)
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    Node* temp = *head_ref;
    //traverse temp to second last position
    while(temp->link->link != NULL)
    {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
    // printf("Node deleted from end"); //optional confirmation
}

//Function to delete node from specific index

void delAtIndex(Node** head_ref,int index)
{
    //check if list is empty
    if(isEmpty(*head_ref))
    {
        return;
    }

    //Check Boundary conditions
    if(index < 0 || index >= lenList(*head_ref)) //we need lenList function
    {
        printf("Invalid Index given!");
        return;
    }

    //check if position given is 0
    if(index == 0)
    {
        delBeg(head_ref);
        return;
    }

    //Here we need two pointers temp and prev. traverse temp to the index given and prev before that

    Node* temp = *head_ref;
    Node* prev = NULL;

    int i;
    for(i = 1;i<=index;++i)
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = temp->link;
    free(temp); //free memory pointed by temp
}