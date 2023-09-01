#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}
*top=NULL;//pointer points null
void push()
{
    int x;
    cout<<"\nEnter value to be inserted:";
    cin>>x;
    node *newnode= new node;
    newnode->data=x;
    if (top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    int x;
    struct node *temp;
    if (top==NULL)
    {
        cout<<"\nstack is empty!";
    }
    else
    {
        temp=top;
        x=temp->data;
        top=temp->next;
        delete temp;
    }
    cout<<"\nDeleted element "<<x;
}

void display()
{ 
    int x;
    struct node *temp;
    if (top==NULL)
    {
        cout<<"\nstack is empty!";
    }
    else
    {
        cout<<"\n";
        while(top!=NULL)
        {
            temp=top;
            x=temp->data;
            cout<<x<<" ";
            top=temp->next;
            delete temp;
        }
    }

}

int main()
{
    cout<<"\n21BCE4008\nDhruv Gandhi";
    int n;
    while(1)
    {
        cout<<"\n1.Insertion \n2.Deletion \n3.Display stack\n4.Exit";
        cout<<"\nEnter choice:";
        cin>>n;
        switch(n)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            default:
            exit(0);
        }
    }
    return 0;
}
