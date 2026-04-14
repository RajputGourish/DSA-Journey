#include<iostream>
#include<vector>
using namespace std;

/*
    Problem link =>     
                    https://chatgpt.com/c/69de64ae-cda0-8320-87d9-beb8cccfce10
*/

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));

        // Base case: no robots left → cost = 0
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        for (int j = m - 1; j >= 0; j--) {
            for (int i = n; i >= 0; i--) {

                // Option 1: skip this factory
                dp[i][j] = dp[i][j + 1];

                long long cost = 0;

                // Option 2: assign robots to this factory
                for (int k = 1; k <= factory[j][1] && i + k - 1 < n; k++) {
                    cost += abs(robot[i + k - 1] - factory[j][0]);

                    if (dp[i + k][j + 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], cost + dp[i + k][j + 1]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};
int main(){
    
    return 0;
}