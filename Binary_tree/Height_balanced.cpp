#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool heightbalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    // we will come to know that cuurent root left subtree is not balanced,if heightbalanced
    //  (root->left) is false
    if (heightbalanced(root->left) == false)
    {
        return false;
    }
    // we will come to know that cuurent root right subtree is not balanced,if heightbalanced
    //  (root->right) is false
    if (heightbalanced(root->right) == false)
    {
        return false;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    // abs means absolute(mod) value.
    if (abs(leftheight - rightheight) <= 1)
    {
        return true;
    }
    else
    {
        return false;
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
    if (heightbalanced(root))
    {
        cout << "Balance tree";
    }
    else
    {
        cout << "Unbalance tree";
    }
    return 0;
}
