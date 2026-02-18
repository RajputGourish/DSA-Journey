#include <iostream>
#include <vector>
using namespace std;

/*

    Problem Link :-
                https://leetcode.com/problems/binary-number-with-alternating-bits/?envType=daily-question&envId=2026-02-18
*/

bool hasAlternatingBits(int n)
{
    unsigned int x = n ^ (n >> 1);
    return (x & (x + 1)) == 0;
}

int main()
{
    cout<<hasAlternatingBits(3)<<endl;
    return 0;
}