#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, int n, int open, int close, string output)
{

    if (open == 0 and close == 0)
    {
        ans.push_back(output);
        return;
    }

    // include open bracket

    if (open > 0)
    {
        output.push_back('(');
        solve(ans, n, open - 1, close, output);
        output.pop_back();
    }

    if (close > open) // because at this point the remaining would be close > open to make the successive valid parenthesis
    {
        output.push_back(')');
        solve(ans, n, open, close - 1, output);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    string output = "";
    int open = n;
    int close = n;

    vector<string> ans;

    solve(ans, n, open, close, output);

    return ans;
}

int main()
{

    int n = 3;
    vector<string> result = generateParenthesis(n);

    for (auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}