#include <iostream>
using namespace std;
int n,top=-1;
int stack[10],vis[10];
int g[10][10];

void readmatrix()
{   //creating a 2d array
    int i,j;
    cout<<"Enter number of vertices:";
    cin>>n;
    for(i=0;i<n;i++)//we startnode naming from 0
    {
        for(j=0;j<n;j++)
        {
            cout<<"Enter 1 if there is edge between "<<i<<" "<<j<<":";
            cin>>g[i][j];
        }
    }
}
void printmatrix()
{
    int i,j;
    cout<<"\nThe adjacency matrix is:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void intialise()
{
    int i;
    for(i=0;i<=n;i++)
    {
        vis[i]=0;
    }
}
void push(int x)
{
    if (top==n-1)
    {
        cout<<"\noverflow";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
int pop()
{
    if (top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

void dfs(int s)
{
    int x,i;
    push(s);
    vis[s]=1;
    x=pop();
    if(x!=-1)
    {
        cout<<x;
    }
    while(x!=-1)
    {
        for(i=0;i<=n-1;i++)
        {
            if(g[x][i]==1 && vis[i]==0)
            {
                push(i);
                vis[i]=1;
            }
        }
        x=pop();
        if(x!=-1)
        {
            cout<<x;
        }
    }
}
int main()
{
    int s;
    readmatrix();
    printmatrix();
    while(1)
    {
        intialise();
        cout<<"\n Enter source:";
        cin>>s;
        cout<<"\nDFS:";
        dfs(s);
    }
    return 0;
}