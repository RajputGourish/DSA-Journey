#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem Link =>
                    https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01
*/

int minimumCost(vector<int> &nums)
{
    int ans = nums[0];
    int min = INT_MAX;
    int secmin = INT_MAX;

    for (int i = 1; i < nums.size(); i++)
    {
        if (min > nums[i])
        {
            if (secmin > min)
                secmin = min;
            min = nums[i];
        }
        else if (secmin > nums[i])
            secmin = nums[i];
    }

    return nums[0] + min + secmin;
}

int main()
{
    vector<int> nums = {5, 4, 3};
    cout << minimumCost(nums) << endl;

    return 0;
}