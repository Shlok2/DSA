#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second;

    return v1 > v2;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // for value,weight.
    vector<pair<int, int>> a(n);

    // a[i].first stores value.
    // a[i].second stores weight.
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    // Max weight can be handled by a sack.
    int w;
    cin >> w;

    sort(a.begin(), a.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        // if this condition is true -> then break 'this part' of loop.
        if (w >= a[i].second)
        {
            ans += a[i].first;
            w -= a[i].second;
            continue;
        }
        // if w < a[i].second.
        else
        {
            // vw -> value / weight -> value per unit weight.
            double vw = (double)a[i].first / a[i].second;

            // v/w * w = v;(here w is weight left after above loop.)
            ans += vw * w;
            // Here w will become 0;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
