#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void display(vector<int> &arr, int i, int j)
{
    for (; i <= j; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// brute Generate all subbarray

void Brute_Subbarr_GivenSum(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == target)
            {
                display(arr, i, j);
            }
        }
    }

    // Time Complexity = O(N^3)
    // Space Complexity = O(1)
}

// Better Generate all subbarray

void Better_Subbarr_GivenSum(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                display(arr, i, j);
            }
        }
    }

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

// Optimal

void Optimal_Subbarr_GivenSum(vector<int> &arr, int target)
{
    unordered_map<long long, vector<int>> mpp;
    long long sum = 0;
    mpp[0].push_back(-1);
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int rem = sum - target;

        if (mpp.find(rem) != mpp.end())
        {
            for (int idx : mpp[rem])
            {
                display(arr, idx + 1, i);
            }
        }

        mpp[sum].push_back(i);
    }

    // Time Complexity = O(N+k)
    // Space Complexity = O(N)
}

int main()
{
    vector<int> arr = {3, 4, -7, 1, 3, 3, 1, -4};
    int target = 7;
    Brute_Subbarr_GivenSum(arr, target);
    cout << endl;

    Better_Subbarr_GivenSum(arr, target);
    cout << endl;

    Optimal_Subbarr_GivenSum(arr, target);
    return 0;
}