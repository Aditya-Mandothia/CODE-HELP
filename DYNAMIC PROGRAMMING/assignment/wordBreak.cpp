#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(string s, vector<string> &wordDict)
    {
        for (auto i : wordDict)
        {
            if (s == i)
                return true;
        }

        return false;
    }

    bool solve(string &s, vector<string> &wordDict, int start, vector<int> &dp)
    {

        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        // one case

        string word = "";
        bool flag = false;

        for (int i = start; i < s.size(); i++)
        {
            word += s[i];

            if (check(word, wordDict))
            {
                flag = flag || solve(s, wordDict, i + 1, dp);
            }
        }

        return dp[start] = flag;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);
        return solve(s, wordDict, 0, dp);
    }
};