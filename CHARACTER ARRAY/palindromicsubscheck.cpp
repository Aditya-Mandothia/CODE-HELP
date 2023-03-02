#include <bits/stdc++.h>
using namespace std;

// odd and even substrings

int expand(string s, int i, int j)
{
    int c = 0;

    while (i >= 0 and j < s.length() and s[i] == s[j])
    {
        c++;
        i++;
        j--;
    }

    return c;
}

int countsusbtrings(string s)
{
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int oddKaAns = expand(s, i, i);
        count = count + oddKaAns;

        int evenKaAns = expand(s, i, i + 1);
        count = count + evenKaAns;
    }

    return count;
}

int main()
{
    string s = "noon";
    cout<<"No. of palindromic substrings is: "<<countsusbtrings(s);

    return 0;
}