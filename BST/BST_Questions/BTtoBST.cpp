#include <iostream>
#include <string.h>
#include <algorithm>
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

// To convert BT to array.
void BTtoArray(node *root, int inorder[], int *index_ptr)
{
    if (root == NULL)
    {
        return;
    }
    BTtoArray(root->left, inorder, index_ptr);

    // initially index_ptr is 0;
    inorder[*index_ptr] = root->data;
    (*index_ptr)++;
    BTtoArray(root->right, inorder, index_ptr);
}

// This function will count number of nodes in BT.
int countNode(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}

// To Convert array(sorted) to BST.
void arrToBST(node *root, int inorder[], int *index_ptr)
{
    if (root == NULL)
    {
        return;
    }
    arrToBST(root->left, inorder, index_ptr);

    // initially index_ptr is 0;
    root->data = inorder[*index_ptr];
    (*index_ptr)++;
    arrToBST(root->right, inorder, index_ptr);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// This method is based on feature that inorder of a BST is in asscending order.
// Hence we first convert BT into array->Then sort that array->And finally
// convert that array to BT(i.e.It will be BST).
node *BTtoBST(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // To store BT to array.
    int n = countNode(root);
    int *inorder = new int(n);
    int i = 0;
    BTtoArray(root, inorder, &i);

    // To sort array.
    qsort(inorder, n, sizeof(inorder[0]), compare);

    // To make BST from sorted array.
    i = 0;
    arrToBST(root, inorder, &i);
    delete[] inorder;
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << " " << node->data;

    /* now recur on right child */
    printInorder(node->right);
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure
        10
        / \
       30 15
       /    \
     20      5 */
    root = new node(10);
    root->left = new node(30);
    root->right = new node(15);
    root->left->left = new node(20);
    root->right->right = new node(5);
    BTtoBST(root);
    cout << "Inorder of convered array is: " << endl;
    printInorder(root);
    return 0;
}
