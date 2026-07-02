#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/?envType=daily-question&envId=2026-07-02
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int nh = h - grid[nr][nc];

                if (nh <= 0)
                    continue;

                if (nh > best[nr][nc]) {
                    best[nr][nc] = nh;
                    q.push({nr, nc, nh});
                }
            }
        }

        return false;
    }
};

int main(){
    
    return 0;
}