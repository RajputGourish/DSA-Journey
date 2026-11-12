#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2026-11-12
*/

int Brute_longestMonotonicSubarray(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    int strictlyInc = 1;
    int strictlyDec = 1;
    // generate all subarray
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int len1 = 1;
            int len2 = 1;
            for (int k = i + 1; k <= j; k++)
            {
                if (arr[k - 1] < arr[k])
                {
                    len1++;
                }
                else
                {
                    len1 = 1;
                }
                if (arr[k - 1] > arr[k])
                {
                    len2++;
                }
                else
                {
                    len2 = 1;
                }
            }

            strictlyInc = max(strictlyInc, len1);
            strictlyDec = max(strictlyDec, len2);
        }
    }
    // cout << "{ " << strictlyInc << " ," << strictlyDec << " }" << endl;

    return max(strictlyInc, strictlyDec);

    // Time Complexity = O(n^3)
    // Space Complexity = O(1)
}

int Better_longestMonotonicSubarray(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    int strictlyInc = 1;
    int strictlyDec = 1;
    // generate all subarray
    for (int i = 0; i < n; i++)
    {
        int len1 = 1;
        int len2 = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j - 1] < arr[j])
            {
                len1++;
            }
            else
            {
                len1 = 1;
            }

            if (arr[j - 1] > arr[j])
            {
                len2++;
            }
            else
            {
                len2 = 1;
            }

            strictlyInc = max(strictlyInc, len1);
            strictlyDec = max(strictlyDec, len2);
        }
    }
    cout << "{ " << strictlyInc << " ," << strictlyDec << " }" << endl;

    return max(strictlyInc, strictlyDec);

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

int Optimal_longestMonotonicSubarray(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    int strictlyInc = 1;
    int strictlyDec = 1;

    int maxlen1 = 1;
    int maxlen2 = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] < arr[i])
        {
            strictlyInc++;
            strictlyDec = 1;
            maxlen1 = max(strictlyInc, maxlen1);
        }
        else if (arr[i - 1] > arr[i])
        {
            strictlyInc = 1;
            strictlyDec++;
            maxlen2 = max(strictlyDec, maxlen2);
        }
        else
        {
            strictlyInc = 1;
            strictlyDec = 1;
        }
        // len1 = (arr[i - 1] < arr[i]) ? len1 + 1 : 1;
        // len2 = (arr[i - 1] > arr[i]) ? len2 + 1 : 1;
    }

    return max(strictlyInc, strictlyDec);

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> arr = {1, 4, 3, 3, 2};
    // vector<int> arr = {1, 2, 3};
    cout << Optimal_longestMonotonicSubarray(arr) << endl;

    return 0;
}