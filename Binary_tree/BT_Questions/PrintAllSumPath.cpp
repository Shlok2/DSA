
// Print all "k" Sum Path in binary tree.
// If cannot able to understand by code -> can refer to GFG "Video" Solution.

#include <iostream>
#include <string.h>
#include <vector>
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

void printVector(const vector<int> &path, int i)
{
    for (int j = i; j < path.size(); j++)
    {
        cout << path[j] << " ";
    }
    cout << endl;
}

// take vector by reference.
void PrintAllSumPath(node *root, vector<int> &path, int k)
{
    if (root == NULL)
    {
        return;
    }

    // Add curr node to vector(Path).
    path.push_back(root->data);

    // Check for k sum path in left and right subtree.
    PrintAllSumPath(root->left, path, k);
    PrintAllSumPath(root->right, path, k);

    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--)
    {
        f += path[j];

        // If path sum = k ->print all those nodes which sums up to k.
        if (f == k)
        {
            printVector(path, j);
        }
    }
    // remove curr element from path.
    path.pop_back();
}

void PrintKPath(node *root, int k)
{
    vector<int> path;
    PrintAllSumPath(root, path, k);
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);

    int k = 5;
    PrintKPath(root, k);

    return 0;
}
