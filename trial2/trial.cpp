#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
int partition(int a[],int start,int end)
{
    int pindex,pivot;
    pivot=a[end];
    pindex=start;
    for(int i=start;i<end;i++)
    {
        if (a[i]<pivot)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[end]);
    return pindex;
}
void quicksort(int a[],int start,int end)
{
    int pindex;
    if (start<end)
    {
        pindex=partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
    }
}
int main()
{
    int n;
    int a[100];
    cout<<"\n21BCE4008\nDhruv Gandhi";
    cout<<"\nEnter number of array elements:";
    cin>>n;
    int start=0,End=n-1;//position starts from 0 to n-1
    cout<<"\nEnter array elemnts:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\n";
    quicksort(a,start,End);
    cout<<"The array is:\n";
    for(int j=0;j<n;j++)
    {
        cout<<" "<<a[j];
    }
    return 0;
}