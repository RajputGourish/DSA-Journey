#include <iostream>
#include <vector>
using namespace std;

/*
            Build Array from Permutation

    Problem link ->
                https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
*/
void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
}
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
    
    // Time Complexity = O(N)
    // Space Complexity = O(N)
};
int main()
{
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    Solution s;
    vector<int> ans = s.buildArray(nums);
    display(ans);

    return 0;
}