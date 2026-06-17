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

        if(ans.size() >= k+1) return ans[k];
    }

    return (ans.size() < k+1) ? '.' : ans[k];

    // MLE => Memory Limit Exceeds
}

int main()
{
    string s = "z*#";
    cout<<processStr(s, 0)<<endl;
    
    return 0;
}