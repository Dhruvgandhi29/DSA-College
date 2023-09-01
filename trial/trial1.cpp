#include <iostream>
using namespace std;
int temp,sum=0;
void sumans(int n)
{
    if(temp!=0)
    {
        sum=sum+temp%10;
        temp=temp/10;   
        sumans(temp);
    }
    
}
int main()
{
    int n,x;
    cout<<"Enter your number";
    cin>>n;
    temp=n;
    cout<<"\n"<<temp;
    sumans(temp);
    cout<<"\n"<<sum;
}