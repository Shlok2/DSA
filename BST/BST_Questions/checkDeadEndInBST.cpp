
// Dead End means, we are not able to insert any element after that node.
// Input :       8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : Yes
// Explanation : We can't insert any element at
//               node 9.

#include <iostream>
#include <string.h>
#include <unordered_set>
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

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void storeNode(node *root, unordered_set<int> &all_nodes, unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
    {
        return;
    }

    // Store every node in unordered set all_nodes.
    all_nodes.insert(root->data);

    // Insert leaf node in unordered set leaf_nodes.
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }

    storeNode(root->left, all_nodes, leaf_nodes);
    storeNode(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(node *root)
{
    // If root is NULL.It cannot be a dead end.
    if (root == NULL)
    {
        return false;
    }

    unordered_set<int> leaf_nodes, all_nodes;

    // for edge case is BST consists 1.
    all_nodes.insert(0);
    storeNode(root, all_nodes, leaf_nodes);

    // To traverse leaf node unordered set.
    for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
    {
        // Store data at i th index in unordered set to x.
        int x = (*i);

        // If all_nodes unordered set has x+1 and x-1 -> then return true , otherwise
        // return false after loop.
        if (all_nodes.find(x + 1) != all_nodes.end() && all_nodes.find(x - 1) != all_nodes.end())
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
