#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
        https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/?envType=daily-question&envId=2026-04-21
*/
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) parent[py] = px;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build connections
        for (auto &swap : allowedSwaps)
            unite(swap[0], swap[1]);

        // Group indices by root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int hamming = 0;

        // Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // Count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // Match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    hamming++;
                }
            }
        }

        return hamming;
    }
};
int main(){
    
    return 0;
}