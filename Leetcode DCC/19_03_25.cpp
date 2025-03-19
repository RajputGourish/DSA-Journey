#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem link ->
            https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19
*/

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    int i = 0;
    while (i <= n - 3)
    {
        if (nums[i] == 0)
        {
            ans++;
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
        }
        i++;
    }
    if (nums[n - 1] == 0 || nums[n - 2] == 0)
        return -1;

    return ans;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> arr = {0, 1, 1, 1, 0, 0};
    cout << minOperations(arr) << endl;

    return 0;
}