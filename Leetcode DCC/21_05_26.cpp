#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/submissions/2009270269/?envType=daily-question&envId=2026-05-21
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes from arr1
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.count(num)) {
                    ans = max(ans, (int)to_string(num).size());
                    break;
                }
                num /= 10;
            }
        }

        return ans;
    }
};

int main(){
    
    return 0;
}