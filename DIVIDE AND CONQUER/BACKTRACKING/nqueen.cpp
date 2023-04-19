#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &arr, int i, int j)
{

    // check row

    for (int k = 0; k < arr.size(); k++)
    {
        if (arr[i][k] == 1)
            return false;
    }

    // check column
    for (int k = 0; k < arr.size(); k++)
    {
        if (arr[k][j] == 1)
            return false;
    }

    // check diaognals
    int x = i;
    int y = j;

    // ULD
    while (x >= 0 and y >= 0)
    {
        if (arr[x][y] == 1)
            return false;

        x--;
        y--;
    }

    x = i;
    y = j;

    // LRD
    while (x < arr.size() and y < arr.size())
    {
        if (arr[x][y] == 1)
            return false;

        x++;
        y++;
    }

    x = i;
    y = j;

    // URD
    while (x >= 0 and y < arr.size())
    {
        if (arr[x][y] == 1)
            return false;

        x--;
        y++;
    }

    x = i;
    y = j;

    // LlD
    while (x < arr.size() and y >= 0)
    {
        if (arr[x][y] == 1)
            return false;

        x++;
        y--;
    }

    return true;
}

void nqueen(vector<vector<int>> &arr, int i)
{

    // base case
    if (i == arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                cout << arr[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl
             << endl;

        return;
    }

    for (int j = 0; j < arr.size(); j++)
    {
        if (isSafe(arr, i, j))
        {
            arr[i][j] = 1;

            nqueen(arr, i + 1);
        }

        arr[i][j] = 0;
    }
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0, 0},
                               {0, 0, 0, 0},
                               {0, 0, 0, 0},
                               {0, 0, 0, 0}};

    // we have to place 4 queens on the board
    int i = 0;
    // int j = 0;
    nqueen(arr, i);

    return 0;
}