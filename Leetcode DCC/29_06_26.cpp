#include<iostream>
#include<vector>
using namespace std;


/*
Problem Link =>
              https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string &pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};

int main(){
    
    return 0;
}