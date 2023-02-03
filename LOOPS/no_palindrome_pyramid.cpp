#include <bits/stdc++.h>

using namespace std;

int main()
{
    int row = 5;

    for (int i = 0; i < row; i++)
    {
        int j;
        for (j = 1; j < i + 1; j++)
        {
            cout << j;
        }

        j = j - 2;

        for (; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}