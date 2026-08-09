#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2026-08-09
*/


class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n) return 0;

        // Can take all remaining piles
        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Take X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int taken = suffix[i] - suffix[i + X];

            int opponent = solve(i + X, max(M, X));

            ans = max(ans, taken + (suffix[i + X] - opponent));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = sum of piles[i ... n-1]
        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M never needs to be greater than n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};

int main(){
    
    return 0;
}