#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(beginWord);

        while (!q.empty())
        {
            pair<string, int> fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            if (currString == endWord)
            {
                return currCount;
            }

            for (int index = 0; index < currString.size(); index++)
            {
                char originalCharacter = currString[index];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[index] = ch;

                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }

                currString[index] = originalCharacter;
            }
        }

        return 0;
    }
};