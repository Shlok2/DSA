#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void zigzagTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> currlevel;
    stack<node *> nextlevel;
    currlevel.push(root);
    bool lefttoright = true;

    while (!currlevel.empty())
    {
        node *temp = currlevel.top();
        currlevel.pop();
        if (temp != NULL)
        {
            cout << temp->data;

            if (lefttoright == true)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }

            // else right to left
            else
            {
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }

            if (currlevel.empty())
            {
                lefttoright = !lefttoright;
                swap(currlevel, nextlevel);
            }
        }
    }
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
    zigzagTraversal(root);
    cout << endl;
    return 0;
}
