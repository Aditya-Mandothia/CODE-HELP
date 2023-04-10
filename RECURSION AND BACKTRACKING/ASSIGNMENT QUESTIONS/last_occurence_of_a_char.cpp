#include <bits/stdc++.h>
using namespace std;

void lastOcc(string s, char x, int i, int &index)
{
    if (i >= s.size())
    {
        return;
    }

    if(s[i]==x)
    {
        index = i;
    }

    lastOcc(s,x,i+1,index);
  
}

int main()
{
    string s = "abcddefdg";

    // we need to find the last occurence of d(recurisively).

    char x = 'd';
    int index = 0;

    lastOcc(s, x, 0, index);
    cout<<index;

    return 0;
}