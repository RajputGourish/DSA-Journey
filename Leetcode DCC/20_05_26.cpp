#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<int> freq(n + 1, 0);
        vector<int> ans(n);
        
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                common++;
            
            freq[B[i]]++;
            if (freq[B[i]] == 2)
                common++;
            
            ans[i] = common;
        }
        
        return ans;
    }
};
int main(){
    
    return 0;
}