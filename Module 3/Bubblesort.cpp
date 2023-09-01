#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
int main()
{
    int n;
    int a[100];
    cout << "\n21BCE4008\nDhruv Gandhi";
    cout << "\nEnter number of array elements:";
    cin >> n;
    cout << "\nEnter array elemnts:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\n";
    bubblesort(a, n);
    cout << "The array is:\n";
    for (int j = 0; j < n; j++)
    {
        cout << " " << a[j];
    }
    return 0;
}