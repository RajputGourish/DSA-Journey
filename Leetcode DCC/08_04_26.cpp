#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/xor-after-range-multiplication-queries-i/submissions/1972676572/?envType=daily-question&envId=2026-04-08
*/

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};

int main(){
    
    return 0;
}