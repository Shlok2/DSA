
// On Logic of Binary Search (#2)

#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    // studentRqquired check for given min , how many students are required.
    int studentsRequired = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }

        // if current element + current sum > min -> then we try to increase current min.
        // hence we cannot give this book to current student. Hence we have to increase
        // student (student ++).

        if (sum + arr[i] > min)
        {
            studentsRequired++;
            sum = arr[i];

            // if studentsRequired is greater than m(given students). then we have to return false.
            if (studentsRequired > m)
            {
                return false;
            }
        }
        // if we can give this book also to student(sum + arr[i]<min) -> then we will simply
        // add current element to sum.
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int allocate_min_pages(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    // end is the sum of all elements of array.
    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            // to check left part of mid.
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << allocate_min_pages(arr, n, m);
    return 0;
}
