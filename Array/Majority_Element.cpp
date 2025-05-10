#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
    Problem Link -->
                https://leetcode.com/problems/majority-element

*/

int Brute_majorityElement(vector<int> &nums)
{
    int size = nums.size();
    int minfreqreq = size / 2 + 1;
    sort(nums.begin(), nums.end());
    int countcurr = 0;
    for (int i = 0; i < size; i++)
    {
        countcurr++;
        if (countcurr >= minfreqreq)
            return nums[i];
        if (nums[i] != nums[i + 1])
        {
            countcurr = 0;
        }
    }
    return -1;

    // Time Complexity = O(NlogN + N)
    // Space Complexity = O(1)
}

int Brute2_majorityElement(vector<int> &nums)
{
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > nums.size() / 2)
            return it.first;
    }
    return -1;

    // Time Complexity = O(nlogn + n)
    // Space Complexity = O(n)
}

int Better_majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];

    // Time Complexity = O(NlogN)
    // Space Complexity = O(1)
}
int optimal_majorityElement(vector<int> &nums)
{
    // Moore’s Voting Algorithm

    int n = nums.size();
    int count = 0;
    int element;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = nums[i];
        }
        else if (element != nums[i])
            count--;
        else
        {
            count++;
        }
    }

    return element;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << Brute_majorityElement(arr) << endl;
    cout << Better_majorityElement(arr) << endl;
    cout << optimal_majorityElement(arr) << endl;
    return 0;
}