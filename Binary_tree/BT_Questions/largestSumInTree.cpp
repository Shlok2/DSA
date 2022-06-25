#include <iostream>
#include <string.h>
#include <climits>
#include <algorithm>
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

int addBT(node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + addBT(root->left) + addBT(root->right));
}

int largestSumInTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int largest = INT_MIN;
    // largest = max(largestSumInTree(root->left) + largestSumInTree(root->right) + root->data, largest);
    largest = max(addBT(root), max(addBT(root->left), addBT(root->right)));
    return largest;
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(-2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(-6);
    root->right->right = new node(2);
    cout << "The largest sum in subtree is: " << largestSumInTree(root);
    return 0;
}
