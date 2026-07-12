#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int num : sorted) {
            if (!rank.count(num)) {
                rank[num] = r++;
            }
        }

        for (int &num : arr) {
            num = rank[num];
        }

        return arr;
    }
};

int main(){
    
    return 0;
}