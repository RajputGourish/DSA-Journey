#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/?envType=daily-question&envId=2026-07-29
*/

class Solution {
public:
    static const long long LIMIT = 1000001;

    vector<int> primes;

    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        vector<int> exp(primes.size(), 0);

        auto addFact = [&](int n, int sign) {
            for (int i = 0; i < primes.size(); i++) {
                int p = primes[i];
                if (p > n) break;
                int x = n;
                while (x) {
                    x /= p;
                    exp[i] += sign * x;
                }
            }
        };

        addFact(total, +1);

        for (int x : cnt)
            if (x)
                addFact(x, -1);

        long long ans = 1;

        for (int i = 0; i < primes.size(); i++) {
            while (exp[i]--) {
                ans *= primes[i];
                if (ans >= LIMIT)
                    return LIMIT;
            }
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid += char(i + 'a');
            half[i] = freq[i] / 2;
        }

        int len = 0;
        for (int x : half) len += x;

        sieve(len);

        if (countWays(half) < k)
            return "";

        string left = "";

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};

int main(){
    
    return 0;
}