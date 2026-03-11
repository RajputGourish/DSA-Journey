#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link =>
                https://leetcode.com/problems/complement-of-base-10-integer/submissions/1944961410/?envType=daily-question&envId=2026-03-11

*/

int bitwiseComplement(int n)
{
    if (n == 0)
        return 1;

    int mask = 0, temp = n;

    while (temp)
    {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return n ^ mask;
}

int main()
{
    cout<<bitwiseComplement(7)<<endl;
    
    return 0;
}