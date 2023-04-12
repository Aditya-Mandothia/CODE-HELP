#include <bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> &arr, int i, int &minPrice, int &maxPrice)
{
    // base case
    if (i > arr.size() - 1)
        return;

    // one case sol
    if (arr[i] < minPrice)
    {
        minPrice = arr[i];
    }

    if (arr[i] - minPrice > maxPrice)
    {
        maxPrice = arr[i] - minPrice;
    }

    maxProfit(arr, i + 1, minPrice, maxPrice);
}

int main()
{

    vector<int> arr = {7, 5, 1, 4, 8, 11};

    int minPrice = INT_MAX;
    int maxPrice = INT_MIN;
    int i = 0;

    maxProfit(arr, i, minPrice, maxPrice);
    cout << "THE MAXIMUM PROFIT : " << maxPrice << endl;

    return 0;
}