#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

// n is no. of plaforms.
#define n 2
// m is no. of trains(no. of arrays).
#define m 5

int maxStop(int arr[][3])
{
    // Vector is for platform no.
    // pair represents arriving and departure time.
    vector<pair<int, int>> vect[n + 1];

    // For all arrays(trains) make pair of arr and leaving
    // and store in in vector[arr[i][2]]->
    // arr[i][2] is platform no. of each array(train).
    // vect[1] -> {1000,1030},{1010,1020},{1025,1040}
    // vect[2] -> {1130,1145},{1130,1140}
    for (int i = 0; i < m; i++)
    {
        vect[arr[i][2]].push_back(make_pair(arr[i][1], arr[i][0]));
    }

    // sort trains for each platform as per departure time.
    for (int i = 0; i <= n; i++)
    {
        sort(vect[i].begin(), vect[i].end());
    }

    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        // like vect[0].size will be 0 so
        // continue with vect[1].size.
        if (vect[i].size() == 0)
        {
            continue;
        }
        int x = 0;
        // Initially min one platform is necessary.
        count++;
        // Eg - for vect[1] -> size = 3,
        // for vect[2] -> size = 2.
        for (int j = 1; j < vect[i].size(); j++)
        {
            // for vect[1][1...3] -> ka departure time >=
            // vect[1][0] ->ka arriving time.
            if (vect[i][j].second >= vect[i][x].first)
            {
                x = j;
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}
