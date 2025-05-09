#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Problem link ->
                    https://leetcode.com/problems/two-sum
*/

vector<int> Brute_twoSum(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};

    
    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
    
}

vector<int> Optimal_twoSum(vector<int> &arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int findelement = target - arr[i];
        if (mpp.find(findelement) != mpp.end())
        {
            return {i, mpp[findelement]};
        }
        mpp[arr[i]] = i;
    }
    return {-1, -1};

    // Time Complexity = O(N)
    // Space Complexity = O(N)
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans1 = Brute_twoSum(arr, target);
    cout << "Brute Answer = " << " ";
    for (int i = 0; i < 2; i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = Optimal_twoSum(arr, target);
    cout << "Optimal Answer = " << " ";

    for (int i = 0; i < 2; i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}
