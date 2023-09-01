#include <iostream>
using namespace std;
char stack[100];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    char x;
    if (top==-1)
    {
        return -1;
    }
    else
    {
        x=stack[top--];
        return x;
    }
}

int precedence(char x)
{
    if (x =='(')
        return 0;
    if (x =='+'||x =='-')
        return 1;
    if (x =='*'||x =='/')
        return 2;
    if (x=='^')
        return 3;
    return 0;  
}

int main()
{
    char s[100];
    char *t,x;
    cout<<"\nEnter in-fix expression:";
    cin>>s;
    t=s;
    cout<<"\nPost-fix expression:";
    while(*t != '\0')
    {
        if(isalnum(*t))
            cout<<*t;
        else if(*t =='(')
            push(*t);
        else if(*t ==')')
        {
            while((x=pop())!='(')
                cout<<x;
        }
        else
        {
            while(precedence(stack[top]) >= precedence(*t))
                cout<<pop();
            push(*t);
        }
        t++;
    }
    while(top != -1)
    {
        cout<<(pop());
    }
    return 0;
}