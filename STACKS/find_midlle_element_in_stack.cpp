#include <bits/stdc++.h>
using namespace std;

void midel(stack<int> s, int totalSize)
{
    if (s.empty())
    {
        cout << "NO MIDLLE ELEMENT." << endl;
        return;
    }

    if (s.size() == (totalSize / 2) + 1)
    {
        cout << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    midel(s, totalSize);

    s.push(temp);
}

int main()
{

    stack<int> a;

    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);

    int size = a.size();

    midel(a, size);

    return 0;
}