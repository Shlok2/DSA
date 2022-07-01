
// For theory Can refer to GFG.

#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    // next pointer will point to inorder Successor.
    node *next;
    node(int val)
    {
        data = val;
        left = right = next = NULL;
    }
};

// we will use reverse inorder for this question.
//  Hence start will rightmost node->Its pointer will point to Null.
void populateNext(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Inially next = NULL,So when we reach rightmost node,next of that will point to NULL.
    static node *next = NULL;
    populateNext(root->right);
    root->next = next;
    // update value of next to root->So that next of inorder predecessor will point to this node.
    next = root;
    populateNext(root->left);
}

int main(int argc, char const *argv[])
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(12);
    root->left->left = new node(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    node *ptr = root->left->left;
    while (ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1)
             << endl;
        ptr = ptr->next;
    }

    return 0;
}
