#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/?envType=daily-question&envId=2026-07-10
*/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        vector<int> nxt(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff)
                r++;
            nxt[l] = r;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u > v) swap(u, v);

            if (up[LOG - 1][u] < v) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}