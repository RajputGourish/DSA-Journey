#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
            https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/?envType=daily-question&envId=2026-10-22
*/

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int step) -> bool
        {
            for (int i = 1; i < n; i++)
            {
                int prev = (z + (i - 1) * step + n) % n;
                int curr = (z + i * step + n) % n;

                if (nums[prev] > nums[curr])
                {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        if (check(1))
        {
            ans = min(ans, z);
            ans = min(ans, n - z + 2);
        }

        if (check(-1))
        {
            ans = min(ans, z + 2);
            ans = min(ans, n - z);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


int main()
{

    return 0;
}