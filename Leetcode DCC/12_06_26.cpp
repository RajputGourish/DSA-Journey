#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/submissions/2031089636/?envType=daily-question&envId=2026-06-12
*/

class Solution
{
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    void dfs(int u, int p, vector<vector<int>> &adj)
    {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++)
        {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    int lca(int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (diff & (1 << i))
                a = up[a][i];
        }

        if (a == b)
            return a;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (up[a][i] != up[b][i])
            {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                  vector<vector<int>> &queries)
    {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        dfs(1, 1, adj);

        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries)
        {
            int u = q[0];
            int v = q[1];

            int w = lca(u, v);
            int len = depth[u] + depth[v] - 2 * depth[w];

            if (len == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back((int)pow2[len - 1]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}