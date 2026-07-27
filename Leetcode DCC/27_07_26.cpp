#include<iostream>
#include<vector>
#include <climits>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/2082940716/?envType=daily-question&envId=2026-07-27
*/  

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for(int i=0; i<a.size(); i++){
            int d = a[i];
            if(max1<d){
                max2 = max1;
                max1 = d;
            }
            else if(max2<d){
                max2 = d;
            }
        }
        return (max1-1)*(max2-1);
    }
};


int main(){
    
    return 0;
}
