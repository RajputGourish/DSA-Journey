#include<iostream>
#include<vector>
using namespace std;
/*
Problem link =>
            https://leetcode.com/problems/count-binary-substrings/submissions/1924697333/?envType=daily-question&envId=2026-02-19
*/

 int countBinarySubstrings(string s) {
        int prevCount = 0;
        int currCount = 1;
        int result = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currCount++;
            } else {
                result += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }
        
        result += min(prevCount, currCount);
        return result;
    }
int main(){
    
    return 0;
}