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

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        // for n = 3 -> C0C2 + C1C1 + C2C0
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

vector<node *> constructTrees(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftsubtree = constructTrees(start, i - 1);
        vector<node *> rightsubtree = constructTrees(i + 1, end);
        for (int j = 0; j < leftsubtree.size(); j++)
        {
            node *left = leftsubtree[j];
            for (int k = 0; k < rightsubtree.size(); k++)
            {
                node *right = rightsubtree[k];
                node *Node = newnode(i);
                Node->left = left;
                Node->right = right;
                trees.push_back(Node);
            }
        }
    }
    return trees;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char const *argv[])
{
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << catalan(i) << " ";
    // }
    // cout << endl;
    vector<node *> totaltrees = constructTrees(1, 3);
    for (int i = 0; i < totaltrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(totaltrees[i]);
        cout << endl;
    }
    return 0;
}
