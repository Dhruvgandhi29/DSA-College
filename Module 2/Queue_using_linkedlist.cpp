#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}//creating nodes
*rear=NULL;
struct node *front=NULL;
//we declare front and rear variables
void insert()
{   
    int x;
    cout<<"\nEnter value to be inserted:";
    cin>>x;
    node *newnode= new node;//new node is created
    newnode->data=x;// x is the data for the new node
    if (front==NULL && rear==NULL)
    {
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
    }//if the the queue is empty front and rear will point in same direction
    else
    {
        newnode->next=NULL;
        rear->next=newnode;
        rear=newnode;
    }//else only rear points towards the end
}
void Delete()
{
    int x;
    struct node *temp;
    if (front==NULL)
    {
        cout<<"\nQueue Empty!";
    }
    else
    {
        temp=front;
        x=front->data;
        front=temp->next;
        delete temp;
        cout<<"\nDeleted element is:"<<x;
    }
}
//front nodes shifts to the next node and the element is deleted
void display()
{
    int x;
    struct node *temp=front;
    while(temp!=NULL)
    {
        x=temp->data;
        cout<<x<<" ";
        temp=temp->next;
    }
}
//a temp node is made to traverse from front till the end while printing data
int main()
{
    cout<<"\n21BCE4008\nDhruv Gandhi";
    int n;
    while(1)
    {
        cout<<"\n1.Insertion \n2.Deletion \n3.Display queue\n4.Exit";
        cout<<"\nEnter choice:";
        cin>>n;
        switch(n)
        {
            case 1:
            insert();
            break;
            case 2:
            Delete();
            break;
            case 3:
            display();
            break;
            default:
            exit(0);
        }
    }
}