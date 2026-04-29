#include<iostream>
#include<vector>
using namespace std;
/*
    Problem Link =>
                https://leetcode.com/problems/maximum-score-from-grid-operations/?
                envType=daily-question&envId=2026-04-29
*/

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // prefix sum per column
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));

        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                pref[j][i] = pref[j][i + 1] + grid[i][j];
            }
        }

        // dp[j][h] = max score till column j with height h
        vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));

        for (int j = 1; j < n; j++) {
            for (int h = 0; h <= n; h++) {
                long long best = 0;

                for (int ph = 0; ph <= n; ph++) {
                    long long add = 0;

                    if (ph > h) {
                        // column j contributes
                        add += pref[j][h] - pref[j][ph];
                    } else if (h > ph) {
                        // column j-1 contributes
                        add += pref[j - 1][ph] - pref[j - 1][h];
                    }

                    best = max(best, dp[j - 1][ph] + add);
                }

                dp[j][h] = best;
            }
        }

        long long ans = 0;
        for (int h = 0; h <= n; h++) {
            ans = max(ans, dp[n - 1][h]);
        }

        return ans;
    }
};
int main(){
    
    return 0;
}