class Solution {
    const int MOD = 1e9 + 7;

    // Generate all valid row states of length m
    void generateStates(int m, int pos, vector<int>& state,
                        vector<vector<int>>& validStates) {
        if (pos == m) {
            validStates.push_back(state);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (pos == 0 || state[pos - 1] != color) {
                state[pos] = color;
                generateStates(m, pos + 1, state, validStates);
            }
        }
    }

    // Check if two rows are compatible (no vertical adjacent cells have same
    // color)
    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i])
                return false;
        }
        return true;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<vector<int>> validStates;
        vector<int> state(m);
        generateStates(m, 0, state, validStates);

        int k = validStates.size();
        vector<vector<int>> compatible(k);

        // Precompute compatibility between valid states
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (isCompatible(validStates[i], validStates[j])) {
                    compatible[i].push_back(j);
                }
            }
        }

        // DP initialization
        vector<long long> dp(k, 1);
        for (int col = 1; col < n; ++col) {
            vector<long long> newDp(k);
            for (int i = 0; i < k; ++i) {
                for (int j : compatible[i]) {
                    newDp[i] = (newDp[i] + dp[j]) % MOD;
                }
            }
            dp = newDp;
        }

        long long result = 0;
        for (long long val : dp) {
            result = (result + val) % MOD;
        }
        return (int)result;
    }
};