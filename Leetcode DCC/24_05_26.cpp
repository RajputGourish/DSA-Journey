#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24
*/

class Solution {
public:
    int n;
    vector<int> dp;

    int dfs(vector<int>& arr, int d, int i) {
        if (dp[i] != -1) return dp[i];

        int ans = 1;

        // Move Right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(arr, d, j));
        }

        // Move Left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(arr, d, j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);

        int res = 1;

        for (int i = 0; i < n; i++) {
            res = max(res, dfs(arr, d, i));
        }

        return res;
    }
};


int main(){
    
    return 0;
}