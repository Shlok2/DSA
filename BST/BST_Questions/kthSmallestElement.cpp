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

// For theory -> See kthLargestElement.cpp.
void kthSmallest(node *root, int k, int &c)
{
    if (root == NULL || c >= k)
    {
        return;
    }
    kthSmallest(root->left, k, c);
    c++;
    if (c == k)
    {
        cout << "Kth smallest node is: " << root->data << endl;
    }
    kthSmallest(root->right, k, c);
}

void kthSmallestNode(node *root, int k)
{
    int c = 0;
    kthSmallest(root, k, c);
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
        kthSmallestNode(root, k);
    return 0;
}
