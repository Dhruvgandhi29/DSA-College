#include <iostream>
using namespace std;
int flag,u;
struct node
{
    int data;
    struct node*left;
    struct node*right;
}*s=NULL;

struct node* insert(struct node*t,int x)
{
    if (t==NULL)
    {
        t=new node;
        t->data=x;
        t->left=NULL;
        t->right=NULL;
    }
    else if(x<t->data)
    {
        t->left=insert(t->left,x);
    }
    else
    {
        t->right=insert(t->right,x);
    }
    return t;
}

struct node* find_min(struct node*t)
{
    if(t->left==NULL)
    {
        u=t->data;
    }
    else 
    find_min(t->left);
    return t;
}
struct node* find_max(struct node*t)
{
    if(t->right==NULL)
    {
        u=t->data;
    }
    else find_max(t->right);
    return t;
}
struct node* find(struct node *t,int x)
{
    int count=0;
    flag=0;
    struct node *temp;
    temp=t;
    while(temp!=NULL)
    {
        if (temp->data==x)
        {
            flag=1;
            cout<<"\nElement found:";
            return temp;

        }
        else if(x<temp->data)
        {
            temp=temp->left;
            cout<<"Left ";
        }
        else
        {
            temp=temp->right;
            cout<<"Right  ";
        }
    }   
    if (flag==0)
    {
        cout<<"\nElement not found!";
    }
    return t;
}

void inorder(struct node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}
void preorder(struct node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(struct node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }
}

struct node* Delete(struct node *t,int x)
{
    struct node *temp;
    if (t==NULL)
    {
        return NULL;
    }
    else if(x<t->data)
    {
        t->left=Delete(t->left,x);
    }
    else if(x>t->data)
    {
        t->right=Delete(t->right,x);
    }
    else if(t->left==NULL) 
    {
        t=t->right;
    }
    else if(t->right==NULL) 
    {
        t=t->left;
    }
    else
    {
        temp=find_min(t->right);//or find_max(t->left)
        t->data=temp->data;
        t->right=Delete(t->right,t->data);
    }
    return t;
}
int main()
{
    int choice;
    cout<<"\n21BCE4008\nDhruv Gandhi";
    int a[]={50,16,3,22,0,63,5,4,10,500,600};
    int b;
    for (int i=0;i<11;i++)
    {
        b=a[i];
        s=insert(s,b);
    }
    while(1)
    {
        cout<<"\n1.Insert\n2.Find\n3.Display\n4.Delete\n5.Exit";
        cout<<"\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            int x;
            cout<<"Enter element to be inserted:";
            cin>>x;
            s=insert(s,x);
            break;
            case 2:
            int c;
            cout<<"\n1.Find min\n2.Find max\n3.Search\n4.Break";
            cout<<"\nEnter choice:";
            cin>>c;
            switch(c)
            {
                case 1:
                find_min(s);
                cout<<"\nThe smallest node is:"<<u;
                break;
                case 2:
                find_max(s);
                cout<<"\nThe largest node is:"<<u;
                break;
                case 3:
                int x;
                cout<<"\nEnter element to be searched:";
                cin>>x;
                find(s,x);
                break;
                default:
                break;
            }
            break;
            case 3:
            cout<<"\n1.Inorder\n2.Preorder\n3.Postorder\n4.Break";
            cout<<"\nEnter choice:";
            cin>>c;
            switch(c)
            {
                case 1:
                cout<<"The elements displayed in inorder format are:\n";
                inorder(s);
                break;
                case 2:
                cout<<"The elements displayed in preorder format are:\n";
                preorder(s);
                break;
                case 3:
                cout<<"The elements displayed in preorder format are:\n";
                postorder(s);
                break;
                default:
                break;
            }
            break;
            case 4:
            int f;
            cout<<"Enter element to be deleted:";
            cin>>f;
            s=Delete(s,f);
            break;
            default:
            exit(0);
        }    
    }
    return 0;
}