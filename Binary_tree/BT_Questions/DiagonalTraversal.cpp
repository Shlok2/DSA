#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
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

vector<vector<int>> result;
void DiagonalTraversal(node *root)
{
    // result is the final answer.
    // answer is a incomplete answer which will push to result again and again.
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> answer;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();
            while (temp)
            {
                answer.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}

int main(int argc, char const *argv[])
{
    node *root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);

    DiagonalTraversal(root);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << "  ";
        cout << endl;
    }
    return 0;
}
