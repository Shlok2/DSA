// Explanation of this is in my question copy and can also refer to
// take U forward (YT).
// Morris Inorder is used to print inorder of a tree in space complexity
// of O(n).

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

void morrisInorderTraversal(node *root)
{
    node *curr, *pre;

    if (root == NULL)
    {
        return;
    }

    curr = root;

    while (curr != NULL)
    {

        // Case 1-> if curr ->left is NULL then print curr->data
        //  and move curr to curr->right.
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }

        if (curr->left != NULL)
        {
            pre = curr->left;
            // Case 2 -> move to rightmost root of curr->left(pre).
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            // Make pre->right point to curr and do curr = curr->left.
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }

            // If thread already exists -> then remove thread , print curr->data
            // and move curr = curr->right.
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    morrisInorderTraversal(root);
    return 0;
}
