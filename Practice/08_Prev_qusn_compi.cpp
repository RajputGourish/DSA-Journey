#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

// Brute
vector<int> twoSum(vector<int> &numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }
    }
    return {-1, -1};
    // TLE
}

// Better
vector<int> twoSum2(vector<int> &numbers, int target)
{
    unordered_map<int, int> mpp;

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int rem = target - numbers[i];
        if (mpp.find(rem) != mpp.end())
        {
            return {mpp[rem] + 1, i + 1};
        }
        mpp[numbers[i]] = i;
    }
    return {-1, -1};
}

// optimal
vector<int> twoSum3(vector<int> &numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j)
    {
        int sum = numbers[i] + numbers[j];
        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
            return {i + 1, j + 1};
    }
    return {-1, -1};

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{

    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum3(arr, target);
    cout << ans[0] << " "
         << ans[1]
         << endl;

    return 0;
}