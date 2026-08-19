#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/cinema-seat-allocation/description/?envType=daily-question&envId=2026-08-19
*/


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row;

        // Store reserved seats as bits
        for (auto &seat : reservedSeats) {
            int r = seat[0];
            int s = seat[1];

            row[r] |= (1 << (s - 1));
        }

        int ans = 0;

        for (auto &[r, mask] : row) {

            // Both groups: 2-5 and 6-9
            if ((mask & 0b0111111110) == 0) {
                ans += 2;
            }
            else {
                // Group: 2-5
                bool left = (mask & 0b000011110) == 0;

                // Group: 4-7
                bool middle = (mask & 0b001111000) == 0;

                // Group: 6-9
                bool right = (mask & 0b111100000) == 0;

                if (left || middle || right) {
                    ans += 1;
                }
            }
        }

        // Rows with no reservations
        ans += (n - row.size()) * 2;

        return ans;
    }
};
int main(){
    
    return 0;
}