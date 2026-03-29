#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link ->
                https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/?envType=daily-question&envId=2026-03-29
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < 2; i++) {
            if (s1[i] != s2[i]) {
                char temp = s1[i];
                s1[i] = s1[i+2];
                s1[i+2] = temp;
            }
        }

        return (s1 == s2);
    }
};

int main(){
    
    return 0;
}