#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int height(TreeNode *root)
//     {
//         if (root == NULL)
//         {
//             return 0;
//         }
//         // 1 node = 1 height
//         int leftheight = height(root->left);
//         int rightheight = height(root->right);
//         int ans = max(leftheight, rightheight) + 1;

//         return ans;
//     }

//     bool isBalanced(TreeNode *root)
//     {

//         if (root == NULL)
//             return true;

//         int leftheight = height(root->left);
//         int rightheight = height(root->right);
//         int diff = abs(leftheight - rightheight);

//         bool ans1 = (diff <= 1);

//         bool leftans = isBalanced(root->left);
//         bool rightans = isBalanced(root->right);

//         if (ans1 && leftans && rightans)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

// int main()
// {

//     return 0;
// }