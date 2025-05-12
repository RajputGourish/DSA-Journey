#include <iostream>
#include <vector>
using namespace std;

/*
    Problem ->
            https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2025-05-11

*/
bool threeConsecutiveOdds(vector<int> &arr)
{
    int conse = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        conse = (arr[i] & 1) == 1 ? conse + 1 : 0;
        if (conse >= 3)
            return true;
    }
    return false;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    // vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    vector<int> arr = {2, 6, 4, 1};
    cout << threeConsecutiveOdds(arr) << endl;

    return 0;
}