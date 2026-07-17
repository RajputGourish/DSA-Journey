#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! Problem Link =>

* https://leetcode.com/problems/sorted-gcd-pair-queries/description/?envType=daily-question&envId=2026-07-17

*/

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> divisible(mx + 1, 0);

        // Count numbers divisible by each i
        for (int i = 1; i <= mx; i++)
        {
            for (int j = i; j <= mx; j += i)
                divisible[i] += freq[j];
        }

        vector<long long> exact(mx + 1, 0);

        // Inclusion-Exclusion
        for (int i = mx; i >= 1; i--)
        {
            long long cnt = divisible[i];
            exact[i] = cnt * (cnt - 1) / 2;

            for (int j = i + i; j <= mx; j += i)
                exact[i] -= exact[j];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        for (long long q : queries)
        {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};

int main()
{

    return 0;
}