#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void dfs(int src, vector<vector<int>> &g, vector<int> &vis, string &ans)
{
    vis[src] = 1;
    for (auto i : g[src])
    {
        if (!vis[i])
        {
            dfs(i, g, vis, ans);
        }
    }

    // convert src to alphabetical order from 0th based index.
    char ch = src + 'a';

    // just as we use stack in topo sort.
    // insert ch at starting of ans(not ending).
    // eq -> ans is daf and ch is g -> then ans
    // will become gdaf (not dafg).
    ans = ch + ans;
}

// we are given dict array.
// dict has N words and alien language has k alphabets.
// dict = {"baa","abcd","abca","cab","cad"} -> N=5, k=4 (b,d,a,c).
string findOrder(string dict[], int n, int k)
{
    vector<vector<int>> g(k);

    // run loop till n-2 as we have to take w2 = dict[(n+2) + 1] which will be last
    // element of array.
    for (int i = 0; i < n - 1; i++)
    {
        // eg -> w1 = baa
        //       w2 = abcd
        string w1 = dict[i];
        string w2 = dict[i + 1];

        // loop will run through all letters of min(w1,w2).
        // and lets say w1 and w2 are abc and acc -> then
        // for j=0 -> a = a -> hence j will increament.
        // now for j =1 -> b != c -> hence push 0th index of b to c
        //  and break loop.
        for (int j = 0; j < min(w1.size(), w2.size()); j++)
        {
            if (w1[j] != w2[j])
            {
                g[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }

    // after above loop we have our graph stored in g.
    // And now run topological sort(dfs) and store ans of
    // topo sort in ans.
    vector<int> vis(k, 0);
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
        {
            dfs(i, g, vis, ans);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // dict = {"baa","abcd","abca","cab","cad"}
    // n = 5;
    // k = 4;
    return 0;
}
