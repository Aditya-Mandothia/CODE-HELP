#include<bits/stdc++.h>
using namespace std;

int mindiff(vector<string>arr)
{
    vector<int>minutes;

    for(int i=0;i<arr.size();i++)
    {
        string curr = arr[i];

        int hour = stoi(curr.substr(0,2));
        int mins = stoi(curr.substr(3,2));

        int totalMins = hour*60 + mins;
        minutes.push_back(totalMins);
    }

    sort(minutes.begin(),minutes.end());

    int min_diff = INT_MAX;

    for(int i=1;i<minutes.size();i++)
    {
        int diff = minutes[i] - minutes [i-1];
        min_diff = min(min_diff,diff);
    }


    return min_diff;
}


int main()
{
    vector<string>arr = {"23:11","11:40","22:50","11:30"};
    cout<<"The minimum time difference is "<<mindiff(arr)<<" minutes";

return 0;
}