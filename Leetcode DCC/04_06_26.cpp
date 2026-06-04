#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/submissions/2022451891/?envType=daily-question&envId=2026-06-04
*/

class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;
        ll sum;
    };

    string s;
    Node memo[20][2][20][11][11];
    bool vis[20][2][20][11][11];

    Node dfs(int pos, int started, int len,
             int last2, int last1, bool tight) {

        if (pos == (int)s.size())
            return {1, 0};

        if (!tight && vis[pos][started][len][last2][last1])
            return memo[pos][started][len][last2][last1];

        int limit = tight ? s[pos] - '0' : 9;

        Node res{0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, 0, 10, 10, ntight);

                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
            } else {
                if (!started) {
                    Node nxt = dfs(pos + 1, 1, 1, 10, d, ntight);

                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum;
                } else {
                    int add = 0;

                    if (len >= 2) {
                        if ((last1 > last2 && last1 > d) ||
                            (last1 < last2 && last1 < d))
                            add = 1;
                    }

                    Node nxt = dfs(pos + 1, 1, len + 1,
                                   last1, d, ntight);

                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum + nxt.cnt * add;
                }
            }
        }

        if (!tight) {
            vis[pos][started][len][last2][last1] = true;
            memo[pos][started][len][last2][last1] = res;
        }

        return res;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        s = to_string(N);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 0, 10, 10, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
int main(){
    
    return 0;
}