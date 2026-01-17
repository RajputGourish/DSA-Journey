#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link ->
                    https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17

*/

class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft,
                                vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long overlapWidth =
                    min(topRight[i][0], topRight[j][0]) -
                    max(bottomLeft[i][0], bottomLeft[j][0]);

                long long overlapHeight =
                    min(topRight[i][1], topRight[j][1]) -
                    max(bottomLeft[i][1], bottomLeft[j][1]);

                if (overlapWidth > 0 && overlapHeight > 0)
                {
                    long long side = min(overlapWidth, overlapHeight);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3},
                                    {4, 4},
                                    {6, 6}};

    Solution s;
    cout << s.largestSquareArea(bottomLeft, topRight) << endl;

    return 0;
}