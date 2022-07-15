// Problem statement is in copy.

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // a.first-> store distance from stop to town.
        // a.second-> store fuel that stop can give to truck.
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        // l -> distance from truck to town.
        // p -> initial fuel in truck.
        int l, p;
        cin >> l >> p;

        // update stop distance from town to distance from truck.
        // distance from truck to stop =
        // distance of town to truck{l} - stop to town.
        for (int i = 0; i < n; i++)
        {
            a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());
        int count = 0;

        // curr capacity truck.
        int curr = p;
        // If flag ko hum 1 kar de -> possible hi nhi he ki
        // hum curr fuel se stop tak pahuch jae.
        bool flag = 0;

        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < n; i++)
        {
            // If with curr capacity of truck we can get to town.
            if (curr >= l)
            {
                break;
            }

            // ensure we have enough fuel to reach next stop.
            // while curr fuel se hum stop tak nhi pahuch pae.
            // jab hmare pass enough fuel ho jaega ki hum next
            // stop tak jaa ske -> then yeh loop over ho jaega.
            while (curr < a[i].first)
            {
                // Also agar pq empty he toh hum pahuch hi nhi sakte stop tak.
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                count++;
                curr += pq.top();
                pq.pop();
            }
            if (flag)
            {
                break;
            }
            // jab hum stop tak pahuch gye->push fuel to pq.
            pq.push(a[i].second);
        }

        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr < l)
        {
            curr += pq.top();
            pq.pop();
            count++;
        }

        if (curr < l)
        {
            cout << "-1" << endl;
            continue;
        }

        cout << count << endl;
    }
    return 0;
}
