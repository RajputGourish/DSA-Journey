#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/rearrange-array-elements-by-sign
*/

class Solution
{
public:
    vector<int> Brute_rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        for (int i = 0; i < n / 2; i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;

        // Time Complexity = O(N + n/2)
        // Space Complexity = O(N-> storing pos and neg numbers + N-> for returning ans)
    }

    vector<int> Better_rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        int posind = 0;
        int negind = 0;

        while (posind < n && negind < n)
        {
            while (posind < n && nums[posind] < 0)
            {
                posind++;
            }
            while (negind < n && nums[negind] > 0)
            {
                negind++;
            }
            if (posind >= n || negind >= n)
            {
                break;
            }
            ans.push_back(nums[posind]);
            ans.push_back(nums[negind]);
            posind++;
            negind++;
        }
        return ans;

        // Time Complexity = O(N)
        // Space Complexity = O(N-> returning ans)
    }
    vector<int> Optimal_rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posind = 0;
        int negind = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                ans[negind] = nums[i];
                negind += 2;
            }
            else
            {
                ans[posind] = nums[i];
                posind += 2;
            }
        }

        return ans;
        // simplicity apprach
        // Time Complexity = O(N)
        // Space Complexity = O(N-> returning ans)
    }
};
int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    Solution s;
    s.Brute_rearrangeArray(arr);
    s.Better_rearrangeArray(arr);
    s.Optimal_rearrangeArray(arr);

    return 0;
}