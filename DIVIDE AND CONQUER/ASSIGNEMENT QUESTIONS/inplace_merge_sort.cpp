#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int end)
{

    int total_size = end - start + 1;
    int gap = (total_size / 2) + (total_size % 2);

    while (gap > 0)
    {
        int i = start;
        int j = gap + start;

        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }

            ++i, ++j;
        }

        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}
void mergeSort(vector<int> &v, int start, int end)
{

    if (start >= end)
        return;

    int mid = (start + end) / 2;

    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, end);
}

int main()
{

    vector<int> v = {8, 4, 2, 1};

    mergeSort(v, 0, v.size() - 1);

    for (auto x : v)
    {
        cout << x << " ";
    }

    return 0;
}