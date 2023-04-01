#include<bits/stdc++.h>
using namespace std;

void printDigits(int num)
{
    if(num == 0)
    {   
        // cout<<0<<" ";
        return;
    }

    printDigits(num/10);
    int digit = num%10;
    cout<<digit<<" ";


}

int main()
{
    int num = 6400;
    printDigits(num);

return 0;
}