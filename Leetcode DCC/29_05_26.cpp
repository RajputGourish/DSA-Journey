#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/?envType=daily-question&envId=2026-05-29
*/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
             string elm = to_string(nums[i]);
             int sum = 0;
             for(char ch : elm){
                sum = sum + (ch - '0');
                if(sum > mini) break;
             }
             mini = min(sum, mini);
        }
        return mini;
    }
};

int main(){
    
    return 0;
}