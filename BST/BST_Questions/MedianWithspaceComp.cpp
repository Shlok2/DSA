
// If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
// If no. of nodes are odd : then median = (n+1)/2th node.

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

node *insert(struct node *Node, int key)
{
    /* If the tree is empty, return a new node */
    if (Node == NULL)
        return new node(key);

    /* Otherwise, recur down the tree */
    if (key < Node->data)
        Node->left = insert(Node->left, key);
    else if (key > Node->data)
        Node->right = insert(Node->right, key);

    /* return the (unchanged) node pointer */
    return Node;
}

// This function is almost similar to Morris Inorder Traversal
// and it is used to find number of nodes in a BT.
int morrisInorderCount(node *root)
{
    node *curr, *pre;

    int count = 0;
    if (root == NULL)
    {
        return count;
    }

    curr = root;

    while (curr != NULL)
    {

        // Case 1-> if curr ->left is NULL then print curr->data
        //  and move curr to curr->right.
        if (curr->left == NULL)
        {
            count++;
            curr = curr->right;
        }

        else
        {
            pre = curr->left;
            // Case 2 -> move to rightmost root of curr->left(pre).
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            // Make pre->right point to curr and do curr = curr->left.
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }

            // If thread already exists -> then remove thread , print curr->data
            // and move curr = curr->right.
            else
            {
                pre->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

int findMedian(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = morrisInorderCount(root);
    int currcount = 0;
    node *curr = root, *pre, *prev;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {

            currcount++;
            if (count % 2 != 0 && currcount == (count + 1) / 2)
            {
                return prev->data;
            }

            else if (count % 2 == 0 && currcount == (count / 2) + 1)
            {
                return (curr->data + prev->data) / 2;
            }
            // update prev for even no. of nodes.
            prev = curr;

            curr = curr->right;
        }

        else
        {
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }

            else
            {
                pre->right = NULL;
                prev = pre;
                currcount++;
                if (count % 2 != 0 && currcount == (count + 1) / 2)
                {
                    return curr->data;
                }

                else if (count % 2 == 0 && currcount == (count / 2) + 1)
                {
                    return (curr->data + prev->data) / 2;
                }
                // update prev for even no. of nodes.
                prev = curr;
                curr = curr->right;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}
