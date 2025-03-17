#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem link ->
            https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
*/

// Leetcode Solution
bool divideArray_Leet(vector<int> &nums)
{
    // Sort array to group equal elements together
    sort(nums.begin(), nums.end());

    // Check consecutive pairs in sorted array
    for (int pos = 0; pos < nums.size(); pos += 2)
    {
        // If any pair doesn't match, we can't form n equal pairs
        if (nums[pos] != nums[pos + 1])
        {
            return false;
        }
    }

    // All pairs found successfully
    return true;

    // Time Complexity = O~(NlogN)
    // Space Complexity = O~(logN)
}

// Mine Solution
bool divideArray_Self(vector<int> &nums)
{
    // Sort an array
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            sum = nums[i];
        }
        else
        {
            sum = nums[i] - sum;
            if (sum != 0)
                return false;
        }
    }
    return true;

    // Time Complexity = O~(2 * Nlog 2N) -> sorting and traversing
    // Space Complexity = O~(logN) -> sorting
}

int main()
{
    vector<int> arr = {3, 2, 3, 2, 2, 2};
    cout << divideArray_Leet(arr) << endl;
    cout << divideArray_Self(arr) << endl;

    return 0;
}