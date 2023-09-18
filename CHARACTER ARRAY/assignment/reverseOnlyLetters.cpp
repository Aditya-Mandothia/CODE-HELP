#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string x){

    int l = 0;
    int h = x.size()-1;

    while(l<h)
    {
        if(isalpha(x[l]) and isalpha(x[h]))
        {
            swap(x[l],x[h]);
            l++;
            h--;
        }
        else if(!isalpha(x[l]))
        {
            l++;
        }
        else{
            h--;
        }
    }

    return x;

}

int main()
{
    string x = "test1ingLeetc0d3_";

    cout<<reverseOnlyLetters(x);


return 0;
}