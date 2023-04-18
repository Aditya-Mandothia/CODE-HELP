#include <bits/stdc++.h>
using namespace std;

void allpermutations(string &a, int i)
{

    // base case
    if (i > a.size() - 1)
    {
        cout << a << endl;
        return;
    }

    for (int j = i; j < a.size(); j++)
    {
        swap(a[i], a[j]);

        allpermutations(a, i + 1);

        swap(a[i], a[j]); // restoring original string
    }
}
int main()
{
    string a = "abc";
    int i = 0;
    allpermutations(a, i);

    return 0;
}