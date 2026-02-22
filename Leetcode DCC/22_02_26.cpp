#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
            https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22
*/


class Solution {
public:
    int binaryGap(int n) {
        int last = -1;     // position of previous 1
        int maxDist = 0;
        int pos = 0;       // current bit position
        
        while (n > 0) {
            if (n & 1) {   // if current bit is 1
                if (last != -1) {
                    maxDist = max(maxDist, pos - last);
                }
                last = pos;
            }
            n >>= 1;       // shift right
            pos++;
        }
        
        return maxDist;
    }
};
int main(){
    
    return 0;
}