// Explanation of algo is below code.

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

// To check if x,y coordinate dont go out of grid.
int validCoord(int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x > n - 1 || y > n - 1)
    {
        return 0;
    }
    return 1;
}

void bfs(int n, int m, int data[][8], int x, int y, int color)
{
    int vis[101][101];
    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> q;
    q.push({x, y});

    vis[x][y] = 1;

    while (!q.empty())
    {
        pair<int, int> coord = q.front();
        int x = coord.first;
        int y = coord.second;
        int precolor = data[x][y];

        // change data[x][y] to given color and then check
        // -> adj data = precolor
        // -> adj node is not visited
        // -> and adj doesn't go outside the grid.
        // adj nodes are x+1,x-1,y+1,y-1.
        data[x][y] = color;
        q.pop();

        if (validCoord(x + 1, y, n, m) && data[x + 1][y] == precolor && vis[x + 1][y] == 0)
        {
            q.push({x + 1, y});
            vis[x + 1][y] = 1;
        }

        if (validCoord(x - 1, y, n, m) && data[x - 1][y] == precolor && vis[x - 1][y] == 0)
        {
            q.push({x - 1, y});
            vis[x - 1][y] = 1;
        }

        if (validCoord(x, y + 1, n, m) && data[x][y + 1] == precolor && vis[x][y + 1] == 0)
        {
            q.push({x, y + 1});
            vis[x][y + 1] = 1;
        }

        if (validCoord(x, y - 1, n, m) && data[x][y - 1] == precolor && vis[x][y - 1] == 0)
        {
            q.push({x, y - 1});
            vis[x][y - 1] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n, m, x, y, color;
    n = 8;
    m = 8;

    int data[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };

    x = 4, y = 4, color = 3;

    // Function Call
    bfs(n, m, data, x, y, color);
    return 0;
}

// In MS-Paint, when we take the brush to a pixel and click,
// the color of the region of that pixel is replaced with a
// new selected color. Following is the problem statement
// to do this task.
// Input : screen[M][N] = {
//             {1, 1, 1, 1, 1, 1, 1, 1},
//             {1, 1, 1, 1, 1, 1, 0, 0},
//             {1, 0, 0, 1, 1, 0, 1, 1},
//             {1, 2, 2, 2, 2, 0, 1, 0},
//             {1, 1, 1, 2, 2, 0, 1, 0},
//             {1, 1, 1, 2, 2, 2, 2, 0},
//             {1, 1, 1, 1, 1, 2, 1, 1},
//             {1, 1, 1, 1, 1, 2, 2, 1},
// };
// x = 4, y = 4, newColor = 3

// Output:
// Screen should be changed to following.
// screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
//                {1, 1, 1, 1, 1, 1, 0, 0},
//                {1, 0, 0, 1, 1, 0, 1, 1},
//                {1, 3, 3, 3, 3, 0, 1, 0},
//                {1, 1, 1, 3, 3, 0, 1, 0},
//                {1, 1, 1, 3, 3, 3, 3, 0},
//                {1, 1, 1, 1, 1, 3, 1, 1},
//                {1, 1, 1, 1, 1, 3, 3, 1},
//                };