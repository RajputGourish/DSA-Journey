#include<iostream>
#include<vector>
using namespace std;


/*
Problem Link =>
    https://leetcode.com/problems/number-of-zigzag-arrays-ii/?envType=daily-question&envId=2026-06-24          
*/
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long a = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        // states:
        // 0..m-1      => up[x]
        // m..2m-1     => down[x]

        for (int x = 0; x < m; x++) {
            // up[x] -> down[y] for y > x
            for (int y = x + 1; y < m; y++) {
                T[m + y][x] = 1;
            }

            // down[x] -> up[y] for y < x
            for (int y = 0; y < x; y++) {
                T[y][m + x] = 1;
            }
        }

        Matrix P = power(T, n - 1);

        vector<long long> init(sz, 1);

        long long ans = 0;

        for (int i = 0; i < sz; i++) {
            long long ways = 0;

            for (int j = 0; j < sz; j++) {
                ways = (ways + P[i][j] * init[j]) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return (int)ans;
    }
};


int main(){
    

    return 0;
}