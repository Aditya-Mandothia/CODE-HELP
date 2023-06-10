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

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

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

int main()
{

    // vector<int> T = {90, 20, 11, -1, -1, 13, -1, -1, 50, -1, -1};
    Node *root = NULL;
    root = buildTree();
    levelOrderTraversal(root);

    return 0;
}