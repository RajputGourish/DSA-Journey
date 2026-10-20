#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
            https://leetcode.com/problems/running-sum-of-1d-array/submissions/2176488826/
*/

vector<int> runningSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + nums[i];
    }

    return ans;

    // Time Complexity = O(N)
    // Space Complexity = O(N)
}

int main()
{

    return 0;
}