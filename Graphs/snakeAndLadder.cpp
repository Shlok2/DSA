#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int ladders, snakes;
    map<int, int> lad;
    map<int, int> snak;

    // this will store ladder for u to v and
    // if lad[u] will come it will give result as v.
    cin >> ladders;
    for (int i = 0; i < ladders; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    // Same as ladders.
    cin >> snakes;
    for (int i = 0; i < snakes; i++)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    // moves -> stores min moves required to reach 100.
    // q will store the no. we are at.we start with 1
    //   hence push 1 initially.
    // found will return true if we reach 100.
    // vis is to check if no. is visited.
    // vis[1] = true as we are starting from 1 and hence is
    //   already visited.
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101, 0);
    vis[1] = true;

    while (!q.empty() && !found)
    {
        int sz = q.size();
        while (sz--)
        {
            // t is current no. we are at in board.
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6; die++)
            {
                // it t + die gives 100 then make found = true.
                if (t + die == 100)
                {
                    found = true;
                }

                // if t + die<= 100 and there is a ladder at t+die and
                // we have not visited of lad[t+die](number after climing ladder
                // at t+die).
                // then make lad[t+die] as true and check if lad[t+die] gives
                // 100 -> then return true.
                // also push lad[t+die] to queue.(lad[t+die] -> new no.
                // after climing ladder).
                if (t + die <= 100 && lad[t + die] && !vis[lad[t + die]])
                {
                    vis[lad[t + die]] = true;
                    if (lad[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(lad[t + die]);
                }

                // nearly same as above case of ladder.
                // The only difference is we have snake instead of ladder at
                // t+die.
                else if (t + die <= 100 && snak[t + die] && !vis[snak[t + die]])
                {
                    vis[snak[t + die]] = true;
                    if (snak[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(snak[t + die]);
                }

                // if we dont have snake or ladder at t+die.
                // then just mark t+die as visited and push that no.
                // in queue.
                else if (t + die <= 100 && !vis[t + die] && !snak[t + die] && !lad[t + die])
                {
                    vis[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        // after sz becomes 0 -> that means we have successfully
        // moved one step and hence increase move by 1.
        moves++;
    }

    // if we can reach 100.
    if (found)
    {
        cout << "No of moves required to reach 100 are:" << endl;
        cout << moves << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}
