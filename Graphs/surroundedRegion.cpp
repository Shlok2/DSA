#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void change(vector<vector<char>> &A, int x, int y)
{
    // convert o to *.
    A[x][y] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    // cx and cy will give us all 4 elements surrounding x and y.
    // (i.e. cx -> left,right
    //       cy -> up,bottom)
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        // If cx and cy didn't exceed limit of 2D vector and A[cx][cy]
        // (all four surrounding elements) are 'O' -> then use reccursion
        // -> we went to that 'O' recursively and we checked for their
        // neighbours and so on....
        if (cx >= 0 && cx < A.size() && cy >= 0 && cy < A[0].size() && A[cx][cy] == 'O')
        {
            change(A, cx, cy);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    // To declare 2D vector and take its input.
    vector<vector<char>> A(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    // convert EDGE 'O' to 'X'.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (A[i][j] == 'O')
                {
                    change(A, i, j);
                }
            }
        }
    }

    // Convert rest(except edge) 'O' to X.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'O')
            {
                A[i][j] = 'X';
            }
        }
    }

    // Convert * back to 'O'.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == '*')
            {
                A[i][j] = 'O';
            }
        }
    }

    // Print 2D vector.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
