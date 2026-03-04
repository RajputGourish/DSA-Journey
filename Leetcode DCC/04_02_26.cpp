#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link ==>
            https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2026-03-04
*/

bool check(vector<vector<int>>& mat, int row, int col){
        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]==1 && i!= row) return false;
        }
        for(int i=0; i<mat[0].size(); i++){
            if(mat[row][i] ==1 && i!= col) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    cnt += (check(mat, i, j));
                }
            }
        }
        return cnt;
    }

int main(){
    
    return 0;
}