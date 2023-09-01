#include <stdio.h>
#include <stdlib.h>
int g[6][6];
int vis[6],d,i,j,f=-1,r=-1,q[6],n;

void initialize()
{
    for(i=0;i<6;i++)
    {
        vis[i]=0;
    }
    f=-1;
    r=-1;
}
void entergraph()
{


    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\nEnter 1 if there is a edge between %d to %d:",i,j);
            scanf("%d",&g[i][j]);
        }
    }
}
void displaymatrix()
{


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}


void add(int x)
{
    if(r==6)
        printf("\nOverflow!");
    else
        {
            if(r==-1)
               f=0;
            q[++r]=x;

    }

}
int delet()
{
    int x;
    if(r==-1)
        return -1;
    else{
        if(f==r)
        {
         x=q[f];
         f=r=-1;
        }
        else{
            x=q[f];
            f=f+1;
        }
        return x;
    }
}

void bfs(int s)
{
 add(s);
 vis[s]=1;
 d=delet();
 if(d!=-1)
    printf("%d  ",d);
 while(d!=-1)
 {
     for(i=1;i<=n;i++)
     {
         if(g[d][i]==1&&vis[i]==0)
         {
             add(i);
             vis[i]=1;
         }
     }
     d=delet();
     if(d!=-1)
        printf("%d ",d);
 }

}
int main()
{
    int s,ch;
    entergraph();
    displaymatrix();
    do
    {
    initialize();
    printf("\nEnter the source vertex:");
    scanf("%d",&s);
    printf("\nTraversal:\n");
    bfs(s);
    printf("\nDo you want to check with different source press 1 for yes or 0 for No:")  ;
    scanf("%d",&ch);
    }while(ch!=0);

    return 0;
}
