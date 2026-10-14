#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14
*/

string maxSumOfSquares(int num, int sum)
{
    if (sum > 9 * num)
        return "";

    string ans = "";

    for (int i = 0; i < num; i++)
    {
        int digit = min(9, sum);
        ans += to_string(digit);
        sum -= digit;
    }

    if (sum > 0)
        return "";

    return ans;

    // Time Complexity = O(num)
    // Space Complexity = O(num)
}

int main()
{
    int n = 7, sum = 64;
    cout << maxSumOfSquares(n, sum) << endl;

    return 0;
}