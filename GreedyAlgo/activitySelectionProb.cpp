#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function.
static bool comp(pair<int, int> a, pair<int, int> b)
{
    // If finishing time of a,b is same -> then we check starting time of both.
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    // Otherwise sort acc to finishing time.
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{

    // Making vector of pair and putting values to vector v.
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {start[i], end[i]};
    }

    sort(v.begin(), v.end(), comp);

    int i = 0;
    int j = 1;
    // count = 1->because we always have to include last element in ans.
    int count = 1;

    while (j < n)
    {
        if (v[i].second < v[j].first)
        {
            count++;
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    int c = maxMeetings(start, end, n);
    cout << "Max number of meetings possible: " << c << endl;
    return 0;
}
