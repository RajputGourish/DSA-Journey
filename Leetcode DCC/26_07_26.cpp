#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-product-of-three-numbers/description/?envType=daily-question&envId=2026-07-26
*/

// Brute approach
int Brute_maximumProduct(vector<int> &a)
{
    int n = a.size();
    if (n == 3)
        return a[0] * a[1] * a[2];
    int maxi = INT_MIN;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                maxi = max(maxi, a[i] * a[j] * a[k]);
            }
        }
    }
    return maxi;
}

// Time Complexity = O(N^3)
// Space Complexity = O(1)


// Better
int Better_maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n != 3)
        sort(nums.begin(), nums.end());
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
}

// Time Complexity = O(NlogN)
// Space Complexity = O(1)


// Optimal
int maximumProduct(vector<int> &a)
{
    int n = a.size();
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int el = a[i];
        if (el < min1)
        {
            min2 = min(min2, min1);
            min1 = el;
        }
        else if (el < min2)
        {
            min2 = el;
        }

        if (el > max1)
        {
            max3 = max(max3, max2);
            max2 = max(max2, max1);
            max1 = el;
        }
        else if (el > max2)
        {
            max3 = max(max3, max2);
            max2 = el;
        }
        else if (el > max3)
        {
            max3 = el;
        }
    }
    return max(max1 * max2 * max3, min1 * min2 * max1);
}

// Time Complexity = O(N)
// Space Complexity = O(1)



int main()
{

    return 0;
}
