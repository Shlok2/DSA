#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

// We can use vi instead of->vector<int>
// Similarly we can use vii instead of 'vector of pair'.
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

int main(int argc, char const *argv[])
{
    // k are number of arrays to be sorted.
    int k;
    cin >> k;

    // Creating 2D vector.
    // eg - { { 1, 2, 3 },
    //        {4, 5, 6},
    //        {7, 8, 9, 4} };

    vector<vector<int>> a(k);

    // input all values of arrays to be merged and sorted.
    for (int i = 0; i < k; i++)
    {
        // input size of an array.
        int size;
        cin >> size;

        a[i] = vector<int>(size);

        // inputing value of array of size.
        for (int j = 0; j < size; j++)
        {
            cin >> a[i][j];
        }
    }

    // vector of k size and initialize with 0.
    // We put index of elements in this array ->
    // initially index of all k arrays pointing to
    // there first elements(i.e. 0 index).
    vector<int> idx(k, 0);

    // min queue with pairs(pii).
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // push first element of every array to pq.
    // eg -> In above array push->1,4,7 in pq.
    for (int i = 0; i < k; i++)
    {

        // a[i][0] is first element of every array.
        // i is array no.

        pq.push({a[i][0], i});
    }

    vi ans;
    while (!pq.empty())
    {

        // pii -> pair<int,int>
        // pq is a min heap->hence its top value will be
        // smallest. Hence we are pushing min "first" element of
        // array.
        // eg->in above created array,1 is smallest in (1,4,7)->
        // Hence it will be stored in x and then popped out.
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        // x.second shows array no.
        if ((idx[x.second] + 1) < a[x.second].size())
        {
            // x.second show array no. and idx will tell us kaunsi index me the hum 'x.second' array ki
            // Hence we push ussi array(x.second wali) ka next index(idx[x.second] + 1).
            pq.push({a[x.second][idx[x.second] + 1], x.second});
        }
        idx[x.second] += 1;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    cout << endl;
    return 0;
}
