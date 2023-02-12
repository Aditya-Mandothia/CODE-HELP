#include <bits/stdc++.h>
using namespace std;

void transposemat(int arr[][3], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printmat(int arr[][3], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotatebynt(int arr[][3], int R, int C)
{
    transposemat(arr, R, C);

    int i = 0;
    int j = C - 1;
    int rowmover = 0;

    while (i < j)
    {
        swap(arr[i][rowmover], arr[j][rowmover]);
        i++;
        j--;

        if (i == j)
        {
            i = 0;
            j = C - 1;
            rowmover++;
        }

        if (rowmover > R-1)
        {
            break;
        }
    }

    // for(int i=0;i<R;i++)
    // {
    //     for(int j=0;j<C;j++)
    //     {

    //     }
    // }
}

int main()
{
    int arr[3][3] = {
        {1, 4, 8},
        {3, 2, 5},
        {6, 7, 9}};

    int R = 3, C = 3;

    cout << "BEFORE: " << endl
         << endl;
    printmat(arr, R, C);

    // transposemat(arr, R, C);
    rotatebynt(arr, R, C);

    cout << "AFTER: " << endl
         << endl;
    printmat(arr, R, C);
    return 0;
}