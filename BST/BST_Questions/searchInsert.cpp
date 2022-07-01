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

node *insertBST(node *root, int k)
{
    if (root == NULL)
    {
        return new node(k);
    }
    if (k > root->data)
    {
        root->right = insertBST(root->right, k);
    }
    else
    {
        root->left = insertBST(root->left, k);
    }
    return root;
}

// Searching a key.
node *search(node *root, int key)
{
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }
    if (root->data < key)
    {
        return search(root->right, key);
    }
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
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    inorder(root);
    return 0;
}
