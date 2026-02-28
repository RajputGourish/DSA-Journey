#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bits = 0;

        for (int i = 1; i <= n; i++) {

            // if power of 2 → new bit length
            if ((i & (i - 1)) == 0)
                bits++;

            result = ((result << bits) + i) % MOD;
        }

        return result;
    }
};
int main(){
    
    return 0;
}