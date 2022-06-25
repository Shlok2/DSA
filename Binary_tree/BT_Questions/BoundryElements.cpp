#include <iostream>
#include <string.h>
#include <queue>
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

void rightview(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {

            node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                // If it is leaf node -> then don't print it and return by this function.
                if (curr->left == NULL && curr->right == NULL)
                {
                    return;
                }
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftview(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                // If it is leaf node -> then don't print it and return by this function.
                if (curr->left == NULL && curr->right == NULL)
                {
                    return;
                }
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void printLeaves(struct node *root)
{
    if (root == NULL)
        return;

    printLeaves(root->left);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        printf("%d ", root->data);

    printLeaves(root->right);
}

void printBoundry(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Print root node.
    cout << root->data << " ";

    // Print left view, we can print left nodes just by passing root->left(Hence root will
    //  not be printed in this process).
    leftview(root->left);

    // to print leaves of root->left.
    printLeaves(root->left);
    // to print leaves of root->right.
    printLeaves(root->right);

    // to print right view. we can print right nodes just by passing root->right.
    rightview(root->right);
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
    // struct node *root = new node(20);
    // root->left = new node(8);
    // root->left->left = new node(4);
    // root->left->right = new node(12);
    // root->left->right->left = new node(10);
    // root->left->right->right = new node(14);
    // root->right = new node(22);
    // root->right->right = new node(25);
    printBoundry(root);
    return 0;
}
