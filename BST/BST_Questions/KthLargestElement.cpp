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

// First we do reverse inorder traversal.
//  and one we reach rightmost(largest) element we increase the
//  c by 1 when we go back to parent.->once c equals k that means
//  that we reached our kth largest element.
// (* Remember that largest element in BST is rightmost and when we
// move leftwards it means we are reducing the element data.)
void kthElement(node *root, int k, int &c)
{
    if (root == NULL || c >= k)
    {
        return;
    }
    kthElement(root->right, k, c);
    // k--;
    // if (k == 0) or
    c++;
    if (c == k)
    {
        cout << "This is the kth largest node: " << root->data << endl;
        return;
    }
    kthElement(root->left, k, c);
}

node *insert(node *Node, int key)
{
    /* If the tree is empty, return a new node */
    if (Node == NULL)
        return new node(key);

    /* Otherwise, recur down the tree */
    if (key < Node->data)
        Node->left = insert(Node->left, key);
    else if (key > Node->data)
        Node->right = insert(Node->right, key);

    /* return the (unchanged) node pointer */
    return Node;
}

void kthLargest(node *root, int k)
{
    int c = 0;
    kthElement(root, k, c);
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int c = 0;
    for (int k = 1; k <= 7; k++)
        kthLargest(root, k);
    return 0;
}
