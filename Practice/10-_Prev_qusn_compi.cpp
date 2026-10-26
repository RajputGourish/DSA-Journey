#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/container-with-most-water/description/
*/

// brute
int maxArea(vector<int> &height)
{
    int maxar = 0;
    int n = height.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int area = (j - i) * min(height[i], height[j]);
            maxar = max(maxar, area);
        }
    }
    return maxar;

    // TLE
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
}

// optimal
int maxArea2(vector<int> &height)
{
   
    int maxarea = 0;
    int i = 0;
    int j = height.size()-1;
    while(i<j){
        int area = min(height[i], height[j])*(j-i);
        maxarea = max(maxarea, area);
        if(height[i]<height[j]){
            i++;
        }
        else j--;
    }

    return maxar;
    // Time Complexity = O(n)
    // Space Complexity = O(1)
}

int main()
{

    // vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> arr = {1, 2, 1};

    cout << maxArea2(arr) << endl;

    return 0;
}