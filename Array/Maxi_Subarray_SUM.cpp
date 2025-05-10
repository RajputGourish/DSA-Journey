#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link ->
                    https://leetcode.com/problems/maximum-subarray
*/
int Brute_maxSubArray(vector<int> &nums)
{
    // Generate all subaaray
    int n = nums.size();
    int maxsum = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + nums[j];

            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

int Optimal_maxSubArray(vector<int> &nums)
{
    // kadane's algorithm
    int n = nums.size();
    int maxsum = INT8_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];

        if (sum > maxsum)
        {
            maxsum = sum;
        }
        if (sum < 0)
            sum = 0;
    }

    return maxsum;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Brute_maxSubArray(arr) << endl;
    cout << Optimal_maxSubArray(arr) << endl;

    return 0;
}