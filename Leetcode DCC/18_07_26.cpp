#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Problem Link =>
      https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18
*/
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int high = INT_MIN;
        int low = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (high < nums[i])
                high = nums[i];
            if (low > nums[i])
                low = nums[i];
        }

        for (int i = min(high, low); i >= 1; i--)
        {
            if (high % i == 0 && low % i == 0)
                return i;
        }
        return 1;
    }
};

int main()
{

    return 0;
}