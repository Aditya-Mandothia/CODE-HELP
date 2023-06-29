// class Solution {
// public:

//     void inorder(TreeNode* root,vector<int>&in)
//     {
//         if(!root) return;

//         inorder(root->left,in);
//         in.push_back(root->val);
//         inorder(root->right,in);
//     }

//     TreeNode* buildBTree(vector<int>&in, int start, int end)
//     {
//         if(start>end)
//         {
//             return NULL;
//         }

//         int mid = (start+end) >> 1;

//         TreeNode* root = new TreeNode(in[mid]);

//         root->left = buildBTree(in,start,mid-1);
//         root->right = buildBTree(in,mid+1,end);

//         return root;
//     }

//     TreeNode* balanceBST(TreeNode* root) {

//         vector<int>in;
//         inorder(root,in);

//         return buildBTree(in,0,in.size()-1);
        
//     }
// };
// Console
