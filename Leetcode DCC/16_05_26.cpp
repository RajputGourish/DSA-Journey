#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-15
*/

int findMin(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[0];
    
    // Time Complexity = O(NlogN)
    // Space Complexity = O(1)
    
}
    int Optimal_findMin(vector<int>& arr) {
        int n = arr.size();
        // Single Element
        if(n == 1) return arr[0];
        // Sorted Array
        if(arr[0] < arr[n-1]) return arr[0];
        // Unsorted array
        // Binary Search
        int mini = INT_MAX;
        int low =0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[low] <= arr[mid]){
                mini = min(mini, arr[low]);
                low = mid+1;
            }
            else{
                mini = min(mini, arr[mid]);
                high = mid-1;
            }
        }

        return mini;
        
        // Time Complexity = O(logN)
        // Space Complexity = O(1)
        
    }
int main()
{

    return 0;
}