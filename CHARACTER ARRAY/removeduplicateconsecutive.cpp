#include<bits/stdc++.h>
using namespace std;

string removedupcons(string s)  //aa xy zz
{
    string ans = "";

    int i=0;

    while(s.length()>i)
    {
        if(ans.length()-1 >=0 and ans[ans.size()-1] == s[i])
        ans.pop_back();
        else
        ans.push_back(s[i]);
        i++;
    }

    return ans;

}

int main()
{
    string s = "aaxyzz";
    cout<<removedupcons(s);
return 0;
}