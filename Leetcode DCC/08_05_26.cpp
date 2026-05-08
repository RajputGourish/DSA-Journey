#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/?envType=daily-question&envId=2026-05-08
*/
class Solution {
public:
    
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;

        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> divisible;

        // Build prime -> indices mapping
        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                divisible[p].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            // Adjacent left
            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // Adjacent right
            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            // Prime teleportation
            int val = nums[idx];

            if (isPrime(val) && !usedPrime.count(val)) {

                for (int nextIdx : divisible[val]) {
                    if (!vis[nextIdx]) {
                        vis[nextIdx] = 1;
                        q.push({nextIdx, steps + 1});
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};

int main(){
    
    return 0;
}