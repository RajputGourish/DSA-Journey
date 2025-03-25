#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

    Problem link ->
            https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
*/
int Brute_longestSubarray(vector<int> &arr, int k)
{
    // generate all the subarray
    int n = arr.size();
    int maxsub = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                maxsub = max(maxsub, j - i + 1);
            }
        }
    }
    return maxsub;
    // TLE (Time limit Exceed)
    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}
//  #Hashing
//  aplicable to negative and positive too
int Optimal_longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> presumMap;
    int sum = 0;
    int maxsub = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum == k)
        {
            maxsub = max(maxsub, i + 1);
        }

        int rem = sum - k;

        if (presumMap.find(rem) != presumMap.end())
        {
            int len = i - presumMap[rem];
            maxsub = max(maxsub, len);
        }

        if (presumMap.find(sum) == presumMap.end())
        {
            presumMap[sum] = i;
        }
    }
    return maxsub;

    // Time Complexity = O(N)
    // Space Complexity = O(N)
}
// Sliding window(expand or shrink)
// aplicable for positive integer only
int Optimal2_longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxsub = 0;
    int sum = arr[0];
    int l = 0;
    int r = 0;

    while (r < n)
    {
        while (sum > k && l <= r)
        {
            sum = sum - arr[l];
            l++;
        }
        if (sum == k)
        {
            maxsub = max(maxsub, r - l + 1);
        }

        r++;
        if (r < n)
        {
            sum = sum + arr[r];
        }
    }

    return maxsub;
    // Time Complexity = O(2N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    vector<int> arr2 = {10, 5, 2, 7, 1};
    int k = 15;
    cout << "Brute -> " << Brute_longestSubarray(arr, k) << endl;
    cout << "Better -> " << Optimal_longestSubarray(arr, k) << endl;
    cout << "Optimal -> " << Optimal2_longestSubarray(arr, k) << endl;

    return 0;
}