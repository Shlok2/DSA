#include <iostream>
#include <string.h>
#include <climits>
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

bool isBSTutil(node *root, int min, int max)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }

    // if both below are true ->then return true.
    return isBSTutil(root->left, min, root->data - 1) &&
           isBSTutil(root->right, root->data + 1, max);
}

int isBST(node *root)
{
    isBSTutil(root, INT_MIN, INT_MAX);
}

int main(int argc, char const *argv[])
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
    return 0;
}
