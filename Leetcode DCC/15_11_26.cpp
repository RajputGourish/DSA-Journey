#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2026-11-15
*/

// Brute
int Brute_numOfSubarrays(vector<int> &arr)
{
    const long long MOD = 1e9 + 7;
    int n = arr.size();
    long long countsubarr = 0;
    // generate all subarray
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum % 2 == 1)
            {
                countsubarr++;
            }
        }
    }

    return countsubarr % MOD;

    // Time Complexity = O(N^3)
    // Space Complexity = O(1)
}

// better
int Better_numOfSubarrays(vector<int> &arr)
{
    const long long MOD = 1e9 + 7;
    int n = arr.size();
    long long countsubarr = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum % 2 == 1)
            {
                countsubarr++;
            }
        }
    }

    return countsubarr % MOD;

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

// optimal
int Optimal_numOfSubarrays(vector<int> &arr)
{
    const long long MOD = 1e9 + 7;
    long long even = 1;
    long long odd = 0;

    long long countsubarr = 0;
    int prefParity = 0;

    for (int x : arr)
    {
        if (x % 2 != 0)
            prefParity ^= 1;

        if (prefParity == 0)
        {
            countsubarr = (countsubarr + odd) % MOD;
            even++;
        }
        else
        {
            countsubarr = (countsubarr + even) % MOD;
            odd++;
        }
    }

    return countsubarr;
    // Time Complexity = O(N)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> arr = {1, 3, 5};
    cout << Optimal_numOfSubarrays(arr) << endl;

    return 0;
}