#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31
*/


class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}