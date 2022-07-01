#include <bits/stdc++.h>
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
// preorderInx -> preorder index.It indicates the current pos in preorder.
//  n = total number of elements in preorder(Size of preorder).
node *constructpreorder(int preorder[], int *preorderInx, int key, int min, int max, int n)
{
    // Base case
    if (*preorderInx >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (key > min && key < max)
    {
        root = newnode(key);
        *preorderInx = *preorderInx + 1;
        if (*preorderInx < n)
        {
            // root->left should be smaller than root. Hence, max will be key ,as root is equal to key.
            root->left = constructpreorder(preorder, preorderInx, preorder[*preorderInx], min, key, n);
        }
        if (*preorderInx < n)
        {
            // root->right should be greater than root.Hence, min will be key,as root is equal to key.
            root->right = constructpreorder(preorder, preorderInx, preorder[*preorderInx], key, max, n);
        }
    }
    return root;
}

void printpreorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main(int argc, char const *argv[])
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    node *root = constructpreorder(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printpreorder(root);
    return 0;
}
