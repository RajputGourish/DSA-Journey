#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-alternating-sum-of-squares/?envType=daily-question&envId=2026-10-13
*/

class Solution
{
    static bool comp(int a, int b)
    {
        return abs((long long)a) < abs((long long)b);
    }

public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);

        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            long long square = 1LL * nums[i] * nums[i];

            if (i < n / 2)
            {
                ans -= square;
            }
            else
            {
                ans += square;
            }
        }

        return ans;
    }

    // Time Complexity = O(NlogN + N)
    // Space Complexity = O(LogN)
};

int main()
{

    vector<int> arr = {1, 2, 3};

    return 0;
}