#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link=>
                https://leetcode.com/problems/furthest-point-from-origin/?envType=daily-question&envId=2026-04-24
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, U = 0;

        for(char c : moves) {
            if(c == 'L') L++;
            else if(c == 'R') R++;
            else U++;
        }

        return abs(R - L) + U;
    }
};
int main(){
    
    return 0;
}