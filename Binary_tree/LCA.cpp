#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// node *newnode(int val)
// {
//     node *temp = new node;
//     temp->data = val;
//     temp->right = temp->left = NULL;
//     return temp;
// }

node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    // if root is one of n1 or n2 then it will be the only one to be LCA.
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftLCA = LCA(root->left, n1, n2);
    node *rightLCA = LCA(root->right, n1, n2);

    // if we get both left and right LCA from subtree of root, then if must be a LCA.
    if (leftLCA && rightLCA)
    {
        return root;
    }
    // if leftLCA is not null -> then return leftLCA.
    if (leftLCA)
    {
        return leftLCA;
    }
    // if rightLCA is not null -> then return rightLCA.
    return rightLCA;
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    int n1 = 7;
    int n2 = 6;
    node *lca = LCA(root, n1, n2);
    if (LCA == NULL)
    {
        cout << "LCA doesn't exist";
    }
    else
    {
        cout << lca->data << endl;
    }
    return 0;
}
