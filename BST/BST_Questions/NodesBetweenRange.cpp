// Find number of node between given range.
// eg - Input:
//         10
//       /    \
//     5       50
//    /       /  \
//  1       40   100
// Range: [5, 45]

// Output:  3
// There are three nodes in range, 5, 10 and 40

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

int countNodes(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (n1 <= root->data && root->data <= n2)
    {
        return 1 + countNodes(root->left, n1, n2) + countNodes(root->right, n1, n2);
    }
    if (n1 < root->data && !(root->data <= n2))
    {
        return countNodes(root->left, n1, n2);
    }
    else
    {
        return countNodes(root->right, n1, n2);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(50);
    root->left->left = new node(1);
    root->right->left = new node(40);
    root->right->right = new node(100);
    int n1 = 5;
    int n2 = 45;
    int ans = countNodes(root, n1, n2);
    cout << "No. of nodes between " << n1 << " and " << n2 << " are: " << ans << endl;
    return 0;
}
