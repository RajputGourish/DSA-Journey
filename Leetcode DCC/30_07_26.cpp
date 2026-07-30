#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/submissions/?envType=daily-question&envId=2026-07-30
*/

class Solution
{
public:
    int minimumPushes(string word)
    {
        int ln = word.size();
        int ans = 0;

        for (int i = 1; i <= 3; i++)
        {
            if (ln <= 8)
                return ans + ln * i;
            else
            {
                ans = ans + 8 * i;
                ln = ln - 8;
            }
        }

        return ans + ln * 4;
    }
};

int main()
{

    return 0;
}