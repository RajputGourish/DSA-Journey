#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
                https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/?envType=daily-question&envId=2026-11-01

*/

// Brute
int Brute_minMoves(vector<int> &arr)
{
    int ans = 0;

    while (true)
    {
        int minind = 0, maxind = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[minind] > arr[i])
            {
                minind = i;
            }
            if (arr[maxind] < arr[i])
            {
                maxind = i;
            }
        }
        int diff = arr[maxind] - arr[minind];
        if (diff == 0)
            return ans;
        ans = ans + diff;
        for (int i = 0; i < arr.size(); i++)
        {
            if (maxind == i)
                continue;
            arr[i] = arr[i] + diff;
        }
    }

    return ans;

    // TLE
    // Time Complexity = O( ansx(N+N) )
    // Space Complexity = O(1)
}

// Better
int Optimal_minMoves(vector<int> &arr)
{
    long long sum = 0;
    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        mini = min(mini, arr[i]);
    }

    return sum - (long long)arr.size() * mini;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{

    vector<int> arr = {1, 2, 3};
    // cout << Brute_minMoves(arr) << endl;
    cout << Optimal_minMoves(arr) << endl;

    return 0;
}