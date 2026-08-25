#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-missing-multiple-of-k/?envType=daily-question&envId=2026-08-25
*/

class Solution {
public:
    int missingMultiple(vector<int>& n, int k) {
        vector<int> na(101, 0);

        for (int i = 0; i < n.size(); i++) {
            na[n[i]] = 1;
        }
    int j;
        for(j=k; j<=100; j = j+k){
            if(na[j]==0){
                return j;
            }
        }

        return j;
    }
};

int main(){
    
    return 0;
}