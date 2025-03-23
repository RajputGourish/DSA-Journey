#include <iostream>
#include <vector>
using namespace std;
/*
    Problem Link -> https://leetcode.com/problems/single-number
*/
int SingleNumber(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {2, 3, 1, 3, 4, 4, 2};
    cout << SingleNumber(arr) << endl;

    return 0;
}