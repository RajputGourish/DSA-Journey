#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
             https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16
*/

string processStr(string s)
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
    }

    return ans;

    
    // Time Complexity = O(N)
    // Space Complexity = O(N) => for storing the answer 
    
}

int main()
{
    string s = "abc%*";
    // string s = "z*#";
    cout << processStr(s) << endl;

    return 0;
}