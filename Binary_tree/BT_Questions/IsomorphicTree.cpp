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

bool isIsomorphic(node *n1, node *n2)
{
    if (n1 == NULL && n2 == NULL)
    {
        return true;
    }
    if (n1 == NULL || n2 == NULL)
    {
        return false;
    }
    if (n1->data != n2->data)
    {
        return false;
    }

    // There are two cases for isomorphic condition ->
    //  1)Subtree rooted at these nodes are not flipped.
    //  2)Subtree rooted at these nodes are filpped.
    return (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
           (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}

int main(int argc, char const *argv[])
{
    struct node *n1 = new node(1);
    n1->left = new node(2);
    n1->right = new node(3);
    n1->left->left = new node(4);
    n1->left->right = new node(5);
    n1->right->left = new node(6);
    n1->left->right->left = new node(7);
    n1->left->right->right = new node(8);

    struct node *n2 = new node(1);
    n2->left = new node(3);
    n2->right = new node(2);
    n2->right->left = new node(4);
    n2->right->right = new node(5);
    n2->left->right = new node(6);
    n2->right->right->left = new node(8);
    n2->right->right->right = new node(7);

    if (isIsomorphic(n1, n2))
    {
        cout << "Yes,It is Isomorphic";
    }
    else
    {
        cout << "No,It is not Isomorphic";
    }
    return 0;
}
