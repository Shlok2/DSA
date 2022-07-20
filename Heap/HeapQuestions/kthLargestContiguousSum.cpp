
// For reference can refer to video of Apt4u
// Heap:kth largest sum in a contiguous subarray.

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int kthLargestSum(int arr[], int n, int k)
{
    vector<int> x;
    int sum = 0;

    // min heap.
    priority_queue<int, vector<int>, greater<int>> pq;

    // This loop will create an array with sum of all subarrays.
    // Eg - array - 20,-5,-1.
    // All possible subarray sums are -
    // 20 , 20-5 , 20-5-1. -> 20,15,14
    // -5,-5-1             -> -5,-6
    // -1.                 -> -1
    for (int i = 0; i < n - 1; i++)
    {

        // to push element itself to vector.
        // like - 20,-5.(not -1 as loop from 0 -> n-2)
        x.push_back(arr[i]);
        sum = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            // This sum add all further elements to sum.
            // eg -> 20 -5 -1 , -5 -1.
            sum += arr[j];
            x.push_back(sum);
        }
    }
    // Since loop is from 0 -> n-2 ,last element will not be added.
    // Hence push it after loop.
    x.push_back(arr[n - 1]);
    // Hence final vector x-> 20,15,14,-5,-6,-1.

    for (int i = 0; i < x.size(); i++)
    {
        // After this loop pq will have -> 20,15,14.(if k = 3)
        // Also as pq is a min heap -> 14,15,20.(14->top).
        if (pq.size() < k)
        {
            pq.push(x[i]);
        }

        // if pq.size() == k.
        else
        {
            if (pq.top() < x[i])
            {
                pq.pop();
                pq.push(x[i]);
            }
        }
    }
    // Now pq.top() will be kth largest sum in contiguous subarray.
    return pq.top();
}

int main(int argc, char const *argv[])
{
    int arr[] = {20, -5, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(arr, n, k);
    return 0;
}
