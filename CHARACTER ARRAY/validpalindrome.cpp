#include<bits/stdc++.h>
using namespace std;

// check whether a string is a palindrome removing atmost 1 character from it
bool checkP(string s,int i, int j)
{
    // int i=0;
    // int j=s.length()-1;

    while(i<=j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool validP(string s)
{
    int i=0;
    int j=s.length()-1;

    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return checkP(s,i+1,j) || checkP(s,i,j-1);  //abaa
        }
        else
        {
            i++;
            j--;
        }
    }

    return true;

}
int main()
{   

    string s = "abca";
    cout<<validP(s);

return 0;
}