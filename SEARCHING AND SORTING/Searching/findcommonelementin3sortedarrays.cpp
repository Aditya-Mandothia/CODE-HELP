#include <bits/stdc++.h>
using namespace std;

int main()
{

    // 3 arrays are sorted
    int a[] = {1, 2, 4, 5};
    int b[] = {1, 2, 3, 6};
    int c[] = {1, 2, 3, 8};

    set<int> s;

    int n1, n2, n3;
    n1 = n2 = n3 = 5;

    int i, j, k;
    i = j = k = 0;

    while (i < n1 and j < n2 and k < n3)
    {
        if (a[i] == b[j] and b[j] == c[k])
        {
            s.insert(a[i]);
            i++;j++;k++;  //as soon as we find we move everything further
    
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    vector<int> ans;

    for (auto x : s)
    {
        ans.push_back(x);
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}