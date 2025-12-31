#include <iostream>
#include <vector>
using namespace std;

/*

    Problem link:- 
                    https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2025-12-30

*/

class Solution
{

    void display(vector<int> arr)
    {
        for (int i = 1; i < 10; i++)
        {
            cout << i << " " << arr[i] << endl;
        }
    }

    bool eachrow(vector<vector<int>> &g, int rs, int cs, vector<int> &dis, int sum)
    {
        for (int i = rs; i < rs + 3; i++)
        {
            int er = 0;
            for (int j = cs; j < cs + 3; j++)
            {
                er += g[i][j];
                dis[g[i][j]]++;
            }
            if (er != sum)
                return false;
        }

        return true;
    }

    bool eachcol(vector<vector<int>> &g, int rs, int cs, vector<int> &dis, int sum)
    {
        for (int i = cs; i < cs + 3; i++)
        {
            int er = 0;
            for (int j = rs; j < rs + 3; j++)
            {
                er += g[j][i];
                dis[g[j][i]]++;
            }
            if (er != sum)
                return false;
        }
        return true;
    }

    bool eachdiagonal(vector<vector<int>> &g, int rs, int cs, vector<int> &dis, int sum)
    {
        int dsum = 0;
        for (int i = 0; i < 3; i++)
        { // Diagonal1
            dis[g[rs + i][cs + i]]++;
            dsum += g[rs + i][cs + i];
        }
        if (sum != dsum)
            return false;
        dsum = 0;
        for (int i = 0; i < 3; i++)
        { // Diagona2
            dis[g[rs - i + 2][cs + i]]++;
            dsum += g[rs - i + 2][cs + i];
        }
        if (sum != dsum)
            return false;

        return true;
    }

    bool blackmagic(vector<vector<int>> &grid, int i, int j, vector<int> &dis, int sum)
    {

        if (((eachrow(grid, i, j, dis, sum) && eachcol(grid, i, j, dis, sum) && eachdiagonal(grid, i, j, dis, sum))) == false)
            return false;

        for (int m = 1; m < 10; m++)
        {
            if (dis[m] == 0)
                return false;
        }

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i + 2 < grid.size(); i++)
        {
            for (int j = 0; j + 2 < grid[i].size(); j++)
            {
                int sum = 0;
                vector<int> dis(16, 0);

                for (int k = 0; k < 3; k++)
                {
                    sum += grid[i][j + k];
                }
                ans += blackmagic(grid, i, j, dis, sum);
            }
        }
        return ans;
    }
};

int main()
{
    // vector<vector<int>> grid = {{0}};
    vector<vector<int>> grid = {{4, 3, 8, 4},
                                {9, 5, 1, 9},
                                {2, 7, 6, 2}};

    Solution s;
    cout << s.numMagicSquaresInside(grid) << endl;

    return 0;
}