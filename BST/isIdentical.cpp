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

bool isIdentical(node *root1, node *root2)
{
    // to check if both root1 and root2 are empty(NULL). then structure of both bst is same and value NULL.
    //  Hence return true.
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    // if one of 2 roots is NULL and other don't , then structure of bst is different.
    //  Hence return false.
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    // if both roots are not null then check for conditions.
    else
    {
        bool cond1 = root1->data = root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        // if all three conditions are true then return true, else return false.
        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}

int main(int argc, char const *argv[])
{
    node *root = newnode(2);
    root->left = newnode(1);
    root->right = newnode(3);

    node *root2 = newnode(2);
    root->left = newnode(1);
    root->right = newnode(4);

    if (isIdentical(root, root))
    {
        cout << "BST's are identical." << endl;
    }
    else
    {
        cout << "BST's not identical." << endl;
    }

    if (isIdentical(root, root2))
    {
        cout << "BST's are identical." << endl;
    }
    else
    {
        cout << "BST's not identical." << endl;
    }
    return 0;
}
