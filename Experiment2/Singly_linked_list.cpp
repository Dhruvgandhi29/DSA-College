#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
}
*head=NULL;   //will have to give *head
int pos,val;

void insertfirst()
{
    cout<<"\nEnter value to be inserted:";
    cin>>val;
    node *newnode= new node;// alternative for below syntax
    //struct node *newnode= (struct node*) malloc(sizeof(struct node*));
    if (head==NULL)
    {
        cout<<"\nList is empty";
        newnode->value=val;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->value=val;
        newnode->next=head;
        head=newnode;
        cout<<"\nNode inserted at 1st position.";
    }

}

void insertlast()
{
    cout<<"\nEnter value to be inserted:";
    cin>>val;
    node *newnode= new node;
    if (head==NULL)
    {
        cout<<"\nList is  empty";
        newnode->value=val;
        newnode->next=NULL;
        head=newnode;
        cout<<"\nElement inserted!";
    }
    else
    {
        struct node *temp=head; 
        while (temp->next!=0)
        {
            temp=temp->next;
        }
        newnode->value=val;
        newnode->next=NULL;
        temp->next=newnode;
        cout<<"\nElement inserted at last";
    }
}

void insertatpos()
{
    //position starts from 1
    cout<<"\nEnter position at which to be inserted:";
    cin>>pos;
    cout<<"\nEnter value to be inserted:";
    cin>>val;
    node *newnode= new node;
    struct node *temp1=head;
    if( pos==1)
    {
        newnode->value=val;
        newnode->next=head;
        head=newnode;
    }
    else if(head==NULL) 
    {
        cout<<"\nInvalid position entered";
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            temp1=temp1->next;
        }
        if (temp1->next==NULL)
        {
            newnode->value=val;
            newnode->next=NULL;
            temp1->next=newnode;
        }
        else
        {
            newnode->value=val;
            newnode->next=temp1->next;
            temp1->next=newnode;
        }
        cout<<"\nElement inserted at position "<<pos;
    }

}

void deletefirst()
{
    struct node *temp=head;
    if (head==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    else
    {
        head=temp->next;
        delete temp;
        cout<<"\nFirst element is deleted";
    }

}

void deletelast()
{
    struct node *temp1=head;
    struct node *temp2;
    if (head==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    else if(temp1->next==NULL)
    {
        head=temp1->next;
        delete temp1;
        cout<<"\nThe Last element is deleted from the linked list!";
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        delete temp1;
        cout<<"\nThe Last element is deleted from the linked list!";
    }

}

void deleteatpos()
{
    struct node *temp1=head;
    struct node *temp2;
    cout<<"\nEnter position at which to deleted:";
    cin>>pos;
    if (head==NULL)
    {
        cout<<"\nList is empty!";
    }
    if( pos==1)
    {
        head=temp1->next;
        delete temp1;
        cout<<"Element deleted at 1st pos";
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        cout<<"\nElement deleted at position "<<pos;
    }

}

void display()
{
    int counter=0;
    struct node *temp1=head;
    cout<<"\nThe elements of the list are:\n";
    if (head==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    else 
    {
        while(temp1!=0)
        {
            cout<<" "<<temp1->value;
            temp1=temp1->next;
            counter++;
        }
        cout<<"\nList has "<<counter<<" elements";
    }
}

void search()
{
    int x,flag=0;
    pos=1;
    struct node *temp=head;
    cout<<"\nEnter element to be searched:";
    cin>>x;
    if (head==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->value==x)
            {
                cout<<"\nValue found at position "<<pos;
                flag=0;
            }
            else
            {
                flag=1;
            }
            
            temp=temp->next;
            pos++;
        }
        if (flag==1)
        {
            cout<<"\nValue not found!";
        }
    }    
}

int main()
{
    cout<<"\n21BCE4008\nDhruv Gandhi";
    int flag=1,choice,choice2;
    while(flag!=0)
    {
        
        cout<<"\n";
        cout<<"\n1.Insertion \n2.Deletion \n3.Display list \n4.Search \n5.Exit";
        cout<<"\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\n1.Insert first\n2.Insert last\n3.Insert at  position ";
                cout<<"\nEnter choice:";
                cin>>choice2;
                switch(choice2)
                {
                    case 1: 
                    insertfirst();
                    break;
                    case 2: 
                    insertlast();
                    break;
                    case 3:
                    insertatpos();
                    break;
                    default:
                    cout<<"\nInvalid input!";
                    break;
                }
                display();
                break;
            }
            case 2:
            {
                cout<<"\n1.Delete first\n2.Delete last\n3.Delete at  position ";
                cout<<"\nEnter choice:";
                cin>>choice2;
                switch(choice2)
                {
                    case 1: 
                    deletefirst();
                    break;
                    case 2: 
                    deletelast();
                    break;
                    case 3:
                    deleteatpos();
                    break;
                    default:
                    cout<<"\nInvalid input!";
                    break;
                }
                display();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                search();
                display();
                break;
                cout<<"/////";
            }
            
            default:
            flag--;
            break;
        }   
    }
}