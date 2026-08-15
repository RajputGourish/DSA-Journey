#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool allZero = true;

        for (int x : nums) {
            xr ^= x;
            if (x != 0) allZero = false;
        }

        if (xr != 0) return nums.size();
        if (allZero) return 0;
        return nums.size() - 1;
    }
};

int main(){
    
    return 0;
}