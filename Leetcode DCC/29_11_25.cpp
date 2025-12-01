#include <iostream>
#include <vector>
using namespace std;

/*
Problem link:
            https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29
*/

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum % k;
    }
};

int main()
{
    vector<int> nums = {3, 9, 7};
    int k = 5;
    Solution s;
    cout << "The Answer is " << s.minOperations(nums, k);
    return 0;
}