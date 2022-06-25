#include <iostream>
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

int countNode(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}

int sumNode(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNode(root->left) + sumNode(root->right) + root->data;
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
    cout << countNode(root) << endl;
    cout << sumNode(root);
    return 0;
}
