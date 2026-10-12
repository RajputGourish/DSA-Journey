#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/sum-of-squares-of-special-elements/description/?envType=daily-question&envId=2026-10-11
*/

int sumOfSquares(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (n % (i + 1) == 0)
        {
            sum += nums[i] * nums[i];
        }
    }
    return sum;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};

    cout<<sumOfSquares(arr)<<endl;
    

    return 0;
}