#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//swaps the places of elements in array
int partition(int a[],int start,int End)
{
    int pindex,pivot;
    pivot=a[End];//end element is taken as pivot
    pindex=start;//starting element is marked as index
    for(int i=start;i<End;i++)
    {
        if(a[i]>=pivot)
        {
            swap(a[i],a[pindex]);
            pindex=pindex+1;
        }
    }
    swap(a[pindex],a[End]);
    //finds suitable position for pivot and swaps the index with pivot
    return pindex;
}

int quicksort(int a[],int start,int End)
{
    if (start<End)
    {
        int pindex=partition( a,start,End);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,End);
    }
}
/*recursive function that splits array in multiple segements 
and sorts each and every element */
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