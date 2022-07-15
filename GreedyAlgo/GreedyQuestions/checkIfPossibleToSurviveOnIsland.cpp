
// N – Maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
// Input : S = 10 N = 16 M = 2
// Output : Yes 2
// Explanation 1: One possible solution is to buy a
// box on the first day (Monday), it’s sufficient to eat
// from this box up to 8th day (Monday) inclusive. Now,
// on the 9th day(Tuesday), you buy another box and use
// the chocolates in it to survive the 9th and 10th day.
// Input : 10 20 30
// Output : No
// Explanation 2: You can’t survive even if you buy food
// because the maximum number of units you can buy in one
//  day is less the required food for one day.

#include <iostream>
#include <string.h>
using namespace std;

void survival(int s, int n, int m)
{
    // No. of sundays.
    int x = s / 7;
    // No. of days we can get food.
    int y = s - x;
    // Total food required (total days to survive * unit of food required each day).
    int sm = s * m;
    // No. of days to buy food -> total food required / max food can be bought in one day.
    int days = sm / n;

    // if No. of days to buy food day is perfectly divisible by n -> days will be our required days.
    // else -> we need to increase 1 in days -> eg -> sm = 20 % 16 != 0 -> hence we increase days.
    // sm = 1[(floor value)(20/16)] + 1[Because 20 % 16 != 0] -> days = 2 -> we have to buy
    // food 2 days in order to survive on island.If 20 is nor perfectly divisible by
    // n(16) -> that means we requires some extra food than 16 Hence we buy food next day also
    // -> Hence increase one day.
    if (sm % n != 0)
    {
        days++;
    }

    // If kitna days khareedna chaiye < kitne days khareed skte -> yes, else -> no.
    if (days <= y)
    {
        cout << "Yes " << endl
             << "No of days to buy food: " << days;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
    return 0;
}
