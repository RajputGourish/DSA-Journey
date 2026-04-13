#include<iostream>
#include<vector>
using namespace std;


/*
    Problem Link =>
                https://leetcode.com/problems/minimum-distance-to-the-target-element/?envType=daily-question&envId=2026-04-13
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }
        
        return ans;
    }
};

int main(){
    
    return 0;
}