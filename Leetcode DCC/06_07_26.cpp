#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06

*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        int ans = 0;
        int maxRight = 0;

        for (auto &it : intervals) {
            if (it[1] > maxRight) {
                ans++;
                maxRight = it[1];
            }
        }

        return ans;
    }
};

int main(){
    
    return 0;
}