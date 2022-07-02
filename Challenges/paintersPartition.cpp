#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0, painter = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > limit)
        {
            sum = boards[i];
            painter++;
        }
    }
    return painter;
}

int paintersPartition(int boards[], int n, int m)
{
    // totallength will store sum of all values in boards.And k will store
    // the max value in boards array.
    int totallength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        totallength += boards[i];
        k = max(k, boards[i]);
    }
    int low = k, high = totallength;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = findFeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout << paintersPartition(arr, n, m);
    return 0;
}
