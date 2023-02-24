#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[min_index], arr[i]);
    }
}

void print_array(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
}

int main()
{

    vector<int> arr = {1, 2, 5, 3, 4};
    selection_sort(arr);
    print_array(arr);

    return 0;
}