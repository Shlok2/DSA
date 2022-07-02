#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, A;
        cin >> N >> A;
        if (N == 1)
        {
            if (A % 2 == 0)
            {
                cout << "Even" << endl;
            }
            else if (A % 2 == 1)
            {
                cout << "Odd" << endl;
            }
            continue;
        }
        if (A % 2 == 1)
        {
            if (N % 2 == 1)
            {
                cout << "Odd" << endl;
            }
            if (N % 2 == 0)
            {
                cout << "Even" << endl;
            }
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
