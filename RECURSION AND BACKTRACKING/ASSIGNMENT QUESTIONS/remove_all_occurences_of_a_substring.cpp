#include <bits/stdc++.h>
using namespace std;

void removeOCC(string &s, string &part)
{
    int found = s.find(part);
    if (found != string ::npos)
    {

        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;

        removeOCC(s, part);
    }
    else
    {
        return;
    }
}

string removeOccurences(string &s, string part)
{
    removeOCC(s, part);
    return s;
}

int main()
{   

    string s = "dabcgabcee";
    string part = "abc";

    string ans = removeOccurences(s,part);
    cout<<ans<<endl;

    return 0;
}