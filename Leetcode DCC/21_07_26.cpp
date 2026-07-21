#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
          https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21    
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        vector<pair<char,int>> blocks;
        int m = t.size();

        for (int i = 0; i < m; ) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        int gain = 0;

        for (int i = 1; i + 1 < (int)blocks.size(); i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                gain = max(gain,
                           blocks[i - 1].second + blocks[i + 1].second);
            }
        }

        return ones + gain;
    }
};

int main(){
    
    return 0;
}