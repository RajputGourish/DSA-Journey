#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=daily-question&envId=2026-08-14
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}