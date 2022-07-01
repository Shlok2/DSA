#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *newnode(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

node *searchinBST(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    // if root->data = key -> return root itself.
    if (root->data == key)
    {
        return root;
    }
    // if root->data >key then key must exist in left subtree.
    if (root->data > key)
    {
        searchinBST(root->left, key);
    }
    else
    {
        // if root->data<key then key must exist in right subtree.
        return searchinBST(root->right, key);
    }
}

node *inordersucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteinBST(node *root, int key)
{
    // if key <root->data then we can find key in root->left.And after deleting ,all changes
    // will be reflected in root->left pointer me.
    if (key < root->data)
    {
        root->left = deleteinBST(root->left, key);
    }
    // if key >root->data then we can find key in root->right.And after deleting ,all changes
    // will be reflected in root->right pointer me.
    else if (key > root->data)
    {
        root->right = deleteinBST(root->right, key);
    }
    // if key = root->data
    else
    {
        // cases 1,2 are handled by below 2 if conditions.
        if (root->left == NULL)
        {
            // if root->left = NULL then store kara lenge root ke right ko temp me.And then
            // delete(free) root.
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        // below temp is different from above temp.
        node *temp = inordersucc(root->right);
        root->data = temp->data;

        // Delete the inorder successor.
        root->right = deleteinBST(root->right, temp->data);
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
    node *root = newnode(4);
    root->left = newnode(2);
    root->right = newnode(5);
    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(6);
    root = deleteinBST(root, 5);
    inorder(root);
    return 0;
}
