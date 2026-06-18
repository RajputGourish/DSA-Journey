#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/angle-between-hands-of-a-clock/submissions/?envType=daily-question&envId=2026-06-18
*/

double angleClock(int hour, int minutes)
{
    if (hour == 12)
        hour = 0;
    double ans = abs((30 * hour) - (5.5 * minutes));
    return min(ans, 360.0 - ans);
}

int main()
{
    
    return 0;
}