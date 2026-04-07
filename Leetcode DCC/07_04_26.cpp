#include<iostream>
#include<vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07
*/

class Robot {
public:
    int w, h;
    int x, y, dir;

    vector<string> dirs = {"East", "North", "West", "South"};
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
    }

    void step(int num) {
        int cycle = 2 * (w + h - 2);
        num %= cycle;

        // Special case
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; // South
            return;
        }

        while (num--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; // turn left
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            x = nx;
            y = ny;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};
int main(){
    
    return 0;
}