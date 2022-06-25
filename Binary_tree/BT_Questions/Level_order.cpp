#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void level_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        if (top != NULL)
        {
            cout << top->data << " ";
            if (top->left)
            {
                q.push(top->left);
            }
            if (top->right)
            {
                q.push(top->right);
            }
        }
        if (top == NULL)
        {
            q.push(NULL);
        }
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
    level_order(root);
    return 0;
}
