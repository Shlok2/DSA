// arr[i] denotes the price of the stock on the ith day.
// There is a rule that a customer can buy at most i stock
// on the ith day. If the customer has an amount of k amount
// of money initially, find out the maximum number of stocks
// a customer can buy.

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

// Not Greedy Method.

// int buyMaximumProducts(int arr[], int n, int k)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // if (10*1) or (7*2) or (19 * 3) < 45 or (45 - 10) or (35 - 14) respectively.
//         if (arr[i] * (i + 1) <= k)
//         {
//             k -= (arr[i] * (i + 1));
//             count = count + (i + 1);
//         }
//         // like is case-> 19*3 !< 21
//         else
//         {
//             // Hence while(19<21)-> count++ and k-19.
//             while (arr[i] < k)
//             {
//                 k = k - arr[i];
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int buyMaximumProducts(int price[], int n, int k)
{
    vector<pair<int, int>> v;
    // Why i+1 = ?
    // As array start from 0.
    // but first element should be multiplied with
    // 1 not 0 ,similarly second with 2 (not 1)
    // and so on.
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(price[i], i + 1));
    }

    // sort by price.
    // Greedly we think to buy cheapest stock first
    // So that we can by max stocks.
    // (7,2),(10,1),(19,3)
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // Same as above approach(non-greedy).
        int price = v[i].first;
        int stock = v[i].second;
        if (price * stock <= k)
        {
            ans += stock;
            k -= (price * stock);
        }
        else
        {
            // eg -> 21 / 19 = 1.
            ans += (k / price);
            k -= price * (k / price);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(price, n, k) << endl;
    return 0;
}
