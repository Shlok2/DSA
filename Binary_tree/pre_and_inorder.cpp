#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorderprint(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildtree(int inorder[], int preorder[], int start, int end)
{
    // base condition
    if (start > end)
    {
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    node *Node = new node(curr);

    // edge condition
    if (start == end)
    {
        return Node;
    }

    int pos = search(inorder, start, end, curr);
    Node->left = buildtree(inorder, preorder, start, pos - 1);
    Node->right = buildtree(inorder, preorder, pos + 1, end);

    return Node;
}

int main(int argc, char const *argv[])
{
    int inorder[] = {4, 2, 1, 5, 3};
    int preorder[] = {1, 2, 4, 3, 5};
    node *root = buildtree(inorder, preorder, 0, 4);

    // Name of 'inorder' changed to 'inorder' print because we already used inorder name in our question
    inorderprint(root);

    return 0;
}
