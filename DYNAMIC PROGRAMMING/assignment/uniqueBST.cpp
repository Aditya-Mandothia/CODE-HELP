#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<pair<int, int>, vector<TreeNode *>> dp;

    vector<TreeNode *> solve(int start, int end)
    {

        // base
        if (start > end)
            return {NULL};
        if (start == end)
            return {new TreeNode(start)};

        if (dp.find({start, end}) != dp.end())
            return dp[{start, end}];

        vector<TreeNode *> ans;

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = solve(start, i - 1);
            vector<TreeNode *> right = solve(i + 1, end);

            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        return dp[{start, end}] = ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};