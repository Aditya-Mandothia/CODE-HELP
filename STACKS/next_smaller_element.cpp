#include <bits/stdc++.h>
using namespace std;
int main()
{
    // this is the code for next smaller element and if we want to create code for prev smaller element we just have to change the direction of for loop from L->R
    vector<int> arr = {2, 1, 4, 3};
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (st.top() >= curr)
        {
            st.pop();
        }

        // chota number milgya
        ans[i] = st.top();

        //current no. ko push kardiya
        st.push(curr);
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}