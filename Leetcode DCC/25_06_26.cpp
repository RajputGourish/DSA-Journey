#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25
*/

int countMajoritySubarrays(vector<int> &nums, int target)
{
    int ans = 0;
    // generate all subarray
    for (int i = 0; i < nums.size(); i++)
    {
        int targ = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if(nums[j] == target) targ++;
            if(targ >= (((j-i+1)/2)+1)){
                ans++;
            }            
        }
    }
    return ans;

    
    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
    
}

int main()
{

    vector<int> nums = {1, 2, 2, 3};
    int target = 2;

    cout << countMajoritySubarrays(nums, target) << endl;

    return 0;
}