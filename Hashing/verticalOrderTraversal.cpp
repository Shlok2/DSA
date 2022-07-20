#include <iostream>
#include <string.h>
#include <map>
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

// hd is horizontal distance.
void getVerticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    // To push 'value' of root to 'key' of m.
    // eg - at starting push 10(root->data) to m[0] where 0 is 'key'.
    m[hd].push_back(root->data);

    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

int main(int argc, char const *argv[])
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(6);

    map<int, vector<int>> m;

    // hd is horizontal distance.
    int hd = 0;
    getVerticalOrder(root, hd, m);

    map<int, vector<int>>::iterator it;

    // We only have to print vector(value).
    for (it = m.begin(); it != m.end(); it++)
    {
        // (it->second)size() -> represent size of vector at it->second.
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
