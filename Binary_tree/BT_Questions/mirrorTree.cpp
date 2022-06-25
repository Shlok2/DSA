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

node *mirrorTree(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    if (root->left)
    {
        mirrorTree(root->left);
    }
    if (root->right)
    {
        mirrorTree(root->right);
    }

    return root;
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
    struct node *root = new node(2);
    root->left = new node(1);
    root->left->left = new node(12);
    root->right = new node(8);
    // root->left->right = new node(4);
    // root->right->left = new node(6);
    root->right->right = new node(9);
    inorder(root);
    cout << endl;
    mirrorTree(root);
    inorder(root);
    return 0;
}
