#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int minCost(int arr[], int n)
{
    sort(arr, arr + n);
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() != 1)
    {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        int s = s1 + s2;
        pq.push(s);
        ans += s;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
