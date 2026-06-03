#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/submissions/2021483412/?envType=daily-question&envId=2026-06-03
*/

class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        auto solve = [&](vector<int>& Astart, vector<int>& Adur,
                         vector<int>& Bstart, vector<int>& Bdur) -> long long {
            int k = Bstart.size();

            vector<pair<long long,long long>> rides(k);
            for (int i = 0; i < k; i++) {
                rides[i] = {Bstart[i], Bdur[i]};
            }

            sort(rides.begin(), rides.end());

            vector<long long> starts(k);
            vector<long long> prefMinDur(k);
            vector<long long> suffMinOpenFinish(k);

            for (int i = 0; i < k; i++) {
                starts[i] = rides[i].first;
            }

            prefMinDur[0] = rides[0].second;
            for (int i = 1; i < k; i++) {
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    rides[i].second);
            }

            suffMinOpenFinish[k - 1] =
                rides[k - 1].first + rides[k - 1].second;

            for (int i = k - 2; i >= 0; i--) {
                suffMinOpenFinish[i] =
                    min(suffMinOpenFinish[i + 1],
                        rides[i].first + rides[i].second);
            }

            long long ans = LLONG_MAX;

            for (int i = 0; i < (int)Astart.size(); i++) {
                long long endTime =
                    (long long)Astart[i] + Adur[i];

                int pos =
                    upper_bound(starts.begin(), starts.end(), endTime)
                    - starts.begin();

                long long best = LLONG_MAX;

                if (pos > 0) {
                    best = min(best,
                               endTime + prefMinDur[pos - 1]);
                }

                if (pos < k) {
                    best = min(best,
                               suffMinOpenFinish[pos]);
                }

                ans = min(ans, best);
            }

            return ans;
        };

        long long landThenWater =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long waterThenLand =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(landThenWater, waterThenLand);
    }
};
int main(){
    
    return 0;
}