// #include <bits/stdc++.h>
// using namespace std;

// bool kthAncestor(Node *root, int &k, int p)
// {
//     // base case
//     if (root == NULL)
//         return false;

//     if (root->data == p)
//     {
//         return true;
//     }

//     bool leftAns = kthAncestor(root->left, k, p);
//     bool rightAns = kthAncestor(root->right, k, p);

//     // wapas aare honge
//     // check left ya right me answer mila ya anhi
//     if (leftAns || rightAns)
//         k--;
//     if (k == 0)
//     {
//         cout << "Answer: " << root->data << endl;
//         k = -1;
//     }

//     return leftAns || rightAns;
// }

// int main()
// {

//     return 0;
// }