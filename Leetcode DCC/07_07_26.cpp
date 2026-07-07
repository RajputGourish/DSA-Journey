#include<iostream>
#include<vector>
using namespace std;


/*
Problem Link =>
              https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07
*/

class Solution {
public:
    int reverse(int n)
    {
        int revnum = 0;
        while (n != 0)
        {
            if (n % 10 != 0)
            {
                int digit = n % 10;
                revnum = revnum * 10 + digit;
            }
            n = n / 10;
        }
        return revnum;
    }

    long long sumAndMultiply(int n)
    {
        int x = reverse(reverse(n));
        int sum = 0;
        while (n != 0)
        {
            int digit = n % 10;
            sum += digit;
            n = n / 10;
        }
        long long ans = (long long)x*(long long)sum;
        return ans;
    }
};


int main(){
    
    return 0;
}