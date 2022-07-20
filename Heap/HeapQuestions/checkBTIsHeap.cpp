#include <iostream>
#include <string.h>
#include <queue>
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

int size(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

// Given a binary tree, we need to check it has heap property or not, Binary tree need to fulfill the following two conditions for being a heap –

//   1)  It should be a complete tree (i.e. all levels except last should be full).
//   2)  Every node’s value should be greater than or equal to its child node (considering max-heap).
bool checkHeap(node *root, int n, int index)
{
    if (root == NULL)
    {
        return 1;
    }

    // Condition 1) - This condition is used to check if tree is complete or not.
    // n is size of BT and if index(2*i+1 || 2*i+2) > n -> return false-> as
    // index cannot be greater than size of BT.
    if (index >= n)
    {
        return 0;
    }

    // Condition 2) - To check if it is heap or not.
    if ((root->left && root->left->data >= root->data) || (root->right && root->right->data >= root->data))
    {
        return 0;
    }
    return checkHeap(root->left, n, 2 * index + 1) && checkHeap(root->right, n, 2 * index + 2);
}

bool isheap(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int n = size(root);
    int index = 0;
    if (checkHeap(root, n, index))
    {
        return 1;
    }
    return 0;
}

// (Method 2)->(Iterative(using Level order Traversal))

//     bool checkBTisHeap(node *root)
// {
//     queue<node *> q;
//     q.push(root);
//     bool nullish = false;
//     while (!q.empty())
//     {

//         node *temp = q.front();
//         q.pop();

//         if (temp->left)
//         {
//             // If nullish is true that means it dont have either left
//             // or right subtree -> Hence it is not a complete tree ->
//             // Hence it cannot be heap.
//             if (nullish || temp->data <= temp->left->data)
//             {
//                 return false;
//             }
//             q.push(temp->left);
//         }
//         else
//         {
//             nullish = true;
//         }
//         if (temp->right)
//         {
//             if (nullish || temp->data <= temp->right->data)
//             {
//                 return false;
//             }
//             q.push(temp->right);
//         }
//         else
//         {
//             nullish = true;
//         }
//     }
//     return true;
// }

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    root = new node(10);
    root->left = new node(9);
    root->right = new node(8);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);
    root->left->left->left = new node(3);
    root->left->left->right = new node(2);
    root->left->right->left = new node(9);

    // Function call
    if (isheap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
    return 0;
}