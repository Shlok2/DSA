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

node *findLCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > n1 && root->data > n2)
    {
        return findLCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);

    int n1 = 10, n2 = 14;
    node *t = findLCA(root, n1, n2);
    cout << "LCA of node " << n1 << " and " << n2 << " is: " << t->data << endl;
    n1 = 14, n2 = 8;
    t = findLCA(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 10, n2 = 22;
    t = findLCA(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
    return 0;
}
