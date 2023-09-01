#include <iostream>
using namespace std;
int n;
int f=-1,r=-1;
int g[10][10];
int q[10],vis[10];
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
    for(int i=0;i<=n;i++)
    {
        vis[i]=0;
    }
    f=-1;
    r=-1;
}
void add(int x)
{
    if(r==n-1)
    {
        cout<<"\nOverflow!";
    }
    else
        {
            if(r==-1)
            {
               f=0;
            }
            r++;
            q[r]=x;
        }

}
int del()
{
    int x;
    if(r==-1)
    {
        return -1;
    }
    else
    {
        if(f==r)
        {
         x=q[f];
         f=r=-1;
        }
        else
        {
            x=q[f];
            f=f+1;
        }
        return x;
    }
}
void bfs(int s)
{
    int d;
    add(s);
    vis[s]=1;
    d=del();
    if(d!=-1)
    {
        cout<<d;
    }
    while(d!=-1)
    {
        for(int i=0;i<n;i++)
        {
            if(g[d][i]==1&&vis[i]==0)
            {
                add(i);
                vis[i]=1;
            }
        }
        d=del();
        if(d!=-1)
            cout<<d;
    }

}
int main()
{
    int s,ch;
    readmatrix();
    printmatrix();
    while(ch!=0)
    {
        intialise();
        cout<<"\n Enter source:";
        cin>>s;
        cout<<"\nTraversal:";
        bfs(s);
        cout<<"\nExit program=0:";
        cin>>ch;
    }
    return 0;
}