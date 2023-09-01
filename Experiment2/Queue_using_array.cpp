#include <iostream>
using namespace std;
int queue[100],n=100,front=-1,rear=-1;
void insert()
{
    int item;
    if (rear==n-1)
    {
        cout<<"Queue overflow!";
    }
    else
    {
        front=0;
        cout<<"Enter the element:";
        cin>>item;
        rear++;
        queue[rear]=item;
    }
}
void Delete()
{
    if (front==-1||front>rear)
    {
        cout<<"Queue underflow!";
    }
    else
    {
        cout<<"Element deleted from queue is:"<<queue[front];
        front++;
    }
}
void display()
{
    if (front==-1)
    {
        cout<<"Queue is empty!";
    }
    else
    {
        cout<<"Queue elements are:";
        for(int i=front;i<=rear;i++)
        {
            cout<<" "<<queue[i];
        }
    }
}
int main ()
{
    int choice;
    cout<<"\n21BCE4008\nDhruv Gandhi";
    while (1)
    {
        cout<<"\n1.Insert an elemnt\n2.Delete element\n3.Display elements\n4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: insert();
            break;
            case 2: Delete();
            break;
            case 3: display();
            break;
            default: exit(0);
        }
    }
    return 0;
}