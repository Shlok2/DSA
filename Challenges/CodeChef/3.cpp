#include <bits/stdc++.h>
using namespace std;

int concate(string s, int n, unordered_set<string> u)
{
    string s2;
    for (int i = 0; i < n; i++)
    {
        s2 = "";
        for (int j = 0; j < i; j++)
        {
            s2.push_back(s[j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            s2.push_back(s[j]);
        }
        u.insert(s2);
    }
    return u.size();
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        unordered_set<string> u;
        int ans = concate(s, n, u);
        cout << ans << endl;
    }
    return 0;
}
