#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/rotate-image/submissions/1995083696/?envType=daily-question&envId=2026-05-04
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
int main(){
    
    return 0;
}