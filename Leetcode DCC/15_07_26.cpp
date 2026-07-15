#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
                https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/?envType=daily-question&envId=2026-07-15
*/

int gcdOfOddEvenSums(int n)
{
    int sumodd = 0;
    int sumeven = 0;
    int ans = 1;
    for (int i = 1; i <= n * 2; i++)
    {

        if (i % 2 == 0)
            sumeven += i;
        else
            sumodd += i;
    }

    for (int i = n * 2; i >= 1; i--)
    {
        if (sumodd % i == 0 && sumeven % i == 0)
        {
            ans = max(ans, i);
            break;
        }
    }

    return ans;

    // Time Complexity = O(2N)
    // Space Complexity = O(1)
}
int gcdOfOddEvenSums(int n)
{
    return n;
    // Time Complexity = O(1)
    // Space Complexity = O(1)
}

int main()
{
    cout << gcdOfOddEvenSums(12) << endl;

    return 0;
}