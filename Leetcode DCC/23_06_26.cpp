#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-23
*/


class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m + 1), down(m + 1);
        vector<long long> newUp(m + 1), newDown(m + 1);
        vector<long long> prefUp(m + 1), prefDown(m + 1);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;      // previous value < v
            down[v] = m - v;    // previous value > v
        }

        // Build lengths 3..n
        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                // Last move is up, previous move must be down
                newUp[v] = prefDown[v - 1];

                // Last move is down, previous move must be up
                newDown[v] = (prefUp[m] - prefUp[v] + MOD) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        if (n == 2) {
            for (int v = 1; v <= m; v++) {
                ans = (ans + up[v] + down[v]) % MOD;
            }
            return (int)ans;
        }

        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};


int main(){
    
    return 0;
}