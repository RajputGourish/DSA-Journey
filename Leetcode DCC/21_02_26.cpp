#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link =>
            https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/1926558750/?envType=daily-question&envId=2026-02-21
*/
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right)
    {
        int count = 0;

        for (int i = left; i <= right; i++)
        {
            int setBits = __builtin_popcount(i); // counts number of 1s
            if (isPrime(setBits))
            {
                count++;
            }
        }

        return count;
    }
};
int main()
{
    int left = 6, right = 10;
    Solution s;
    cout << s.countPrimeSetBits(left, right) << endl;

    return 0;
}