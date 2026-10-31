#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/twisted-mirror-path-count/description/?envType=daily-question&envId=2026-10-31
*/

void recursion(vector<vector<int>> &grid, int r, int c, char direction, int &cnt)
{
    if (r == grid.size() - 1 && c == grid[r].size() - 1)
    {
        cnt++;
        return;
    }
    if(r >= grid.size() || c >= grid[r].size()){
        return;
    }
    if (grid[r][c] == 0)
    {
        // right move
        if (c < grid[r].size() - 1)
        {
            recursion(grid, r, c + 1, 'l', cnt);
        }

        // down
        if (r < grid[r].size() - 1)
        {
            recursion(grid, r + 1, c, 'u', cnt);
        }
    }
    else
    {
        if (direction == 'l')
        {
            recursion(grid, r + 1, c, 'u', cnt);
        }
        else
        {
            recursion(grid, r, c + 1, 'l', cnt);
        }
    }
}

int uniquePaths(vector<vector<int>> &grid)
{
    int cnt = 0;
    recursion(grid, 0, 0, 'a', cnt);
    return cnt;
}

int main()
{
    // vector<vector<int>> matrix = {
    //     {0, 1, 0},
    //     {0, 0, 1},
    //     {1, 0, 0}};
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 1, 0}};
    // vector<vector<int>> matrix = {
    //     {0, 0},
    //     {0, 0}
    // };

    cout << uniquePaths(matrix) << endl;

    return 0;
}