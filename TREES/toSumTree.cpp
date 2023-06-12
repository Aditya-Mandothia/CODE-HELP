#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data)
    {
        this->data = data;
    }
};

int toSumTree(Node *root)
{

    if (!root)
        return 0;

    // check leaf node
    if (!root->left and !root->right)
    {
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    int lsum = toSumTree(root->left);
    int rsum = toSumTree(root->right);
    int temp = root->data;
    root->data = lsum + rsum;
    return temp + root->data;
}

int main()
{

    return 0;
}