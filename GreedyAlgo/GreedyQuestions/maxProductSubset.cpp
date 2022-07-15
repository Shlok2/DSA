#include <iostream>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    if (a >= 0 && b >= 0)
    {
        return a > b;
    }
    else if (a < 0 && b < 0)
    {
        return a < b;
    }
}

int maxProductSubset(int arr[], int n)
{
    // if there are 2 -ve then we can multiply them
    // to get positive and then include them both to ans.
    int count = 0;
    // To store -ve no.
    stack<int> s;

    sort(arr, arr + n, comp);
    // Array after sorting -> 4 ,3 ,2,-1,-1.
    // m->first element.
    int m = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        if (arr[i] > 0)
        {
            m = m * arr[i];
        }
        if (arr[i] < 0)
        {
            s.push(arr[i]);
            count++;
            if (count % 2 == 0)
            {
                while (!s.empty())
                {
                    m = m * s.top();
                    s.pop();
                }
            }
        }
    }
    return m;
}

int main(int argc, char const *argv[])
{
    int a[] = {-1, -1, -2, 4, 3};
    // int a[] = {-1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n) << endl;
    return 0;
}
