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

bool isBST(node *root, node *min = NULL, node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && min->data >= root->data)
    {
        return false;
    }
    if (max != NULL && max->data <= root->data)
    {
        return false;
    }
    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid = isBST(root->right, root, max);

    // if both leftvalid and rightvalid will be true than only return true.
    return leftvalid and rightvalid;
}

int main(int argc, char const *argv[])
{
    node *root = newnode(4);
    root->left = newnode(2);
    root->right = newnode(5);
    root->left->left = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(6);

    if (isBST(root, NULL, NULL))
    {
        cout << "BST is valid" << endl;
    }
    else
    {
        cout << "BST is invalid" << endl;
    }
    return 0;
}
