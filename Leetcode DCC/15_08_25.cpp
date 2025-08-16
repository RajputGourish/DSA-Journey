#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/power-of-four/?envType=daily-question&envId=2025-08-15
*/

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        else if (n == 1)
            return true;
        return (n % 4) ? false : isPowerOfFour(n / 4);
    }
};
int main()
{
    Solution s;
    s.isPowerOfFour(16);
    return 0;
}