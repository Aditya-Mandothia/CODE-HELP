#include <bits/stdc++.h>
using namespace std;

vector<char> printPattern(int N)
{
    // code here
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout << " ";
    }
}

int main()
{
    
    return 0;
}