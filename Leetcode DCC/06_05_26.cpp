#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/rotating-the-box/submissions/1996794439/?envType=daily-question&envId=2026-05-06
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Apply gravity (right direction)
        for (int i = 0; i < m; i++) {
            int write = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    write = j - 1;
                } 
                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][write]);
                    write--;
                }
            }
        }

        // Step 2: Rotate matrix
        vector<vector<char>> res(n, vector<char>(m));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = box[i][j];
            }
        }

        return res;
    }
};


int main(){
    
    return 0;
}