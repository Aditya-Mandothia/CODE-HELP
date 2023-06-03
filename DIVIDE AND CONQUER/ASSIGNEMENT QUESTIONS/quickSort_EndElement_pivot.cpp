#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &a, int start, int end)
{

    if (start >= end)
        return;

    int i = start - 1;
    int j = start;
    int pivot = end;

    while (j < pivot)
    {
        if (a[j] < a[pivot])
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    i++;

    swap(a[i], a[pivot]);

    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}
int main()
{

    vector<int> a = {7, 2, 1, 8, 6, 3, 5, 4};

    int start = 0;
    int end = a.size() - 1;

    // int i=start-1;
    // int j=start;

    quickSort(a, start, end);

    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}