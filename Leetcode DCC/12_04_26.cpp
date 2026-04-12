#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                    https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/submissions/1976545242/?envType=daily-question&envId=2026-04-12
*/
class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0; // free initial position
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[j] = min cost where second finger is at j
        vector<int> dp(26, INT_MAX), newdp(26);
        
        // initial: both fingers free
        dp.assign(26, 0);

        for (int i = 0; i < n - 1; i++) {
            fill(newdp.begin(), newdp.end(), INT_MAX);
            
            int curr = word[i] - 'A';
            int next = word[i + 1] - 'A';
            
            for (int j = 0; j < 26; j++) {
                if (dp[j] == INT_MAX) continue;
                
                // same finger types next
                int cost1 = dp[j] + dist(curr, next);
                newdp[j] = min(newdp[j], cost1);
                
                // other finger types next
                int cost2 = dp[j] + dist(j, next);
                newdp[curr] = min(newdp[curr], cost2);
            }
            
            dp = newdp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
int main(){
    
    return 0;
}