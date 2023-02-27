#include <bits/stdc++.h>
using namespace std;

string removesubstring(string s, string part)
{
    int pos = s.find(part);   //very important concept

    while(pos != string::npos)
    {
        s.erase(pos,part.size());
        pos = s.find(part);
    }

    return s;
}

int main()
{
    string s = "abcxyzabcweq";
    string part = "abc";
    cout<<removesubstring(s, part);

    return 0;
}