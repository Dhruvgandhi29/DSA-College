#include <iostream>
using namespace std;
// binary search
int main()
{
    int n,f,mid,l,x;
    int flag=0;
    int a[20];
    cout<<"\nEnter the number of items in array in ascending order:";
    cin>>n;
    cout<<"\nEnter the items in array:";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\nEnter element to be searched:";
    cin>>x;
    f=0;
    l=n-1;
    mid=(f+l)/2;
    while(f<=l)
    {
        if (a[mid]=x)   
        {
            cout<<"\nElement found!";
            flag++;
            break;
        }
        else if (x>a[mid])
        {
            f=mid+1;
        } 
        else
        {
            l=mid-1;
        }
        mid=(f+l)/2;
    }
    
    if(flag==0)
    {
        cout<<"\nElement not found!";
    }
    return 0;
}