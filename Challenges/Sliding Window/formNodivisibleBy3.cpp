#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void formNumberDivBy3(vector<int> arr, int k)
{
    // This ans store the starting and ending index of our sliding window.
    pair<int, int> ans;
    int sum = 0;

    // sum = sum of first k elements.
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    // initially we haven't found our ans->hence found = false.
    bool found = false;

    // if first k elements sum is divisible by 3 -> then 0->k-1 will be the
    // sliding window(hence ans).
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    // if initial k element sum is not divisible by 3 -> then we will do
    // sliding window.
    for (int j = k; j < arr.size(); j++)
    {

        // if we already found the no. divisible by 3 -> then we break form this
        // loop.
        if (found)
        {
            break;
        }

        sum = sum - arr[j - k] + arr[j];

        // again check sum after updating.
        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "No such array exists." << endl;
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;
    formNumberDivBy3(arr, k);
    return 0;
}
