#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18
*/

int Brute_largestInteger(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i + k <= nums.size(); i++)
    {
        for (int j = i; j <= i + k - 1; j++)
        {
            
            cout<<"run"<<endl;
            mpp[nums[j]]++;
        }
    }
    int maxi = -1;
    for(auto a: mpp){
        if(a.second < 2){
            maxi = max(maxi, a.first);
        }
    }

    return maxi;
}


class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: Only one subarray exists
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Count frequency of every number
        vector<int> freq(51, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Case 2: Every element is a subarray
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 3: 1 < k < n
        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 9, 2, 1, 7};
    // vector<int> arr = {0,0};

    cout << Brute_largestInteger(arr, 2) << endl;

    return 0;
}