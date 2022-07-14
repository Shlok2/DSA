#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool strongPasswordCheckerII(string password)
{
    string s = "!@#$%^&*()-+";
    string str = password;
    if (str.size() < 8)
    {
        return false;
    }

    bool lc = false, uc = false, nu = false, abc = false;

    for (int i = 0; i < str.size(); i++)
    {
        if (i != 0 && str[i] == str[i - 1])
        {
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (str[i] == ch)
            {
                // if (str[i - 1] != ch && str[i + 1] != ch)
                // {
                lc = true;
                break;
                // }
            }
        }

        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            if (str[i] == ch)
            {
                // if (str[i - 1] != ch && str[i + 1] != ch)
                // {
                uc = true;
                break;
                // }
            }
        }

        for (int j = 0; j <= 9; j++)
        {
            if (str[i] == j)
            {
                // if (str[i - 1] != j && str[i + 1] != j)
                // {
                nu = true;
                break;
                // }
            }
        }

        for (int j = 0; j < s.length(); j++)
        {
            if (str[i] == s[j])
            {
                // if (str[i - 1] != s[j] && str[i + 1] != s[j])
                // {
                abc = true;
                break;
                // }
            }
        }
    }

    if (lc == true && uc == true && nu == true && abc == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool strongPasswordCheckerII(string password)
{
    string s = "!@#$%^&*()-+";
    string str = password;
    if (str.size() < 8)
    {
        return false;
    }

    bool lc = false, uc = false, nu = false, abc = false;

    for (int i = 0; i < str.size(); i++)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (str[i] == ch)
            {
                if (str[i - 1] != ch && str[i + 1] != ch)
                {
                    lc = true;
                    break;
                }
            }
        }

        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            if (str[i] == ch)
            {
                if (str[i - 1] != ch && str[i + 1] != ch)
                {
                    uc = true;
                    break;
                }
            }
        }

        for (int j = 0; j <= 9; j++)
        {
            if (str[i] == j)
            {
                if (str[i - 1] != j && str[i + 1] != j)
                {
                    nu = true;
                    break;
                }
            }
        }

        for (int j = 0; j != s.length(); j++)
        {
            if (str[i] == s[j])
            {
                if (str[i - 1] != s[j] && str[i + 1] != s[j])
                {
                    abc = true;
                    break;
                }
            }
        }
    }

    if (lc == true && uc == true && nu == true && abc == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
