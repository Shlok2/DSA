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

void inorderSuccessorPredecessor(node *root, int key, node *&pre, node *&succ)
{

    if (root == NULL)
    {
        return;
    }

    if (root->data == key)
    {

        // Max value in leftSubtree is predecessor.
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }

        // Min value in rightSubtree is successor.
        if (root->right)
        {
            node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }

    if (root->data < key)
    {
        pre = root;
        inorderSuccessorPredecessor(root->right, key, pre, succ);
    }
    else
    {
        succ = root;
        inorderSuccessorPredecessor(root->left, key, pre, succ);
    }
}

node *insertBST(node *root, int k)
{
    if (root == NULL)
    {
        return new node(k);
    }
    if (k > root->data)
    {
        root->right = insertBST(root->right, k);
    }
    else
    {
        root->left = insertBST(root->left, k);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    int key = 65;
    node *pre = NULL;
    node *succ = NULL;
    inorderSuccessorPredecessor(root, key, pre, succ);
    cout << "Predecessor: " << pre->data << endl;
    cout << "Successor: " << succ->data << endl;
    return 0;
}
