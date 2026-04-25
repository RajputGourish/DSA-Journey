#include<iostream>
#include<vector>
using namespace std;
/*
    Problem Link =>
                https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/?envType=daily-question&envId=2026-04-25
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long per = 4LL * side;

        // Step 1: map points to perimeter
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            if (y == 0) pos[i] = x;
            else if (x == side) pos[i] = side + y;
            else if (y == side) pos[i] = 3LL * side - x;
            else pos[i] = 4LL * side - y;
        }

        // Step 2: sort indices by position
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });

        // Step 3: extend arrays for circular handling
        vector<long long> extPos(2 * n);
        vector<int> extIdx(2 * n);

        for (int i = 0; i < n; i++) {
            extPos[i] = pos[idx[i]];
            extIdx[i] = idx[i];
            extPos[i + n] = pos[idx[i]] + per;
            extIdx[i + n] = idx[i];
        }

        // Manhattan distance
        auto manhattan = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) +
                   abs(points[i][1] - points[j][1]);
        };

        // Step 4: check function
        function<bool(int)> can = [&](int d) {
            for (int start = 0; start < n; start++) {
                vector<int> selected;
                selected.push_back(extIdx[start]);

                long long lastPos = extPos[start];

                for (int i = start + 1; i < start + n; i++) {

                    // perimeter pruning
                    if (extPos[i] - lastPos < d) continue;

                    bool ok = true;

                    // check with ALL selected points
                    for (int prev : selected) {
                        if (manhattan(prev, extIdx[i]) < d) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        selected.push_back(extIdx[i]);
                        lastPos = extPos[i];

                        if ((int)selected.size() >= k)
                            return true;
                    }
                }
            }
            return false;
        };

        // Step 5: binary search
        int low = 0, high = 2 * side, ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
int main(){
    
    return 0;
}