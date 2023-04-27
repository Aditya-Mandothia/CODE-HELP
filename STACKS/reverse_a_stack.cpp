#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int target)
{
    if (st.empty())
    {
        // cout<<"no element can be inserted at bottom";
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertAtBottom(st, target);

    st.push(topElement);
}

void reverseStack(stack<int> &st)
{

    // base case
    if (st.empty())
        return;

    int target = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, target);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // cout << "BEFORE: " << endl;

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    reverseStack(st);

    cout << "\n\nAFTER: " << endl;

     while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}