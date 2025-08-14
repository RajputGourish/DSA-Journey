#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link=>
            https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2025-08-14
*/

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        int maxi = -1;
        for (int i = 0; i + 2 < num.size(); i++)
        {
            char curr = num[i];
            char next = num[i + 1];
            char nextnext = num[i + 2];
            if (curr == next && next == nextnext)
            {
                int val = (curr - '0');
                if (maxi < val)
                {
                    maxi = val;
                    ans.append(3, curr);
                }
            }
        }
        return ans;
    }

    // Time Complexity = O(N)
    // Space Complexity = O(!)
};
int main()
{
    Solution s;
    cout << s.largestGoodInteger("6777133339") << endl;

    return 0;
}