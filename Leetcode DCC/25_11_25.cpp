#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem link:
                https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

*/

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        long long n = 0;
        int digit = 0;

        cout << "start" << endl;
        while (n < LLONG_MAX)
        {
            n = n * 10 + 1; digit++;
            if(n>=LLONG_MAX) break;
            if (n % k == 0) return digit;
        }
        return -1;
    }
};
int main()
{
    int k = 5;
    Solution s;
    cout << s.smallestRepunitDivByK(k) << endl;
    return 0;
}