#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for(int i=0;i<arr.size()-1;i++) // iklauta element humesha sorted hai
    {   
        bool swapped = false;

        for(int j=0;j<arr.size()-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            {   
                swapped = true;
                swap(arr[j+1],arr[j]);
            }
        }

        if(swapped == false)  //ek bhi baar swap nhi hua matlab aage bhi nhi hoga and sorted hai array
        return;
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

    vector<int>arr = {1,2,5,3,4};

    bubbleSort(arr);
    print_array(arr);


return 0;
}