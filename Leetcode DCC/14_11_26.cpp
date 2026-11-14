#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Brute_minimumSumSubarray(vector<int> &nums, int l, int r)
{
    // Generate all subarray
    int minimum = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int size = j - i + 1;
            if (size > r)
                break;

            if (size < l)
                continue;

            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum > 0)
            {
                minimum = min(minimum, sum);
            }
        }
    }
    return (minimum == INT_MAX) ? -1 : minimum;

    
    // Time Complexity = O(N^3)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int l = 2;
    int r = 4;
    cout << Brute_minimumSumSubarray(nums, l, r) << endl;

    return 0;
}