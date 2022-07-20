// if the given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e.,
// k = 3 then your program should print 50, 30, and 23.

#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int kthLargestElement(vector<int> v, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int kthSmallestElement(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    for (int i = 0; i < k; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    kthLargestElement(v, k);
    cout << endl;
    kthSmallestElement(v, k);
    return 0;
}
