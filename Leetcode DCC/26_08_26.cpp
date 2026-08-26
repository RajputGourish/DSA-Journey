#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            // We have exactly k ones
            if (ones == k) {

                // Remove leading zeros to make substring as short as possible
                while (left <= right && s[left] == '0') {
                    left++;
                }

                // Current window [left, right] has exactly k ones
                string cur = s.substr(left, right - left + 1);

                // Check if it is better
                if (ans.empty() ||
                    cur.length() < ans.length() ||
                    (cur.length() == ans.length() && cur < ans)) {
                    ans = cur;
                }

                // Move left past the first 1
                if (s[left] == '1') {
                    ones--;
                    left++;
                }
            }
        }

        return ans;
    }
};


int main(){

    return 0;
}