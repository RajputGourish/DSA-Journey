#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/create-grid-with-exactly-one-path/description/?envType=daily-question&envId=2026-10-27
*/

void display(vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << endl;
    }
}

vector<string> createGrid(int m, int n)
{
    vector<string> ans(m, string(n, '#'));
    for (int i = 0; i < n; i++)
    {
        ans[0][i] = '.';
    }
    for (int i = 0; i < m; i++)
    {
        ans[i][n - 1] = '.';
    }

    return ans;

    // Time Complexity = O(m+n)
    // Space Complexity = O(m x n)
}

int main()
{
    createGrid(3, 3);
    return 0;
}