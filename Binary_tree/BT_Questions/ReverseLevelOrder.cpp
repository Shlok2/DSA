#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
// #include <stack>
// #include <queue>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void ReverseLevelOrder(node *root)
{
    stack<node *> s;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        s.push(Node);

        // First push right and then left for reverse level order.
        if (Node->right)
        {
            q.push(Node->right);
        }
        if (Node->left)
        {
            q.push(Node->left);
        }
    }

    while (!s.empty())
    {
        node *a = s.top();
        cout << a->data << " ";
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    ReverseLevelOrder(root);
    return 0;
}
