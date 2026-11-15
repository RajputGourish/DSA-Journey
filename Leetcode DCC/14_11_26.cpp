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

int Better_minimumSumSubarray(vector<int> &nums, int l, int r)
{
    // Generate all subarray
    int minimum = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            int size = j - i + 1;
            if (size > r)
                break;
            sum += nums[j];
            if (size < l)
                continue;

            if (sum > 0)
                minimum = min(minimum, sum);
        }
    }
    return (minimum == INT_MAX) ? -1 : minimum;

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

int Optimal_minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int n = nums.size();

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    multiset<long long> st;
    long long minimum = INT_MAX;

    for (int j = l; j <= n; j++)
    {
        st.insert(prefix[j - l]);

        if (j > r)
        {
            auto it = st.find(prefix[j - r - 1]);

            if (it != st.end())
                st.erase(it);
        }

        auto it = st.lower_bound(prefix[j]);

        if (it != st.begin())
        {
            it--;

            long long sum = prefix[j] - *it;

            minimum = min(minimum, sum);
        }
    }

    return (minimum == INT_MAX) ? -1 : minimum;

    // Time Complexity = O(NLogN)
    // Space Complexity = O(N)
}

int main()
{

    vector<int> nums = {-12, 8};
    int l = 1;
    int r = 1;
    cout << Brute_minimumSumSubarray(nums, l, r) << endl;
    cout << Better_minimumSumSubarray(nums, l, r) << endl;
    cout << Optimal_minimumSumSubarray(nums, l, r) << endl;

    return 0;
}