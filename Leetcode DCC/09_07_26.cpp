#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
         https://leetcode.com/problems/path-existence-queries-in-a-graph-i/submissions/2061946590/?envType=daily-question&envId=2026-07-09     
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}
