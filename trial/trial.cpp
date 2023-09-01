#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout<<"\nEnter first number: ";
    cin>>a;
    cout<<"\nEnter second number: ";
    cin>>b;
    while (a!=b)
    {
        if (a>b)
        {
            a=a-b;
        }
        else if(b>a)
        {
            b=b-a;
        }
    }
    cout<<"GCD is:"<<a;
}