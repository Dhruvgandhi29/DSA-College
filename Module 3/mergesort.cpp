#include <iostream>
using namespace std;

void Merge(int a[],int l,int mid, int h)
{
    int b[100];//new array made by merging two arrays
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    /*a single array a is considered as 2 sepearate arrays
    from l to mid and mid+1 to h*/
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    /*array elements of 2 arrays are compared to each other and 
    then appended to the new array*/
    }
    for(;i<=mid;i++)
    {
        b[k]=a[i];
        k++;
    }
    for(;j<=h;j++)
    {
        b[k]=a[j];
        k++;
    }
    for(int p=l;p<=h;p++)
    {
        a[p]=b[p];
    }
    // the new sorted array b is copied to a    
}

void mergesort(int a[],int l,int h)
{
    //mid,l and h hold dynamic values
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}
/*recursive function that splits array in individual elements and 
then merges them in sorted fashion */
int main()
{
    int n,l=0,h;
    int a[100];
    cout<<"\n21BCE4008\nDhruv Gandhi";
    cout<<"\nEnter number of array elements:";
    cin>>n;
    h=n-1;
    cout<<"\nEnter array elemnts:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,l,h);
    cout<<"\nThe sorted array is:";
    for(int p=0;p<n;p++)
    {
        cout<<" "<<a[p];
    }
    return 0;
}