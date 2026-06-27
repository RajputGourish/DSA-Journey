#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle value 1 separately
        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;


                if (cur > 1000000000LL / cur) break; // avoid overflow
                cur = cur * cur;
            }

            if (freq.count(cur) && freq[cur] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};


int main(){
    
    return 0;
}