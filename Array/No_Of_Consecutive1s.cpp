#include <iostream>
#include <vector>
using namespace std;
/*
    Problem Link -> https://leetcode.com/problems/max-consecutive-ones
*/
int Consecutive_Ones(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0, cons = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cons++;
            maxi = max(maxi, cons);
        }
        else
            cons = 0;
    }
    return maxi;
    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    cout << Consecutive_Ones(arr) << endl;

    return 0;
}