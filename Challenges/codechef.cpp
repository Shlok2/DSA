// #include <iostream>
// #include <string.h>
// #include <algorithm>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, x;
//         int a[n];
//         cin >> n >> x;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         int sum = 0;
//         int count = 0;
//         sort(a, a + n);
//         for (int i = n - 1; i >= 0; i--)
//         {
//             sum += a[i];
//             count++;
//             if (sum >= x)
//             {
//                 break;
//             }
//         }
//         if (sum > x)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << count << endl;
//         }
//     }
//     return 0;
// }

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
        int n, x;
        bool con = false;
        int a[n];
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, greater<>());
        int sum = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum >= x)
            {
                con = true;
                break;
            }
        }
        if (con)
        {
            cout << i + 1 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
