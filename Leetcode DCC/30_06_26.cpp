#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/2051449935/?envType=daily-question&envId=2026-06-30
*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lastseen[3] = {-1, -1, -1};
        int NoOfsubsring = 0;
        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                NoOfsubsring =
                    NoOfsubsring +
                    (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
            }
        }
        return NoOfsubsring;
    }
};

int main(){
    
    return 0;
}