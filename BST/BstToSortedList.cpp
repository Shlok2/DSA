
//  the value of each node must be lesser than
// the values of all the nodes at its right, and its left node must be NULL after flattening.
// Input:
//           5
//         /   \ 
//        3     7
//       / \   / \ 
//      2   4 6   8
// Output: 2 3 4 5 6 7 8

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

void inorder(node *curr, node *&prev)
{
    if (curr == NULL)
    {
        return;
    }
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

node *flatten(node *curr)
{
    node *dummy = new node(-1);
    node *prev = dummy;

    inorder(curr, prev);

    // For last node make both left and right of prev = NULL.
    prev->left = NULL;
    prev->right = NULL;

    // ret pointing to right of dummy node(i.e leftmost node in BST).
    node *ret = dummy->right;

    // Delete dummy node
    delete dummy;
    return ret;
}

void print(node *parent)
{
    node *curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}

int main(int argc, char const *argv[])
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // Calling required function
    print(flatten(root));
    return 0;
}
