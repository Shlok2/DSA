#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
struct node
{
    int no;
    int freq;
    node(int a, int b)
    {
        no = a;
        freq = b;
    }
};

struct compare
{
    bool operator()(node const &a, node const &b)
    {
        return a.freq < b.freq;
    }
};

vector<int> topKFreq(vector<int> &num, int n, int k)
{
    unordered_map<int, int> m;

    // Storing vector frequencies to map.
    for (int i = 0; i < n; i++)
    {
        m[num[i]]++;
    }

    // pushing map to heap by heap of nodes(value,frequencies).
    priority_queue<node, vector<node>, compare> heap;
    for (auto it : m)
    {
        heap.push(node(it.first, it.second));
    }

    // while k != 0 -> popping top element of heap and storing
    // top->no to ans.
    vector<int> ans;
    while (k--)
    {
        node temp = heap.top();
        heap.pop();
        ans.push_back(temp.no);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> num = {1, 2, 3, 2, 1, 1};
    vector<int> a = topKFreq(num, 6, 2);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
