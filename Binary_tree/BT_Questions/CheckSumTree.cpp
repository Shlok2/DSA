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

int checkSumTree(node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int ls = checkSumTree(root->left);
    int rs = checkSumTree(root->right);

    if (root->data == ls + rs && checkSumTree(root->left) && checkSumTree(root->right))
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    node *root = new node(26);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->right = new node(3);

    int check = checkSumTree(root);
    if (check = 1)
    {
        cout << "The given tree is a Sum Tree";
    }
    else
    {
        cout << "The given tree is not a Sum Tree";
    }
    return 0;
}
