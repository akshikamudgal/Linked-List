#include <iostream>
using namespace std;

struct node 
{
    int num;                
    node *nextptr;             
}*stnode; //node constructed

void listBanao(int n);                 
void reverse(node **stnode);	            
void listDhikhao();
 

void listBanao(int n) //function to create linked list.
{
    struct node *frntNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL)        
    {
        cout<<" Memory can not be allocated";
    }
    else
    {
                                  
        cout<<"Enter the data for node 1: ";
        cin>>num;
        stnode-> num = num;      
        stnode-> nextptr = NULL; //Links the address field to NULL
        tmp = stnode;
 
        for(i=2; i<=n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node)); 
 

            if(frntNode == NULL) //If frntnode is null no memory cannot be allotted
            {
                cout<<"Memory can not be allocated";
                break;
            }
            else
            {
                cout<<"Enter the data for node "<<i<<": "; // Entering data in nodes.
                cin>>num;
                frntNode->num = num;         
                frntNode->nextptr = NULL;    
                tmp->nextptr = frntNode;     
                tmp = tmp->nextptr;
            }
        }
    }
} 

void reverse(node **stnode) //function to reverse linked list
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*stnode);
    while(current != NULL) {
        temp = current->nextptr;
        current->nextptr = prev;
        prev = current;
        current = temp;
    }
    (*stnode) = prev;
}
void listDhikhao()//function to display linked list
{
    struct node *tmp;
    if(stnode == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            cout<<tmp->num<<"\t";   
            tmp = tmp->nextptr;                 
        }
    }
}
int main()
{
    int n,num,item;
		
    cout<<"Enter the number of nodes: ";
    cin>>n;
    listBanao(n);
    cout<<"\nLinked list data: \n";		
    listDhikhao();
    cout<<"\nAfter reversing\n";
    reverse(&stnode);
    listDhikhao();
   return 0;
}
