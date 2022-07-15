#include <iostream>
#include <string.h>
using namespace std;

// s -> sum.
// d -> digits
string findSmallest(int s, int d)
{
    // if digit is 4 -> max possible no. is 9999.
    // but if sum > 9999(or 9 * 4) -> than it is
    // not possible -> hence return -1.
    if (9 * d < s)
    {
        return "-1";
    }
    string ans = "";
    for (int i = d - 1; i >= 0; i--)
    {

        // if sum > 9 -> than make last element 9.
        // eg -> s = 21, d = 6.
        // then 20 > 9 ->  _ _ _ _ _ 9 ,s= 21-9 = 12.
        // still 11 > 9 -> _ _ _ _ 9 9 ,s = 12-9 = 3.
        if (s > 9)
        {
            // not ans + 9
            // as if ans is 6 and we do above
            // it will become 69 but we want 96 -> hence 9 + ans.
            ans = '9' + ans;
            s -= 9;
        }

        // Now s < 9.
        else
        {
            // If we have left with only one blank.(eg - _ 99)
            // than fill that blank with s.
            if (i == 0)
            {
                ans = to_string(s) + ans;
            }

            // If we have more than one blank left ->
            // fill blank with s-1.
            // in above eg -> s = 3.-> _ _ _ _ 9 9.
            // Hence fill last slot with s-1 = 2.
            // and fill first slot with 1.
            // Also rest slots with 0.
            // Hence final ans = 1 0 0 2 9 9.
            else
            {
                ans = to_string(s - 1) + ans;
                i--;
                while (i > 0)
                {
                    ans = '0' + ans;
                    i--;
                }
                ans = '1' + ans;
                break;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int s = 9, d = 2;
    cout << findSmallest(s, d) << endl;
    return 0;
}

// The task is to find the smallest number with
// given sum of digits as S and number of digits as D.
// Input:
// S = 9
// D = 2
// Output:
// 18
// Explanation:
// 18 is the smallest number
// possible with sum = 9
// and total digits = 2.