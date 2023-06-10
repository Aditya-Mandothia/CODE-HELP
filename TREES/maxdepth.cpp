#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *buildTree()
{

    int data;
    cout << "\nEnter the Node : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // perform 1,2,3

    Node *root = new Node(data);

    cout << "Enter data on the left of " << data << " Node : " << endl;

    root->left = buildTree();

    cout << "Enter data on the right of " << data << " Node : " << endl;

    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int maxheight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftheight = maxheight(root->left);
    int rightheight = maxheight(root->right);
    int ans = 1 + max(leftheight, rightheight);

    return ans;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = maxheight(root->left) + 1 + maxheight(root->right);

    return max(op1, max(op2, op3));
}

bool isSame(Node *root1, Node *root2) // we have done this with pre order traversal 
{
    if (root1 == NULL or root2 == NULL)
    {
        return (root1 == root2);
    }

    return (root1->data == root2->data and isSame(root1->left, root2->left) and isSame(root1->right, root2->right));
}

int main()
{

    // vector<int> T = {90, 20, 11, -1, -1, 13, -1, -1, 50, -1, -1};
    Node *root = NULL;
    root = buildTree();

    Node* root2 = NULL;
    root2 = buildTree();

    // levelOrderTraversal(root);
    // cout << maxheight(root) - 1;
    // cout << endl
    //      << diameter(root);

    cout<<isSame(root,root2);

    return 0;
}