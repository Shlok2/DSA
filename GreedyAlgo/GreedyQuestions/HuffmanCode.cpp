// Refer to GFG Video(YT).
// For basic understand can refer to Abdul Bari(YT).

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct MinHeapNode
{
    char data;

    // unsigned is type of int with only positive values.
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(int val, unsigned val2)
    {
        data = val;
        freq = val2;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str)
{
    if (root == NULL)
    {
        return;
    }

    // If wo '$' nhi he -> matlab wo array me se koi he
    // ({a,b,c,d,e,f}) -> hence wha tak ki string print kra
    // denge.
    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    // Left and right is to store first and second popped elements respectively.
    // Top stores new node with freq of left+ freq of right.
    MinHeapNode *left, *right, *top;

    // To create and store nodes in min heap with value-> date,freq.
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(new MinHeapNode(data[i], freq[i]));
    }

    while (pq.size() != 1)
    {
        // To store values of left right and top.
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main(int argc, char const *argv[])
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);
    return 0;
}
