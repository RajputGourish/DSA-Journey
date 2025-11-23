#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Link ->
                https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/?envType=daily-question&envId=2025-11-22

*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int op = 0;
        for(int i :nums){
            int mod = i % 3;
             if(mod != 0) op++;
             
        }
        return op;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4};
    cout<<s.minimumOperations(arr)<<endl;
    return 0;
}