
// Check GFG for solution(Method 3)(Reccursion Method)(Count Pairs from 2
//  BST whose sum is equal to given value x).

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct node
{
    node *left, *right;
    int data;
    node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

int paircount = 0;

void findPair(node *root2, int diff)
{
    if (root2 == NULL)
    {
        return;
    }
    if (root2->data == diff)
    {
        paircount++;
    }
    if (root2->data < diff)
    {
        findPair(root2->right, diff);
    }
    if (root2->data > diff)
    {
        findPair(root2->left, diff);
    }
}

void sumEqualtox(node *root1, node *root2, int x)
{
    if (root1 == NULL || root2 == NULL)
    {
        return;
    }

    sumEqualtox(root1->left, root2, x);
    sumEqualtox(root1->right, root2, x);
    int diff = x - root1->data;
    findPair(root2, diff);
}

int countPairs(node *root1, node *root2, int x)
{
    sumEqualtox(root1, root2, x);
    return paircount;
}

int main(int argc, char const *argv[])
{
    node *root1 = new node(5);
    root1->left = new node(3);
    root1->right = new node(7);
    root1->left->left = new node(2);
    root1->left->right = new node(4);
    root1->right->left = new node(6);
    root1->right->right = new node(8);

    // formation of BST 2
    node *root2 = new node(10);
    root2->left = new node(6);
    root2->right = new node(15);
    root2->left->left = new node(3);
    root2->left->right = new node(8);
    root2->right->left = new node(11);
    root2->right->right = new node(18);

    int x = 16;
    cout << "No. of Pairs: " << countPairs(root1, root2, x) << endl;
    return 0;
}
