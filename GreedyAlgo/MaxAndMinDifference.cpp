#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long min = 0, max = 0;
    for (int i = 0; i < n / 2; i++)
    {
        // sum of last n/2 elements - sum of first n/2 elements.
        max += (a[i + n / 2] - a[i]);

        // (sum of odd elements - sum of even elements).
        min += (a[2 * i + 1] - a[2 * i]);
    }

    cout << min << " " << max;

    return 0;
}
