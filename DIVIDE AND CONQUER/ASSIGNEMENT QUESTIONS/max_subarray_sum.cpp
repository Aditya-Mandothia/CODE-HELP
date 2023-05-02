#include <bits/stdc++.h>
using namespace std;

int maxSubArrayHelper(vector<int> &v, int start, int end)
{

    if (start == end)
        return v[start];

    int maxLeftborderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = start + ((end - start) >> 1);

    int maxLeftSum = maxSubArrayHelper(v, start, mid);
    int maxRightSum = maxSubArrayHelper(v, mid + 1, end);

    int leftBorderSum = 0, rightBorderSum = 0;

    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += v[i];
        if (leftBorderSum > maxLeftborderSum)
            maxLeftborderSum = leftBorderSum;
    }

    for (int i = mid; i <= end; i++)
    {
        rightBorderSum += v[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    int crossBorderSum = maxLeftborderSum + maxRightBorderSum;

    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int main()
{

    vector<int> v = {1, 4, -2, 4, -3, -2, 7, -5};
    int start = 0;
    int end = v.size() - 1;
    cout << maxSubArrayHelper(v, start, end);

    return 0;
}