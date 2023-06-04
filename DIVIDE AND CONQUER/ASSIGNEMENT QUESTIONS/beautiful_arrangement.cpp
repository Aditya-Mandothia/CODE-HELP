#include <bits/stdc++.h>
using namespace std;

void countArrangementHelper(vector<int> &v, int &n, int &ans, int currNum)
{
    // base-case
    if (currNum == n + 1)
    {
        ++ans;
        return;
    }

    // main logic
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] == 0 and (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum;
            countArrangementHelper(v, n, ans, currNum + 1);
            v[i] = 0;
        }
    }
}

int countArrangement(int n)
{
    vector<int> v(n + 1);
    int ans = 0;
    countArrangementHelper(v, n, ans, 1);
    return ans;
}

int main()
{
    int n = 3;
    cout << countArrangement(n);

    return 0;
}