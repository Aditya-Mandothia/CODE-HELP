#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> height(Node *root)
{
    if (!root)
        return {0, 0};

    auto lh = height(root->left);
    auto rh = height(root->right);

    int sum = root->data;

    if (lh.first == rh.first)
    {
        sum += lh.second > rh.second ? lh.second : rh.second;
    }
    else if (lh.second > rh.second)
    {
        sum+= lh.second;
    }
    else{
        sum+= rh.second; 
    }

    return {1 + max(lh.first,rh.first),sum};
}

int longestBloodline(Node *root)
{
    auto h = height(root);
    return h.second;
}

int main()
{

    return 0;
}