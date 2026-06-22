#include<iostream>
#include<vector>
using namespace std;


/*
Problem Link =>
              https://leetcode.com/problems/maximum-number-of-balloons/submissions/2041968994/?envType=daily-question&envId=2026-06-22
*/


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        for(char c:text){
            if(c == 'b') b++;
            if(c == 'a') a++;
            if(c == 'l') l++;
            if(c == 'o') o++;
            if(c == 'n') n++;
        }

        l = l/2;
        o = o/2;
        return min(b, min(a, min(l, min(o, n))));
    }
};

int main(){
    
    return 0;
}