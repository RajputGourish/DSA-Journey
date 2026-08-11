#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11
*/

class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        int presum = a[0];
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]+1) presum += a[i];
            else break;
        } 
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            if(a[i]==presum){
                presum++;
            }
        }
        return presum;
    }
};


int main(){
    
    return 0;
}