#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/distribute-elements-into-two-arrays-i/submissions/2114199198/?envType=daily-question&envId=2026-08-20
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr2 after arr1
        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};

int main(){
    
    return 0;
}