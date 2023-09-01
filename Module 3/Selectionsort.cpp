#include <iostream>
using namespace std;
void selectionsort(int a[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if (a[j]<min)
            {
                min=a[j];
                a[j]=a[i];
                a[i]=min;
            }
        }
    }
}
int main()
{
    int n;
    int a[100];
    cout<<"\n21BCE4008\nDhruv Gandhi";
    cout<<"\nEnter number of array elements:";
    cin>>n;
    cout<<"\nEnter array elemnts:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\n";
    selectionsort(a,n);
    cout<<"The array is:\n";
    for(int j=0;j<n;j++)
    {
        cout<<" "<<a[j];
    }
    return 0;
}