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

node *TreeFromString(string s, int *start)
{
    if (s.size() == 0 || *start >= s.size())
    {
        return NULL;
    }

    int num = 0;
    // This is for a 2 digit numbers.
    while (s[*start] != '(' && s[*start] != ')' && s.size() > *start)
    {
        // below statement is used to store s[*start] to num_here variable.
        // eg- char '9' will be converted to 9 and will be stored in num_here.
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }

    // Make node of the number from above.
    node *root = new node(num);

    // If it is a opening bracket.
    if (s[*start] == '(' && *start < s.size())
    {
        *start = *start + 1;
        root->left = TreeFromString(s, start);
    }

    // If it is a closing bracket.
    if (s[*start] == ')' && *start < s.size())
    {
        *start = *start + 1;
    }

    // As soon as we see second right parenthesis from the
    // current node, we start to construct the tree in the
    // right

    if (s[*start] == '(' && *start < s.size())
    {
        *start = *start + 1;
        root->right = TreeFromString(s, start);
    }
    if (s[*start] == ')' && *start < s.size())
    {
        *start = *start + 1;
    }

    return root;
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
    string s = "4(2(3)(1))(6(5))";
    int start = 0;
    node *root = TreeFromString(s, &start);
    preorder(root);
    return 0;
}
