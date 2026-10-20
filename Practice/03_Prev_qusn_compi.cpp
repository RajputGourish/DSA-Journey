#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/palindrome-number/description/
*/

// Approach 1
bool isPalindrome(int n)
{
    if (n < 0)
        return false;
    int copy = n;
    int rev = 0;
    while (copy != 0)
    {
        rev *= 10;
        rev += copy % 10;
        copy /= 10;
    }

    if (rev == n)
        return true;
    return false;
}

int main()
{

    return 0;
}