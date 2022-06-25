
// Convert a given tree into a sum tree.

#include <iostream>
#include <string.h>
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

int sumReplace(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int old_val = root->data;
    root->data = sumReplace(root->left) + sumReplace(root->right);
    return root->data + old_val;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(int argc, char const *argv[])
{
    node *root = new node(10);
    root->left = new node(-2);
    root->right = new node(6);
    root->left->left = new node(8);
    root->left->right = new node(-4);
    root->right->left = new node(7);
    root->right->right = new node(5);
    inorder(root);
    sumReplace(root);
    cout << endl;
    inorder(root);
    return 0;
}
