#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*
Problem Link =>
            https://leetcode.com/problems/minimum-cost-to-convert-string-ii/submissions/1902148489/?envType=daily-question&envId=2026-01-30

*/

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = source.size();

        // 1. collect all strings
        unordered_set<string> st;
        for (auto &s: original) st.insert(s);
        for (auto &s: changed) st.insert(s);

        vector<string> all(st.begin(), st.end());
        unordered_map<string,int> id;
        for (int i=0;i<all.size();i++) id[all[i]] = i;

        int m = all.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i=0;i<m;i++) dist[i][i] = 0;

        // edges
        for (int i=0;i<original.size();i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd Warshall
        for (int k=0;k<m;k++)
          for (int i=0;i<m;i++)
            for (int j=0;j<m;j++)
              if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // group lengths
        unordered_set<int> lens;
        for (auto &s: original) lens.insert(s.size());

        vector<long long> dp(n+1, INF);
        dp[0] = 0;

        for (int i=1;i<=n;i++) {
            // equal char case
            if (source[i-1] == target[i-1])
                dp[i] = min(dp[i], dp[i-1]);

            for (int L : lens) {
                int j = i - L;
                if (j < 0) continue;

                string sSub = source.substr(j, L);
                string tSub = target.substr(j, L);

                if (!id.count(sSub) || !id.count(tSub)) continue;

                long long c = dist[id[sSub]][id[tSub]];
                if (c < INF)
                    dp[i] = min(dp[i], dp[j] + c);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};


int main(){
    
    return 0;
}