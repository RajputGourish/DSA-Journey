#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/process-string-with-special-operations-ii/description/?envType=daily-question&envId=2026-06-17
*/

char processStr(string s, long long k)
{
    string ans = "";

    for (char c : s)
    {
        if (c == '*')
        {
            if (ans.size() > 0)
            {
                ans.pop_back();
            }
        }
        else if (c == '#')
        {
            ans += ans;
        }
        else if (c == '%')
        {
            reverse(ans.begin(), ans.end());
        }
        else
        {
            ans += c;
        }

        if (ans.size() >= k + 1)
            return ans[k];
    }

    return (ans.size() < k + 1) ? '.' : ans[k];

    // MLE => Memory Limit Exceeds
}

char processStr2(string s, long long k)
{
    long long len = 0;

    for (char c : s)
    {
        if (c == '*')
        {
            len = max(0LL, len - 1);
        }
        else if (c == '#')
        {
            len *= 2;
        }
        else if (c != '%')
        {
            len++;
        }
    }

    if (k >= len)
        return '.';

    for (int i = (int)s.size() - 1; i >= 0; --i)
    {
        char c = s[i];

        if (c == '*')
        {
            len++;
        }
        else if (c == '#')
        {
            len /= 2;
            if (k >= len)
                k -= len;
        }
        else if (c == '%')
        {
            k = len - 1 - k;
        }
        else
        {
            len--;
            if (k == len)
                return c;
        }
    }

    return '.';
}

int main()
{
    string s = "z*#";
    cout << processStr(s, 0) << endl;

    return 0;
}