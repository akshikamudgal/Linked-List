#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
int count=0;
void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i,count;
    count=0;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\n cannot allocate memory");
        exit(0);
    }
    printf("\n enter data of node 1: ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    
    temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        
        if(newnode==NULL)
        {
            printf("\n unable to create memory ");
            break;
        }
        printf("\n enter data of node %d: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        
        temp->next=newnode;
        temp=newnode;
    }
    
    
}
void insertatbeginning()
{
    printf("\n inserting at beginning: ");
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insertatend()
{   
    
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n add node at end:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    //traversing the list to reach end of list
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    
}
void insertatlocation()
{
    int pos,i;
    i=1;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n adding node at specific location: ");
    printf("\n enter position: ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("\n cannot insert as invalid position");
        exit(0);
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
    }
    printf("\n enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
    
}
void traverselist()
{   
    struct node *temp;
    if(head==NULL)
    {
        printf("\n list is empty");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("\n data= %d",temp->data);
        temp=temp->next;
        count++;
        
    }
    printf("\n count is: %d ",count);
}
void printlist()
{
    struct node *temp;
    temp=head;
    printf("\n the list is: ");
    while(temp!=NULL)
    {
        
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createlist(n);
    insertatbeginning();
    insertatend();
    

    printf("\nData in the list \n");
    traverselist();
    insertatlocation();
    printlist();
    

    return 0;
}
