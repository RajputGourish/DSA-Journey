#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> count(maxCost + 1, 0);

        for (int cost : costs) {
            count[cost]++;
        }

        int bars = 0;

        for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
            if (count[cost] == 0) continue;

            int canBuy = min(count[cost], coins / cost);
            bars += canBuy;
            coins -= canBuy * cost;
        }

        return bars;
    }
};

int main(){
    
    return 0;
}