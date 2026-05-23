#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23
*/

class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();

        for(int i=0; i<n; i++){
            int right = arr[(i+1)%n];
            if(arr[i]>right) cnt++;
            if(cnt > 1) return false;
        }
        return cnt<=1?true:false;
    }
};

int main(){
    
    return 0;
}