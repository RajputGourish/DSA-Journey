#include<iostream>
#include<vector>
using namespace std;

/*
! Problem Link =>
               * https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/?envType=daily-question&envId=2026-07-24              
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int step = 1; step <= 3; step++) {
            for (int mask = 0; mask < MAXX; mask++) {
                if (!dp[step - 1][mask]) continue;
                for (int x : nums) {
                    dp[step][mask ^ x] = true;
                }
            }
        }

        int ans = 0;
        for (bool ok : dp[3]) {
            if (ok) ans++;
        }

        return ans;
    }
};


int main(){
    
    return 0;
}
