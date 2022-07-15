// Find min platform required acc to
// arriving and departure time of trains.
// Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
// dep[] =        {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
// Output: 3
// Explanation: There are at-most three trains at a time
// (time between 9:40 to 12:00)

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int MinPlatform(int arr[], int dep[], int n)
{
    // Sort both arriving and departure arrays.

    // INTUTION/CONDITION: Every train is similar and we don't
    // care about what train is coming or going. We are
    // only concerned about their timings of arrival and departure.
    sort(arr, arr + n);
    sort(dep, dep + n);

    // Start i from second element of arriving arr.
    // As first element is already arrived and hence
    // We too maxPlaform 1 initially.
    int i = 1;
    // As train is not departed initially .Hence,
    // Start for first index of dep arr.
    int j = 0;

    // Platform needed uptil now(at particular value
    // of i and j).(Because 1 train is already arrived).
    int maxPlatform = 1;
    // It stores min platform needed.
    int neededPlatform = 1;
    while (i < n)
    {
        // Train arrived but platform is not empty.
        if (arr[i] < dep[j])
        {
            i++;
            maxPlatform++;
            // after increasing maxplatform->compare maxPlatform and neededplatform for
            // max needPlatform.
            neededPlatform = max(maxPlatform, neededPlatform);
        }
        // Platform become empty but train not arrived yet
        // -> Hence reduce maxplatform(As next arriving train
        // can use this platform).
        else if (dep[j] < arr[i])
        {
            j++;
            // after increasing j there will be no train at platform
            // Hence reduce maxPlatform(needed platform).
            maxPlatform--;
        }
    }
    return neededPlatform;
}

int main(int argc, char const *argv[])
{
    int arrivingTime[] = {900, 940, 950, 1100, 1500, 1800};
    int departureTime[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arrivingTime) / sizeof(arrivingTime[0]);
    int mina = MinPlatform(arrivingTime, departureTime, n);
    cout << "Min platform needed: " << mina << endl;
    return 0;
}
