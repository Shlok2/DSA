#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    return max(lheight, rheight) + 1;
}

int calcdiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // when diameter is passing through root.
    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    int currdiameter = lheight + rheight + 1;

    // when diameter is not passing by root and is in left side of root.
    int ldiameter = calcdiameter(root->left);
    // when diameter is not passing by root and is in right side of root.
    int rdiameter = calcdiameter(root->right);

    // maxdiameter should be one of ldiameter,rdiameter,currdiameter. Hence we use
    // max function.
    return max(currdiameter, max(ldiameter, rdiameter));
}

int main(int argc, char const *argv[])
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << calheight(root) << endl;
    cout << calcdiameter(root);
    return 0;
}
