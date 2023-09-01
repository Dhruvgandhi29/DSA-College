#include <iostream>
using namespace std;
int s[10],top=-1;
void push()
{
    //pushes the element
    int d;
    if (top==9)
    cout<<"Stack full!";
    else
    {
        cout<<"\nEnter the value of element to be pushed:";
        cin>>d; 
        top++;
        s[top]=d;
    }
}
void pop()
{
    //pops the element
    int x;
    if(top==-1)
    cout<<"\nStack empty!";
    else
    {
        x=s[top];
        top--;
        cout<<"\nValue popped:"<<x;
    }
}

void display()
{
    //displays all elements
    cout<<"Stack contains:";
    for(int i=top;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }
}

void viewtop()
{
    //shows the top element
    if (top==-1)
    {
        cout<<"Stack Empty!";
    }
    else
    cout<<s[top];
}

int main()
{
    cout<<"\n";
    int choice, flag=0;
    while(1)
    {
        cout<<"\n1.Push\n2.Pop\n3.Display\n4.View top\n5.Exit";
        cout<<"\nEnter choice:";
        cin>>choice;
        switch(choice)
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
            case 4:
            viewtop();
            break;
            default:
            exit(0);
        }    
    }
    cout<<"n";
    return 0;
}