#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/2010770048/?envType=daily-question&envId=2026-05-22
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0; 
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                if((nums[low] <= target && nums[mid]>= target)){
                     high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && nums[high]>= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }};

int main(){
    
    return 0;
}