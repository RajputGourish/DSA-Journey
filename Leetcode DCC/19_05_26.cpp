#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2026-05-19
*/

int getCommon(vector<int>& n1, vector<int>& n2) {
        int i=0, j=0;
        while(i<n1.size() && j<n2.size()){
            if(n1[i] == n2[j]) return n1[i];
            if(n1[i] < n2[j]) i++;
            else j++;
        }
        return -1;
        
        // Time Complexity = O(min(n1, n2))
        // Space Complexity = O(1)
        
    }

int main(){
    
    return 0;
}