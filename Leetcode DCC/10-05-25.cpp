#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
                    https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10

*/
long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    long long zero1 = 0;
    long long zero2 = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        sum1 += nums1[i] == 0 ? 1 : nums1[i];
        zero1 += nums1[i] == 0 ? 1 : 0;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        sum2 += nums2[i] == 0 ? 1 : nums2[i];
        zero2 += nums2[i] == 0 ? 1 : 0;
    }

    if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0))
    {
        return -1;
    }

    return max(sum1, sum2);

    // Time Complexity = O(N + M)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> nums1 = {3, 2, 0, 1, 0}, nums2 = {6, 5, 0};
    cout << minSum(nums1, nums2) << endl;

    return 0;
}