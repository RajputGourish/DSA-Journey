#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/2073608215/?envType=daily-question&envId=2026-07-19
*/

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> vis(26, false);
        string st;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (vis[ch - 'a'])
                continue;

            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i)
            {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            vis[ch - 'a'] = true;
        }

        return st;
    }
};
l

    int
    main()
{

    return 0;
}
