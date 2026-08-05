#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05
*/

class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vector<int> vis(n, 0);

        // DFS to mark suspicious methods
        function<void(int)> dfs = [&](int u)
        {
            vis[u] = 1;
            for (int v : graph[u])
            {
                if (!vis[v])
                    dfs(v);
            }
        };

        dfs(k);

        // Check if any outside method calls a suspicious method
        for (auto &e : invocations)
        {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v])
            {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}