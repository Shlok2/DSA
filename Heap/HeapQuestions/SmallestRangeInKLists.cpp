
// Can refer to video of Aditya RAjiv (YT).

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Atleast one element is between range of output -> eg - 24 from arr1 , 20 from arr2 , 22 from arr3.

#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class element
{
public:
    int value;
    int index;
    int row;
    int arrsize;

    element(int val, int indexnumber, int rownumber, int arraysize)
    {
        value = val;
        index = indexnumber;
        row = rownumber;
        arrsize = arraysize;
    }
};

struct compare
{
    bool operator()(element a, element b)
    {
        return a.value > b.value;
    }
};

vector<int> smallestRange(vector<vector<int>> &arr)
{
    int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
    priority_queue<element, vector<element>, compare> q;
    int k = arr.size();
    int low, high;
    for (int i = 0; i < k; i++)
    {
        q.push(element(arr[i][0], 0, i, arr[i].size()));
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][0]);
    }
    while (!q.empty())
    {
        element temp = q.top();
        q.pop();
        int maybeminimum = temp.value;

        // if curr max - maybeminimum is lesser than range -> then update
        // range.
        if (range > mx - maybeminimum)
        {
            mn = maybeminimum;
            range = mx - mn;
            low = mn;
            high = mx;
        }

        // if it (temp.index) is at last position of its own array->
        // then break the loop as curr range will be the ans and any
        // other range is not possible.
        if (temp.index == temp.arrsize - 1)
        {
            break;
        }

        temp.index += 1;
        q.push(element(arr[temp.row][temp.index], temp.index, temp.row, arr[temp.row].size()));
        mx = max(mx, arr[temp.row][temp.index]);
    }
    vector<int> v{low, high};
    return v;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec{{4, 10, 15, 24, 26},
                            {0, 9, 12, 20},
                            {5, 18, 22, 30}};
    vector<int> vc = smallestRange(vec);
    cout << "The range is: " << endl;
    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }

    return 0;
}
