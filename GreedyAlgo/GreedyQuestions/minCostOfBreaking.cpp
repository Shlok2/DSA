// check GFG article for figure
// Horizontal cut -> 2 1 3 1 4
// vertical cut -> 4 1 2
// For above board optimal way to cut into square is:
// Total minimum cost in above case is 42. It is
// evaluated using following steps.

// Initial Value : Total_cost = 0
// Total_cost = Total_cost + edge_cost * total_pieces

// Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
// Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
// Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
// Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
// Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
// Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
// Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
// Cost 1 Vertical cut        Cost = 38 + 1*4 = 42

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{

    return (a.first > b.first);
}

int minimumCostOfBreaking(vector<pair<int, int>> v)
{
    int cost = 0;

    // Intially we have just one whole board
    // and hence horizonatal and vertical peices is 1.
    int tvp = 1, thp = 1;

    // No need for this sorting as we already passed sorted
    // vector v (sorted in main function).
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 0)
        {
            cost = cost + (v[i].first * thp);
            tvp++;
        }
        else if (v[i].second == 1)
        {
            cost = cost + (v[i].first * tvp);
            thp++;
        }
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    int m = 5, n = 3;
    int X[m] = {2, 1, 3, 1, 4};
    int Y[n] = {4, 1, 2};

    // To push both X and Y into vector v.
    // Pairs are of edge_cost,(0/1)(Horizontal_cut -> 0/ vectical_cut -> 1).
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        v.push_back(make_pair(X[i], 1));
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(Y[i], 0));
    }
    // Final vector -> (2,1),(1,1),(3,1),(1,1),(4,1),(4,0),(1,0),(2,0).
    // 2 -> vectical cut cost, 1 ->vertical cut.

    sort(v.begin(), v.end(), comp);
    // Final vector after sorting ->
    // (4,1),(4,0),(3,1),(2,1),(2,0),(1,1),(1,1),(1,0).
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << minimumCostOfBreaking(v);
    return 0;
}
