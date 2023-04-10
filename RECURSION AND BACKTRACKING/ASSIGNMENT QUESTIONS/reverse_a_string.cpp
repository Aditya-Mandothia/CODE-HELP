#include <bits/stdc++.h>
using namespace std;

void stringRev(string &s, int i)
{
    if (i == s.size() / 2)
    {
        return;
    }

    swap(s[i], s[s.size() - 1 - i]);

    stringRev(s, i + 1);
}

int main()
{
    string s = "aditya";
    int i = 0;

    stringRev(s, i);
    cout << s << endl;

    return 0;
}