#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // why we can't do temp++ that is because LL is non-continous
    }

    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

void insertAttail(Node *&head, int data)
{
    Node *newNode = new Node(data);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteANode(int pos, Node *&head)
{
    Node *temp = head;

    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    Node *deleteValue = temp->next;
    temp->next = temp->next->next;
    delete deleteValue;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(11);
    Node *third = new Node(12);
    Node *fourth = new Node(13);

    first->next = second;
    second->next = third;
    third->next = fourth;

    // cout << "Printing LL: " << endl;

    print(first);
    cout << "++++++++++++++++++++++++++++++++" << endl;
    insertAtHead(first, 9);
    print(first);
    insertAttail(first, 14);
    cout << endl;
    print(first);

    int pos = 3;
    deleteANode(pos, first);
    cout << endl;
    print(first);
    return 0;
}