#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                    https://leetcode.com/problems/walking-robot-simulation/submissions/1970723962/?envType=daily-question&envId=2026-04-06
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;
        
        // Store obstacles
        for (auto &obs : obstacles) {
            long long key = (long long)obs[0] * 60001 + obs[1];
            st.insert(key);
        }

        // Directions: North, East, South, West
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int x = 0, y = 0;
        int dir = 0; // 0 = North
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4; // turn right
            } 
            else if (cmd == -2) {
                dir = (dir + 3) % 4; // turn left
            } 
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key = (long long)nx * 60001 + ny;

                    if (st.count(key)) break; // obstacle

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};

int main(){
    
    return 0;
}