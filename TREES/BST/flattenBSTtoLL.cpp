// void in(TreeNode<int>* root, TreeNode<int>* &prev)
// {
//     if(!root) return;

//     in(root->left,prev);
//     prev->left = NULL;
//     prev->right = root;
//     prev=root;
//     in(root->right,prev);
// }


// TreeNode<int>* flatten(TreeNode<int>* root)
// {
//     // Write your code here
//     TreeNode<int>* dummy = new TreeNode<int>(-1);

//     TreeNode<int>* prev = dummy;

//     in(root,prev);

//     prev->left = prev->right = NULL;
//     root=dummy->right;

//     return root;
// }