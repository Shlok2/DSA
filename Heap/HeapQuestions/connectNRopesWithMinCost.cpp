
// For example, if we are given 4 ropes of lengths 4, 3, 2, and 6. We can connect the ropes in the following ways.
// 1) First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5.
// 2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
// 3) Finally connect the two ropes and all ropes have connected.
// Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other
// ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get
// three strings of 3, 2, and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally, we connect 13
// and 2. Total cost in this way is 10 + 13 + 15 = 38.

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int minCost(int arr[], int n)
{
    // Sortcut for below is -
    // priority_queue<int,vector<int>,greater<int>> pq(arr,arr + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int res = 0;
    // pq will never get empty as we are always pushing first + second
    // in pq -> so when pq have only one element we will leave this loop
    // and return the final answer.
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Total cost for connecting ropes is " << minCost(arr, n);

    return 0;
}
