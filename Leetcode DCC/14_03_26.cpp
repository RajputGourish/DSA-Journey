#include<iostream>
#include<vector>
using namespace std;

/*
    Problem link => 
                https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/submissions/1948304030/?envType=daily-question&envId=2026-03-14
*/


class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(int n, int k, string curr) {
        if(curr.length() == n) {
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                solve(n, k, curr + c);
                if(ans != "") return;
            }
        }
    }

    string getHappyString(int n, int k) {
        solve(n, k, "");
        return ans;
    }
};


int main(){
    
    return 0;
}