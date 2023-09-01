#include <iostream>
using namespace std;

void insert(int a[],int n)
{
    int temp,j;
    for(int i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i;j>0 && a[j-1]>temp;j--)
        {
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
}
/*Elements are taken one by one and sorted such that all 
left side elements are smaller*/
int main()
{
    int n,x;
    int a[100];
    cout<<"\n21BCE4008\nDhruv Gandhi";
    cout<<"\nEnter the no. elements:";
    cin>>n;
    cout<<"\nEnter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i]=x;
    }
    insert(a,n);
    cout<<"\nThe sorted array is:";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
    return 0;
}