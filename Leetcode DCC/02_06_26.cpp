#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/?envType=daily-question&envId=2026-06-02
*/

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            long long landFinish = (long long)landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++)
            {
                long long waterFinish = (long long)waterStartTime[j] + waterDuration[j];

                // Land -> Water
                long long finish1 =
                    max((long long)waterStartTime[j], landFinish) +
                    waterDuration[j];

                // Water -> Land
                long long finish2 =
                    max((long long)landStartTime[i], waterFinish) +
                    landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return (int)ans;
    }
};
int main()
{

    return 0;
}