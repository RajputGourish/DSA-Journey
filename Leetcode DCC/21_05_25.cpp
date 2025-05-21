
#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> mat)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

/*
    Problem Link ->
                https://leetcode.com/problems/set-matrix-zeroes/submissions/1640504845/?envType=daily-question&envId=2025-05-21

*/
void blackbox(vector<vector<int>> &mat, int i, int j)
{
    int m = mat.size();
    int n = mat[0].size();
    for (int a = 0; a < m; a++)
    {
        mat[a][j] = 0;
    }
    for (int a = 0; a < n; a++)
    {
        mat[i][a] = 0;
    }
}
void setZeroes(vector<vector<int>> &mat)
{
    vector<vector<int>> copy = mat;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (copy[i][j] == 0)
            {
                blackbox(mat, i, j);
            }
        }
    }

    // Time Complexity = O(m * n) * (m + n)
    // Space Complexity = O(m*n)
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1}};
    display(matrix);

    setZeroes(matrix);
    cout << "Change Matrix ----" << endl;
    display(matrix);

    return 0;
}