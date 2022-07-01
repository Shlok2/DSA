#include <iostream>
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

node *sortedArraytoBSt(int array[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = newnode(array[mid]);

    root->left = sortedArraytoBSt(array, start, mid - 1);
    root->right = sortedArraytoBSt(array, mid + 1, end);

    return root;
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
    int array[] = {10, 20, 30, 40, 50};
    node *root = sortedArraytoBSt(array, 0, 4);
    preorder(root);
    cout << endl;
    return 0;
}
