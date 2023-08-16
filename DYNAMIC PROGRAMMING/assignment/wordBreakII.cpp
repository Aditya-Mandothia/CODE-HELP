#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<string>> dp;

    vector<string> solve(string &s, unordered_map<string, bool> &dict, int i)
    {
        if (i == s.size())
        {
            return {""};
        }

        if (dp.find(i) != dp.end())
            return dp[i];

        vector<string> ans;
        string word;

        for (int j = i; j < s.size(); j++)
        {
            word.push_back(s[j]);

            if (dict.find(word) == dict.end())
                continue;

            // if found
            auto right = solve(s, dict, j + 1);

            for (auto eachRight : right)
            {
                string endPart;
                if (eachRight.size() > 0)
                    endPart = " " + eachRight;
                ans.push_back(word + endPart);
            }
        }

        return dp[i] = ans;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> dict;

        for (auto word : wordDict)
            dict[word] = 1;

        return solve(s, dict, 0);
    }
};