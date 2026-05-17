#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // Reached zero
            if (arr[i] == 0)
                return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            // Forward jump
            if (forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            // Backward jump
            if (backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};

int main(){
    
    return 0;
}