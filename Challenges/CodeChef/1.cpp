#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int x, m;
    cin >> x >> m;
    int inv = 1, building = 0, a = 0;
    bool blockover = true;
    for (int i = 0; i < m; i++)
    {
        while (inv != 0)
        {
            a++;
            cout << a << " ";
            inv--;
            cout << inv << " ";
            if (a == x)
            {
                building++;
                blockover = false;
                break;
            }
        }

        // cout << building << endl;

        if (blockover = false)
        {
            a = 0;
            inv = inv + x;
        }
        else if (blockover = true)
        {
            inv = a;
        }
    }
    cout << endl;
    cout << building << endl;
    // }
    return 0;
}
