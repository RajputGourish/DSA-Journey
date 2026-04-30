#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
            https://leetcode.com/problems/maximum-path-score-in-a-grid/submissions/1991913666/?envType=daily-question&envId=2026-04-30
*/

class Solution {
public:
    int maxScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[i][j][c] = max score
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // cost and score mapping
        auto getCost = [&](int val) {
            if (val == 0) return 0;
            return 1;
        };

        auto getScore = [&](int val) {
            return val;
        };

        // start
        int startCost = getCost(grid[0][0]);
        int startScore = getScore(grid[0][0]);

        if (startCost <= k)
            dp[0][0][startCost] = startScore;

        // DP
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    // move right
                    if (j + 1 < n) {
                        int nc = c + getCost(grid[i][j + 1]);
                        if (nc <= k) {
                            dp[i][j + 1][nc] = max(dp[i][j + 1][nc],
                                dp[i][j][c] + getScore(grid[i][j + 1]));
                        }
                    }

                    // move down
                    if (i + 1 < m) {
                        int nc = c + getCost(grid[i + 1][j]);
                        if (nc <= k) {
                            dp[i + 1][j][nc] = max(dp[i + 1][j][nc],
                                dp[i][j][c] + getScore(grid[i + 1][j]));
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans;
    }
};
int main(){
    
    return 0;
}