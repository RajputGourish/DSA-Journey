#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/?envType=daily-question&envId=2026-07-08
*/

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefCnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);

        int total = 0;
        for (char c : s)
            if (c != '0')
                total++;

        vector<long long> pw(total + 1), invPw(total + 1);
        pw[0] = 1;
        for (int i = 1; i <= total; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        long long inv10 = modPow(10, MOD - 2);
        invPw[0] = 1;
        for (int i = 1; i <= total; i++)
            invPw[i] = invPw[i - 1] * inv10 % MOD;

        vector<long long> prefVal(n + 1, 0);

        int rank = 0;
        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            prefSum[i + 1] = prefSum[i];
            prefVal[i + 1] = prefVal[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                rank++;
                prefCnt[i + 1]++;
                prefSum[i + 1] += d;
                prefVal[i + 1] =
                    (prefVal[i + 1] + 1LL * d * invPw[rank]) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int leftRank = prefCnt[l];
            int rightRank = prefCnt[r + 1];

            long long val =
                (prefVal[r + 1] - prefVal[l] + MOD) % MOD;

            long long x = val * pw[rightRank] % MOD;

            ans.push_back(x * (sum % MOD) % MOD);
        }

        return ans;
    }
};


int main(){
    
    return 0;
}