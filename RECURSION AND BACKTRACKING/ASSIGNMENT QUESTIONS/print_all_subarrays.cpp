#include <bits/stdc++.h>
using namespace std;

// void printall(string &s, int i, int j)
// {
//     if (i > s.size() - 1)
//     {
//         return;
//     }

//     if (j > i)
//     {

//         printall(s, i + 1, 0);
//     }

//     cout << s[j] << " ";

//     printall(s, i, j + 1);

//     cout << endl;
// }

void printSubUtil(string &s, int start, int end)
{
    if (end == s.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    printSubUtil(s, start, end + 1);
}

void printSub(string &s, int start)
{
    for (int i = start; i < s.size(); i++)
    {
        printSubUtil(s, i, i);
    }
}

int main()
{

    string s = "abc";
    // printall(s, 0, 0);
    // printSubUtil(s,0,0);

    printSub(s, 0);
    return 0;
}