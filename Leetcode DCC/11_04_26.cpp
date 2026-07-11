#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link=>
                https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/?envType=daily-question&envId=2026-04-11
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        // Step 1: store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: process each value
        for (auto &p : mp) {
            auto &v = p.second;
            int n = v.size();
            
            if (n < 3) continue;

            // Step 3: sliding window of size 3
            for (int i = 0; i + 2 < n; i++) {
                int dist = v[i + 2] - v[i];
                ans = min(ans, dist);
            }
        }

        // Step 4: return result
        return ans == INT_MAX ? -1 : 2 * ans;
    }
};

int main(){
    
    return 0;
}