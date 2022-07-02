#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            sum = sum + p;
        }

        if (n > 1)
        {
            if (n % 2 == 0)
            {
                ans = sum / 2;
                // cout << ans << endl;
            }
            else
            {
                ans = sum / 2 + 1;
            }
        }
        else
        {
            ans = sum;
        }
        cout << ans << endl;
    }
    return 0;
}
