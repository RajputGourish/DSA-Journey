#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/rotated-digits/submissions/1993530266/?envType=daily-question&envId=2026-05-02
*/

class Solution {
public:
    bool isGood(int num) {
        bool changed = false;
        
        while (num > 0) {
            int d = num % 10;
            
            // invalid digits
            if (d == 3 || d == 4 || d == 7) return false;
            
            // changing digits
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;
            
            num /= 10;
        }
        
        return changed;
    }
    
    int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }
        
        return count;
    }
};
int main(){
    
    return 0;
}