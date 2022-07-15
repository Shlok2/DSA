// Chocolate Distribution Problem
// Given an array of n integers where each value represents
// the number of chocolates in a packet.Each packet can have
// a variable number of chocolates.There are m students, the
// task is to distribute chocolate packets such that :

// Each student gets one packet.The difference between the
// number of chocolates in the packet with maximum chocolates
// and packet with minimum chocolates given to the students
// is minimum.

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int findMinDiff(int arr[], int n, int m)
{
    sort(arr, arr + n);
    // array -> 2,3,4,7,9,12,56
    priority_queue<int, vector<int>, greater<int>> pq;

    // To run loop from 0 to n-m(7-3) -> So that we can get
    // next m elements.
    for (int i = 0; i <= n - m; i++)
    {
        int ans = arr[i + m - 1] - arr[i];
        pq.push(ans);
    }
    // min pq will store smallest ans at top.
    int a = pq.top();
    return a;
}

int main(int argc, char const *argv[])
{
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int m = 3; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}

// Given an array of n integers where each value represents the number of chocolates in a packet. Each packet
// can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

// 1) Each student gets one packet.
// 2) The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum
//  chocolates given to the students is minimum.
//
// Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
// Output: Minimum Difference is 2
// Explanation:
// We have seven packets of chocolates and
// we need to pick three packets for 3 students
// If we pick 2, 3 and 4, we get the minimum
// difference between maximum and minimum packet
// sizes.
