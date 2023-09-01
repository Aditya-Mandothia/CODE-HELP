#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string &beginWord, string &endWord, vector<string> &wordList)
    {

        vector<vector<string>> ans;
        queue<pair<vector<string>, int>> q; // first : sequence, second : level
        q.push({{beginWord}, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        int prevLevel = -1;
        vector<string> toBeRemoved;

        while (!q.empty())
        {
            auto fNode = q.front();
            q.pop();

            auto currSeq = fNode.first;

            auto currString = currSeq[currSeq.size() - 1];
            int currCount = fNode.second;

            if (currCount != prevLevel) // multiple paths ke liye ek baar mein hi delete na hojae
            {
                for (auto s : toBeRemoved)
                    st.erase(s);
                toBeRemoved.clear();
                prevLevel = currCount;
            }

            if (currString == endWord)
            {
                ans.push_back(currSeq);
            }

            for (int index = 0; index < currString.size(); index++)
            {
                char originalCharacter = currString[index];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;

                    if (st.find(currString) != st.end())
                    {
                        auto temp = currSeq;
                        temp.push_back(currString);
                        q.push({temp, currCount + 1});
                        // st.erase(currString);
                        toBeRemoved.push_back(currString);
                    }
                }

                currString[index] = originalCharacter;
            }
        }

        return ans;
    }
};