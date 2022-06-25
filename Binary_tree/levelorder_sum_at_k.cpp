#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printlevelorder(node *root)
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
        // make Node variable to store front of q.
        node *Node = q.front();
        q.pop();

        // when node is not null
        if (Node != NULL)
        {
            cout << Node->data << " ";
            // if Node->left is not null.
            if (Node->left)
            {
                q.push(Node->left);
            }
            // if Node->right is not null.
            if (Node->right)
            {
                q.push(Node->right);
            }
        }

        // when node is null
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

// to find sum at k level.

int sumatk(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();

        if (Node != NULL)
        {
            // if level is equal to k(meaning our desired level) than we will add data of Nodes.
            // eg -> 4+5+6+7 in (below) when level = 2
            //    1
            //   / \
            //  2    3
            //  /\   /\ 
            // 4  5 6  7
            if (level == k)
            {
                sum += Node->data;
            }
            if (Node->left)
            {
                q.push(Node->left);
            }
            if (Node->right)
            {
                q.push(Node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            // it will increment the level when NULL approches in queue.
            level++;
        }
    }
    return sum;
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
    printlevelorder(root);
    cout << endl;
    cout << sumatk(root, 2);
    return 0;
}
