#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++) // s =
    {
        char ch = s[i];

        // opening bracket
        if (ch == '(' or ch == '[' or ch == '{')
        {
            st.push(ch);
        }
        else
        { // closing bracket
            if (!st.empty())
            {
                char topCh = st.top();
                if (ch == ')' and topCh == '(')
                {
                    st.pop();
                }

                else if (ch == ']' and topCh == '[')
                {
                    st.pop();
                }

                else if (ch == '}' and topCh == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
}

int main()
{
    string s = "{[]}";
    cout << isValid(s);

    return 0;
}