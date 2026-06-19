#include<iostream>
#include<vector>
using namespace std;


/*
Problem Link =>
              https://leetcode.com/problems/find-the-highest-altitude/description/?envType=daily-question&envId=2026-06-19
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;

        for (int g : gain) {
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};

int main(){
    
    return 0;
}