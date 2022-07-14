#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> successfulPairs2(vector<int> &spells, vector<int> &potions, long long success)
{
    int cnt = 0;
    vector<int> v;
    for (int i = 0; i < spells.size(); i++)
    {
        cnt = 0;
        for (int j = 0; j < potions.size(); j++)
        {
            if ((spells[i] * potions[j]) > 5)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
        v.push_back(cnt);
    }
    return v;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int cnt;
    vector<int> v;
    for (int i = 0; i < spells.size(); i++)
    {
        cnt = 0;
        for (int j = 0; j < potions.size(); j++)
        {
            if (spells[i] * potions[j] >= success)
            {
                cnt++;
            }
        }
        v.push_back(cnt);
    }
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> spells = {3, 1, 2};
    vector<int> potions = {8, 5, 8};
    int success = 16;
    vector<int> ans = successfulPairs(spells, potions, success);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
