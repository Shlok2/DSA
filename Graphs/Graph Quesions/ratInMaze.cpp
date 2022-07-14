#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;

void dfs(int i, int j, vector<vector<int>> &visited, string str, vector<vector<int>> &m, int n)
{

    // if we are out of maze or current position is 0 in maze or vistied of current
    // possition is already true (i.e. it is already visited) -> then return.
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1 || m[i][j] == 0 || visited[i][j] == 1)
    {
        return;
    }

    // If we reach our destination than store in ans and return.
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(str);
        return;
    }

    // make visted of i,j = 1 and then check for up,down,left,right
    // positions and after than make visited[i][j] = 0 again.
    visited[i][j] = 1;

    dfs(i - 1, j, visited, str + "U", m, n);
    dfs(i + 1, j, visited, str + "D", m, n);
    dfs(i, j + 1, visited, str + "R", m, n);
    dfs(i, j - 1, visited, str + "L", m, n);

    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<vector<int>> visited(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    // if first block standing on is 0 then its not possible.
    // if last block of grid(our goal) is 0 then also not possible.
    if (m[0][0] == 0)
    {
        return ans;
    }

    if (m[n - 1][n - 1] == 0)
    {
        return ans;
    }

    string str = "";

    // staring point is (0,0) -> i,j = 0,0.
    dfs(0, 0, visited, str, m, n);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    vector<string> result = findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
