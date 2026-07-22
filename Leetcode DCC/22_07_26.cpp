#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximize-active-section-with-trade-ii/submissions/2077414256/?envType=daily-question&envId=2026-07-22
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    struct ZeroGroup {
        int start;
        int end;
        int length;
    };

    class SparseTable {
        int n;
        vector<vector<int>> st;
        vector<int> log_table;

    public:
        SparseTable(const vector<int>& nums) {
            n = nums.size();
            if (n == 0) return;

            log_table.resize(n + 1);
            log_table[1] = 0;
            for (int i = 2; i <= n; ++i) {
                log_table[i] = log_table[i / 2] + 1;
            }

            int max_log = log_table[n] + 1;
            st.assign(max_log, vector<int>(n));

            for (int i = 0; i < n; ++i) {
                st[0][i] = nums[i];
            }

            for (int j = 1; j < max_log; ++j) {
                for (int i = 0; i + (1 << j) <= n; ++i) {
                    st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        int query(int l, int r) const {
            if (l > r) return 0;
            int j = log_table[r - l + 1];
            return max(st[j][l], st[j][r - (1 << j) + 1]);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        // 1. Total '1's in the entire string
        int total_ones_in_s = 0;
        for (char c : s) {
            if (c == '1') total_ones_in_s++;
        }

        // 2. Extract zero-groups
        vector<ZeroGroup> zeroGroups;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') ++j;
                zeroGroups.push_back({i, j - 1, j - i});
                i = j;
            } else {
                ++i;
            }
        }

        int m = zeroGroups.size();

        // 3. Precompute sum of adjacent zero groups lengths
        vector<int> adjacentSums(max(0, m - 1), 0);
        for (int i = 0; i < m - 1; ++i) {
            adjacentSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }

        SparseTable st(adjacentSums);

        // Binary search helpers for overlapping zero groups
        auto get_first_group = [&](int l) {
            int low = 0, high = m - 1, res = m;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zeroGroups[mid].end >= l) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return res;
        };

        auto get_last_group = [&](int r) {
            int low = 0, high = m - 1, res = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zeroGroups[mid].start <= r) {
                    res = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return res;
        };

        vector<int> ans;
        ans.reserve(queries.size());

        // 4. Process queries
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int first_idx = get_first_group(l);
            int last_idx = get_last_group(r);

            // Trade requires at least 2 zero groups overlapping with [l, r]
            if (first_idx >= last_idx || first_idx >= m || last_idx < 0) {
                ans.push_back(total_ones_in_s);
                continue;
            }

            auto get_effective_len = [&](int idx) {
                int start = max(l, zeroGroups[idx].start);
                int end = min(r, zeroGroups[idx].end);
                return end - start + 1;
            };

            int max_gain = 0;

            if (last_idx == first_idx + 1) {
                // Exactly 2 zero groups overlap [l, r]
                max_gain = get_effective_len(first_idx) + get_effective_len(last_idx);
            } else {
                // More than 2 zero groups overlap [l, r]
                // 1) Pair involving left boundary zero group
                max_gain = max(max_gain, get_effective_len(first_idx) + zeroGroups[first_idx + 1].length);

                // 2) Pair involving right boundary zero group
                max_gain = max(max_gain, zeroGroups[last_idx - 1].length + get_effective_len(last_idx));

                // 3) Internal full zero group pairs
                if (first_idx + 1 <= last_idx - 2) {
                    max_gain = max(max_gain, st.query(first_idx + 1, last_idx - 2));
                }
            }

            ans.push_back(total_ones_in_s + max_gain);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}