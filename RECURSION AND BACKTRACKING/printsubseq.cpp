#include<bits/stdc++.h>
using namespace std;

void subseq(string a, string output, int i)
{
    if(i >= a.length())
    {   
        cout<<output<<endl;
        return;
    }

    //exclude
     subseq(a,output,i+1);

     //include
     output.push_back(a[i]);
     subseq(a,output,i+1);

     
    
}

int main()
{
    string a = "abc";
    string output = "";

    int i=0;
    int n = a.size()-1;
    subseq(a,output,i);

return 0;
}