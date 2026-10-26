#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
            https://leetcode.com/problems/squares-of-a-sorted-array/description/
*/

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i] * nums[i];
        ans.push_back(num);
    }

    sort(ans.begin(), ans.end());

    return ans;

    // Time Complexity = O(N)
    // Space Complexity = O(N)
}

// Optimal
vector<int> sortedSquares2(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int i = 0;
    int j = nums.size() - 1;
    int n = nums.size() - 1;

    while (i <= j)
    {
        if (abs(nums[i]) > abs(nums[j]))
        {
            ans[n] = nums[i] * nums[i];
            i++;
        }
        else
        {
            ans[n] = nums[j] * nums[j];
            j--;
        }
        n--;
    }

    return ans;

    // Time Complexity = O(NlogN)
    // Space Complexity = O(N)
}

int main()
{

    vector<int> nums = {-4, -1, 0, 3, 10};
    //                 {0   0   0   0   0}
    vector<int> ans = sortedSquares2(nums);
    display(nums);
    display(ans);
    return 0;
}