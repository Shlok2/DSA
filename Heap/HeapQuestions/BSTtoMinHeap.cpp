#include <iostream>
#include <string.h>
#include <vector>
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

// Convert bst to inorder array and store it in vector.
void bstToArray(node *root, vector<int> &v)
{

    if (root == NULL)
    {
        return;
    }
    bstToArray(root->left, v);
    v.push_back(root->data);
    bstToArray(root->right, v);
}

void arrayToHeap(node *root, vector<int> &v, int &i)
{
    if (root == NULL)
    {
        return;
    }
    root->data = v[i];
    i++;
    arrayToHeap(root->left, v, i);
    arrayToHeap(root->right, v, i);
}

node *bstToHeap(node *root)
{
    vector<int> v;
    int i = 0;
    bstToArray(root, v);
    arrayToHeap(root, v, i);
    return root;
}

void preorderTraversal(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    preorderTraversal(root->left);

    preorderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    bstToHeap(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
    return 0;
}
