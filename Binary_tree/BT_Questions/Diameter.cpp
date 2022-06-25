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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return (max(lheight, rheight) + 1);
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdiameter = lheight + rheight + 1;
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(currdiameter, max(ldiameter, rdiameter));
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
    diameter(root);
    return 0;
}
