
// Check if all leaf are on same level.

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <climits>
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

bool checkSameLeafLevel(node *root)
{

    if (!root)
    {
        return true;
    }
    queue<node *> q;
    q.push(root);
    int result = INT_MAX;
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        level += 1;
        while (size--)
        {
            node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                // if it is a leaf node.
                if (!temp->left->right && !temp->left->left)
                {
                    // if it is the first leaf node->then update result.

                    if (result == INT_MAX)
                    {
                        result = level;
                    }

                    // if it is not a first leaf node->then compare
                    // the level with level of previous leaf node.
                    // if result is not equal to level->return 0.
                    else if (result != level)
                    {
                        return false;
                    }
                }
            }

            if (temp->right)
            {
                q.push(temp->right);
                // if it is a leaf node.
                if (!temp->right->left && !temp->right->right)
                {
                    if (result == INT_MAX)
                    {
                        result = level;
                    }
                    else if (result != level)
                    {
                        return false;
                    }
                }
            }
        }
        size -= 1;
    }
    return true;
}

int main()
{
    node *root = new node(12);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(9);
    root->left->left->left = new node(1);
    root->left->right->left = new node(1);
    root->left->right->left->left = new node(6);
    root->right = new node(3);

    if (checkSameLeafLevel(root))
    {
        cout << "Yes all leaf are on Same level.";
    }
    else
    {
        cout << "No all leaf are not on Same level";
    }
    return 0;
}
