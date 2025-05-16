#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void display(vector<string> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
bool hammingOne(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i] && ++diff > 1)
            return false;
    }
    return diff == 1;
}

vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
{
    int n = words.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    // Build DAG: edge from i → j only if i < j to prevent cycles
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && groups[i] != groups[j] && hammingOne(words[i], words[j]))
                if (i < j)
                {
                    graph[i].push_back(j);
                    indegree[j]++;
                }

    // Topological sort (Kahn's algorithm)
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> dp(n, 1), parent(n, -1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // Find max length path
    int maxLen = 0, end = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            end = i;
        }

    // Reconstruct path
    vector<string> result;
    while (end != -1)
    {
        result.push_back(words[end]);
        end = parent[end];
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    vector<string> ans, words = {"bab", "dab", "cab"};
    vector<int> groups = {1, 2, 2};
    ans = getWordsInLongestSubsequence(words, groups);
    display(ans);
    return 0;
}