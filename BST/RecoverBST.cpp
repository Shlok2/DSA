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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointer(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calcPointer(root->left, first, mid, last, prev);

    // property violates. because root->data should always be greater than prev ka data.
    if (*prev && root->data < (*prev)->data)
    {
        // if property voilates first time then first is NULL.
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, prev, mid, last, prev);
}

void recoverBST(node *root)
{
    // prev is like a temp pointer.
    node *prev, *first, *mid, *last;
    first = mid = last = prev = NULL;

    calcPointer(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(int argc, char const *argv[])
{
    node *root = newnode(6);
    root->left = newnode(9);
    root->right = newnode(3);
    root->left->left = newnode(1);
    root->left->right = newnode(4);
    root->right->right = newnode(13);

    inorder(root);
    cout << endl;
    recoverBST(root);
    inorder(root);
    cout << endl;
    return 0;
}
