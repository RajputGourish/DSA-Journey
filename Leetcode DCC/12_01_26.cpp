#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link -
                    https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12
*/

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &p)
    {
        if (p.size() == 1)
            return 0;
        int totalseconds = 0;
        for (int i = 1; i < p.size(); i++)
        {
            int a = abs(p[i][0] - p[i - 1][0]);
            int b = abs(p[i][1] - p[i - 1][1]);
            totalseconds += max(a, b);
        }

        return totalseconds;
    }
};

int main()
{
    vector<vector<int>> p = {{3, 2}, {-2, 2}};
    Solution s;
    cout << s.minTimeToVisitAllPoints(p) << endl;
    return 0;
}