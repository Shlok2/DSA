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

// To convert BST to vector.
void BSTtoarr(node *root, vector<node *> &v)
{
    if (root == NULL)
    {
        return;
    }
    BSTtoarr(root->left, v);
    v.push_back(root);
    BSTtoarr(root->right, v);
}

// To make complete BST from vector.
node *arrToCompleteBST(vector<node *> &v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = v[mid];
    root->left = arrToCompleteBST(v, start, mid - 1);
    root->right = arrToCompleteBST(v, mid + 1, end);
    return root;
}

// First we push elements (nodes) of BST to vector.
// then we make a complete BST from vector.
node *BSTtoCompleteBST(node *root)
{
    vector<node *> v;
    BSTtoarr(root, v);
    int n = v.size();
    return arrToCompleteBST(v, 0, n - 1);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char const *argv[])
{
    node *root = new node(10);
    root->left = new node(8);
    root->left->left = new node(7);
    root->left->left->left = new node(6);
    root->left->left->left->left = new node(5);
    root = BSTtoCompleteBST(root);
    cout << "Preorder traversal of balanced BST is: " << endl;
    preorder(root);
    return 0;
}
