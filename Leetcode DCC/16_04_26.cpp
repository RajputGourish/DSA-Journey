#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/closest-equal-element-queries/?envType=daily-question&envId=2026-04-16
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: precompute answer for each index
        vector<int> best(n, -1);

        for (auto &it : mp) {
            auto &vec = it.second;
            int k = vec.size();

            if (k == 1) continue;

            for (int i = 0; i < k; i++) {
                int curr = vec[i];

                int prev = vec[(i - 1 + k) % k];
                int next = vec[(i + 1) % k];

                int d1 = abs(curr - prev);
                d1 = min(d1, n - d1);

                int d2 = abs(curr - next);
                d2 = min(d2, n - d2);

                best[curr] = min(d1, d2);
            }
        }

        // Step 3: answer queries
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};
int main(){
    
    return 0;
}