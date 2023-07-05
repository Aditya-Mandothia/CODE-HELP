#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long pref=1;
	    long long suff=1;
	    long long maxi=INT_MIN;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(pref==0) pref=1;
	        if(suff==0) suff=1;
	        
	        pref=pref*arr[i];
	        suff=suff*arr[n-i-1];
	        
	        maxi=max(maxi,max(pref,suff));
	        
	    }
	    
	    return maxi;
	}
};

int main()
{

return 0;
}