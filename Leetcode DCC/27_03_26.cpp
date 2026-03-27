#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link=>
                https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27
*/


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        int shift = k % n;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int newIndex;
                
                if (i % 2 == 0) {
                    // left shift
                    newIndex = (j + shift) % n;
                } else {
                    // right shift
                    newIndex = (j - shift + n) % n;
                }
                
                if (mat[i][j] != mat[i][newIndex]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(){
    
    return 0;
}