#include <iostream>
using namespace std;
//linear search
int main ()
{
    int n,x, flag=0; 
    cout<<"\n";
    cout<<"Enter number of array elements:";
    cin>>n;
    int *a= new int[n];
    cout<<"Enter the array elements:";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element to be searched;";
    cin>>x;
    for(int j=0;j<=n;j++)
    {
        if(x==a[j])
        {
            cout<<"Element found at "<<j<<" position in array.";
            flag++;
        }
    }
    if (flag<1)
    {
        cout<<"Element not found";
    }
    return 0;
}