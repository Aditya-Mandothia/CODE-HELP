#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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
    int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp)
    {
        if (!root)
            return 0;

        if (dp.find(root) != dp.end())
            return dp[root];

        int rob = 0;
        int dontRob = 0;

        rob += root->val;

        if (root->left)
            rob += solve(root->left->left, dp) + solve(root->left->right, dp);

        if (root->right)
            rob += solve(root->right->left, dp) + solve(root->right->right, dp);

        dontRob = solve(root->left, dp) + solve(root->right, dp);

        dp[root] = max(rob, dontRob);
        return dp[root];
    }

    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> dp;
        return solve(root, dp);
    }
};