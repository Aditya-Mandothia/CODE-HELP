#include <bits/stdc++.h>
using namespace std;

int numSquareHelper(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while (i <= end)
    {
        int perfectSquare = i * i;
        int noOfPF = 1 + numSquareHelper(n - perfectSquare);

        if (noOfPF < ans)
        {
            ans = noOfPF;
        }

        ++i;
    }

    return ans;
}

int numsquare(int n)
{
    int ans = numSquareHelper(n) - 1;
    return ans;
}
int main()
{
    int n = 13;
    cout << numsquare(n);

    return 0;
}