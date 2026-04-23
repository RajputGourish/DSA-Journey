#include <iostream>
#include <vector>
using namespace std;
/*
    Problem Link=>
                https://leetcode.com/problems/sum-of-distances/?envType=daily-question&envId=2026-04-23
*/

void display(vector<long long> &d)
{
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

void distance(vector<int> &a)
{
    int n = a.size();
    vector<long long> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            continue;
            if (a[i] == a[j])
            {
                ans[i] += abs(i - j);
            }
        }
    }
    display(ans);
} 
// =>  TLE

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: store indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for (auto &p : mp) {
            vector<int>& idx = p.second;
            int m = idx.size();

            vector<long long> prefix(m + 1, 0);

            // prefix sum of indices
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + idx[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = (long long)idx[i] * i - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - (long long)idx[i] * (m - i - 1);
                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 3, 1, 1, 2};
    distance(arr);
    return 0;
}