#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> a;

    int arr[] = {1, 2, 3, 4, 5};

    cout << "Initial string: ";

    int i = 0;
    while (i < 5)
    {
        a.push(arr[i]);
        cout << arr[i];
        i++;
    }

    cout << "\nReversed string is: ";

    while (!a.empty())
    {
        cout << a.top();
        a.pop();
    }

    return 0;
}