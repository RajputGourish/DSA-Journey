#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2026-02-26

*/

int numSteps(string s)
{
    int steps = 0;
    int carry = 0;

    // start from right side
    for (int i = s.size() - 1; i > 0; i--)
    {
        int bit = (s[i] - '0') + carry;

        if (bit == 1)
        {
            // odd → add 1 then divide
            steps += 2;
            carry = 1;
        }
        else
        {
            // even → divide by 2
            steps += 1;
        }
    }

    return steps + carry;
}

int main()
{
    cout<<numSteps("1101")<<endl;
    return 0;
}