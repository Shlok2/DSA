#include <bits/stdc++.h>
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

void Zigzag(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> currlevel;
    stack<node *> nextlevel;
    bool lefttoright = true;
    currlevel.push(root);

    while (!currlevel.empty())
    {
        node *temp = currlevel.top();
        currlevel.pop();
        if (temp != NULL)
        {
            cout << temp->data << " ";
            if (lefttoright = true)
            {
                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }
            }

            // if lefttoright = false (i.e. righttoleft)
            else
            {
                if (temp->right != NULL)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if (currlevel.empty())
        {
            // reverse lefttoright
            lefttoright = !lefttoright;
            swap(currlevel, nextlevel);
        }
    }
}

int main(int argc, char const *argv[])
{
    node *root = newnode(12);
    root->left = newnode(9);
    root->right = newnode(15);
    root->left->left = newnode(5);
    root->left->right = newnode(10);
    Zigzag(root);
    cout << endl;
    return 0;
}
