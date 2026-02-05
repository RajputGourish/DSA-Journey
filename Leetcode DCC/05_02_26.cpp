#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/transformed-array/?envType=daily-question&envId=2026-02-05
*/

void display(vector<int> &n)
{
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i] << " ";
    }
    cout << endl;
}

// 3 -2 1 1 3 -2 1 1

void constructTransformedArray(vector<int> &nums)
{
    int len = nums.size();
    vector<int> res(len, 0);
    vector<int> rep(nums);
    for (int i = 0; i < len; i++)
    {
        rep.push_back(nums[i]);
    }
    display(rep);
    for (int i = 0; i < len; i++)
    {
        int nm = abs(nums[i]) % len;
        if (nums[i] > 0)
        {
            res[i] = rep[i + nm];
        }
        else if (nums[i] < 0)
        {
            res[i] = rep[len + i - nm];
        }
    }
    display(res);
}

int main()
{
    // vector<int> arr = {3, -2, 1, 1};
    vector<int> arr = {-1, 4, -1};
    constructTransformedArray(arr);
    return 0;
}