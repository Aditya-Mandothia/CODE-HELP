#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr)
{
    for(int i=1;i<arr.size();i++)
    {
        int val = arr[i];

        int j=i-1;

        for(;j>=0;j--)   //{1,2,7,3,4};
        {
            if(arr[j]>val)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j+1]=val; //peeche jaane ke baad ek se badhaya
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

    vector<int> arr = {1,2,7,3,4};
    insertionSort(arr);
    print_array(arr);


return 0;
}