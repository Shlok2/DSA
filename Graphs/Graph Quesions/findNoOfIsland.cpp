#include <iostream>
#include <string.h>
using namespace std;
#define ROW 5
#define COL 5

// To check if given cell can be included in DFS or not.
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col < COL) && (col >= 0) && M[row][col] == 1 && !visited[row][col];
}

// To check all 8 adjacent cells of given cell.
void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{

    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // mark current cell is visited and then check all adj cells.
    visited[row][col] = true;

    for (int k = 0; k < 8; k++)
    {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
        {
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
        }
    }
}

int countIslands(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] == 1 && !visited[i][j])
            {
                DFS(M, i, j, visited);
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int M[][COL] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}
