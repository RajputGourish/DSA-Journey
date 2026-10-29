#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/stone-game-ix/description/?envType=daily-question&envId=2026-08-16
*/

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {

        int cnt[3] = {0};

        for (int x : stones)
        {
            cnt[x % 3]++;
        }

        if (cnt[0] % 2 == 0)
        {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

int main()
{

    return 0;
}