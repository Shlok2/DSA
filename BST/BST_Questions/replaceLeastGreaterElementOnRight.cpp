// Replace every element with the least greater element on its right
// Given an array of integers, replace every element with the least greater element on its right side in the array.
// If there are no greater elements on the right side, replace it with -1.
// Input: [8, 58, 71, 18, 31, 32, 63, 92,
//          43, 3, 91, 93, 25, 80, 28]
// Output: [18, 63, 80, 25, 32, 43, 80, 93,
//          80, 25, 93, -1, 28, -1, -1]
// Can refer to codelibrary by Yogesh (YT).

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

// This function insert a node to BST.
// data is to be added.
// Succ is inorder Successor in a BST.
node *insert(node *root, int data, node *&succ)
{
    if (root == NULL)
    {
        return root = new node(data);
    }
    if (root->data > data)
    {
        succ = root;
        root->left = insert(root->left, data, succ);
    }
    else
    {
        root->right = insert(root->right, data, succ);
    }
    return root;
}

void replace(int arr[], int n)
{
    node *root = NULL;

    // We are making BST from back of array.(Check Theory)
    for (int i = n - 1; i >= 0; i--)
    {
        node *succ = NULL;
        root = insert(root, arr[i], succ);
        if (succ)
        {
            arr[i] = succ->data;
        }
        else
        {
            arr[i] = -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92,
                 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    replace(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
