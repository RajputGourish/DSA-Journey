#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link=>
                https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/submissions/1967025758/?envType=daily-question&envId=2026-04-02
*/

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size(), n = coins[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(3, LLONG_MIN)));

        // Base case
        for (int k = 0; k <= 2; k++)
        {
            if (coins[0][0] >= 0)
            {
                dp[0][0][k] = coins[0][0];
            }
            else
            {
                if (k == 0)
                    dp[0][0][k] = coins[0][0];
                else
                    dp[0][0][k] = 0; // neutralize
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                for (int k = 0; k <= 2; k++)
                {

                    long long best = LLONG_MIN;

                    // Check from top
                    if (i > 0)
                    {
                        // take value
                        if (dp[i - 1][j][k] != LLONG_MIN)
                        {
                            best = max(best, dp[i - 1][j][k] + coins[i][j]);
                        }

                        // neutralize if negative
                        if (coins[i][j] < 0 && k > 0 && dp[i - 1][j][k - 1] != LLONG_MIN)
                        {
                            best = max(best, dp[i - 1][j][k - 1]);
                        }
                    }

                    // Check from left
                    if (j > 0)
                    {
                        // take value
                        if (dp[i][j - 1][k] != LLONG_MIN)
                        {
                            best = max(best, dp[i][j - 1][k] + coins[i][j]);
                        }

                        // neutralize if negative
                        if (coins[i][j] < 0 && k > 0 && dp[i][j - 1][k - 1] != LLONG_MIN)
                        {
                            best = max(best, dp[i][j - 1][k - 1]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

int main()
{

    return 0;
}