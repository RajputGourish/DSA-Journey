#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06
*/

int smallestNumber(int n, int t)
{
    while (true)
    {
        int p = 1;
        int num = n;
        while (num != 0)
        {
            p = p * (num % 10);
            num = num / 10;
        }
        if (p % t == 0)
            return n;
        n++;
    }
    return -1;
}

int main()
{
    cout << smallestNumber(21, 7) << endl;

    return 0;
}