#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link ->
            https://leetcode.com/problems/range-sum-query-immutable/?envType=problem-list-v2&envId=array
*/

class NumArray
{

public:
    vector<int> arr;
    NumArray(vector<int> &nums)
    {
        arr.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            arr[i + 1] = arr[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return arr[right + 1] - arr[left];
    }
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray N(nums);
    cout<<N.sumRange(0, 2)<<endl;
    cout<<N.sumRange(2, 5)<<endl;
    cout<<N.sumRange(0, 5)<<endl;
    
    
    return 0;
}