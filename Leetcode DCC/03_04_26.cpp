#include<iostream>
#include<vector>
using namespace std;

/*
    Problem link=>
            https://leetcode.com/problems/maximum-walls-destroyed-by-robots/?envType=daily-question&envId=2026-04-03
*/

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<pair<int,int>> r;
        for(int i = 0; i < n; i++) {
            r.push_back({robots[i], distance[i]});
        }

        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();

        // convert to index ranges
        auto getRange = [&](int L, int R) {
            int l = lower_bound(walls.begin(), walls.end(), L) - walls.begin();
            int r = upper_bound(walls.begin(), walls.end(), R) - walls.begin() - 1;
            if(l > r) return pair<int,int>{-1, -1};
            return pair<int,int>{l, r};
        };

        vector<pair<int,int>> left(n), right(n);

        for(int i = 0; i < n; i++) {
            int pos = r[i].first, dist = r[i].second;

            int L = pos - dist;
            if(i > 0) L = max(L, r[i-1].first);
            left[i] = getRange(L, pos);

            int R = pos + dist;
            if(i < n - 1) R = min(R, r[i+1].first);
            right[i] = getRange(pos, R);
        }

        // dp[i] = max walls till index i
        vector<int> dp(m + 1, 0);

        for(int i = 0; i < n; i++) {
            vector<int> newdp = dp;

            // LEFT
            if(left[i].first != -1) {
                int l = left[i].first;
                int rgt = left[i].second;

                int best = 0;
                for(int j = 0; j <= l; j++) {
                    best = max(best, dp[j]);
                }

                newdp[rgt + 1] = max(newdp[rgt + 1], best + (rgt - l + 1));
            }

            // RIGHT
            if(right[i].first != -1) {
                int l = right[i].first;
                int rgt = right[i].second;

                int best = 0;
                for(int j = 0; j <= l; j++) {
                    best = max(best, dp[j]);
                }

                newdp[rgt + 1] = max(newdp[rgt + 1], best + (rgt - l + 1));
            }

            dp = newdp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    
    return 0;
}