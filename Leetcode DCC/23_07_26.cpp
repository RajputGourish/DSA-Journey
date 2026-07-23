#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/number-of-unique-xor-triplets-i/?envType=daily-question&envId=2026-07-23
*/

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
            return n;

        int ans = 1;
        while (ans <= n)
            ans <<= 1;

        return ans;
    }
};
int main()
{

    return 0;
}