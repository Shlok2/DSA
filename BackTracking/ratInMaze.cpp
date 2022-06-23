#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    // if arr[x][y] = 0 -> that means we cannot go to that index.
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solarr)
{
    if (x == n - 1 && y == n - 1)
    {
        solarr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solarr[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, solarr))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, solarr))
        {
            return true;
        }

        // Backtraking
        solarr[x][y] = 0;
        return false;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    cout << endl;
    if (ratInMaze(arr, 0, 0, n, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
