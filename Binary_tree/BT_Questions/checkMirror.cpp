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

bool checkMirror(node *a, node *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }

    if (a == NULL || b == NULL)
    {
        return false;
    }

    if (a->data == b->data && checkMirror(a->left, b->right) && checkMirror(a->right, b->left))
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    node *a = new node(1);
    node *b = new node(1);

    a->left = new node(2);
    a->right = new node(3);
    a->left->left = new node(4);
    a->left->right = new node(5);

    b->left = new node(3);
    b->right = new node(2);
    b->right->left = new node(5);
    b->right->right = new node(4);

    checkMirror(a, b) ? cout << "Yes" : cout << "No";
    return 0;
}
