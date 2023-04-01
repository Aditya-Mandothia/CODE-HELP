#include <bits/stdc++.h>
using namespace std;

void checkKey(string s, int n, int i, char key, vector<int> &ans)
{

    if (i >= n)
    {
        return;
    }

    if (s[i] == key)
    {
        ans.push_back(i);
    }

    checkKey(s, n, i + 1, key, ans);
}

int main()
{
    string s = "adityamandothia";
    int n = s.length();
    int key = 'a';

    vector<int> ans;

    checkKey(s, n, 0, key, ans);

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}