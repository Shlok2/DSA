#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
    }

    int ans = 0;
    while (pq.size() != 1)
    {
        int a1 = pq.top();
        pq.pop();
        int a2 = pq.top();
        pq.pop();

        ans += a1 + a2;
        pq.push(a1 + a2);
    }

    cout << ans << endl;
    return 0;
}
