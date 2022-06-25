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

void rightview(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        // n is number of nodes in one level (not total nodes).
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            // take q ka front in curr variable.
            node *curr = q.front();
            q.pop();

            // when i = n-1 -> means it is last(most right) node of a level.Hence, print it!
            if (i == n - 1)
            {

                cout << curr->data << " ";
            }

            // if left child is not null -> push it to queue.
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            // if right child is not null -> push it to queue.
            if (curr->right != NULL)
            {
                q.push(curr->right);
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
    rightview(root);
    return 0;
}
