#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{

    // base case
    if (start >= end)
    {
        return true;
    }

    if (s[start] != s[end])
    {
        return false;
    }

    isPalindrome(s, start + 1, end - 1);
}

int main()
{
    string s = "namana";
    cout << isPalindrome(s, 0, s.size() - 1);

    return 0;
}