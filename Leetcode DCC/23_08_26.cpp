#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
                https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23
*/

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int qDiff = leftQ - rightQ;
        int sumDiff = leftSum - rightSum;

        // Odd difference in number of '?' -> Alice wins
        if (abs(qDiff) % 2 == 1)
            return true;

        // Bob can balance the sums if this condition holds
        return 2 * sumDiff != 9 * (rightQ - leftQ);
    }
};

int main(){
    
    return 0;
}