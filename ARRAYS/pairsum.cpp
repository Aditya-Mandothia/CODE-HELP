#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 2, 5, 2, 4};
    int key = 3; // that is find a pair whose sum is 3.
    sort(a.begin(), a.end());

    int i = 0, j = a.size() - 1;

    int c = 0;
    while (i < j)
    {
        if (a[i] + a[j] == 3)
        {
            c++;
            j--;
        }

        else if (a[i] + a[j] < 3)
            i++;
        else if (a[i] + a[j] > 3)
            j--;
    }

    cout << c;

    return 0;
}