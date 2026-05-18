#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        // Store indices having same value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int idx = q.front();
                q.pop();

                // Reached last index
                if (idx == n - 1)
                    return steps;

                // Move to idx - 1
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                // Move to idx + 1
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // Move to same value indices
                for (int next : mp[arr[idx]]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }

                // Important optimization:
                // clear to avoid revisiting same-value nodes again
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};
int main(){
    
    return 0;
}