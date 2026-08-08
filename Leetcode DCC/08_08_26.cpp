#include<iostream>
#include<vector>
#include <array>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/?envType=daily-question&envId=2026-08-08
*/


class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // prev[i][c] = rightmost index <= i having character c
        vector<array<int, 26>> prev(n);

        for (int c = 0; c < 26; c++)
            prev[0][c] = -1;

        prev[0][word1[0] - 'a'] = 0;

        for (int i = 1; i < n; i++) {
            prev[i] = prev[i - 1];
            prev[i][word1[i] - 'a'] = i;
        }

        // exact[i] = latest possible index of word2[i]
        // when word2[i...] is matched exactly.
        vector<int> exact(m + 1, -1);
        exact[m] = n;

        for (int i = m - 1; i >= 0; i--) {
            int limit = exact[i + 1] - 1;

            if (limit < 0)
                break;

            exact[i] = prev[limit][word2[i] - 'a'];
        }

        // one[i] = latest possible index of word2[i]
        // when word2[i...] can be matched with <= 1 mismatch.
        vector<int> one(m + 1, -1);
        one[m] = n;

        for (int i = m - 1; i >= 0; i--) {
            int limit1 = one[i + 1] - 1;
            int limit2 = exact[i + 1] - 1;

            if (limit1 < 0 && limit2 < 0)
                break;

            int best = -1;

            // Current character matches exactly.
            if (limit1 >= 0) {
                best = prev[limit1][word2[i] - 'a'];
            }

            // Use the one allowed mismatch at current position.
            if (limit2 >= 0) {
                int cur = -1;

                for (int c = 0; c < 26; c++) {
                    if (c == word2[i] - 'a')
                        continue;

                    cur = max(cur, prev[limit2][c]);
                }

                best = max(best, cur);
            }

            one[i] = best;
        }

        if (one[0] == -1)
            return {};

        vector<int> ans;
        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {
            while (pos < n) {
                bool can = false;

                if (word1[pos] == word2[i]) {
                    // Match exactly; remaining part may use the mismatch.
                    if (i == m - 1 || one[i + 1] > pos)
                        can = true;
                } 
                else if (!usedMismatch) {
                    // Use the mismatch here; remaining must match exactly.
                    if (i == m - 1 || exact[i + 1] > pos) {
                        can = true;
                        usedMismatch = true;
                    }
                }

                if (can) {
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                pos++;
            }

            if ((int)ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};

int main(){
    
    return 0;
}