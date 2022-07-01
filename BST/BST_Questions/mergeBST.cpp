// To merge 2 BST -> take inorder of both BT's-> Then concatinate both inorder and do sorting of resultant array -> Then make BST from
//  that resultant array.

// But we have to do this same question with "limited space".

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

int main(int argc, char const *argv[])
{

    return 0;
}
