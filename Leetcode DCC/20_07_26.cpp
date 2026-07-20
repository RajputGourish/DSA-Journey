#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int idx = i * n + j;
                int newIdx = (idx + k) % total;

                int newRow = newIdx / n;
                int newCol = newIdx % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};


int main(){
    
    return 0;
}