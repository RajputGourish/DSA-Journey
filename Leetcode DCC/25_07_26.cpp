#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/maximum-product-of-two-digits/description/?envType=daily-question&envId=2026-07-25
*/

class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int secmaxi = 0;
        while(n != 0){
            int dig = n%10;
            if(dig > maxi){
                secmaxi = maxi;
                maxi = dig;
            }
            else if(secmaxi < dig){
                secmaxi = dig;
            }
            n /= 10;
        }
        return maxi*secmaxi;
    }
};

int main(){
    
    return 0;
}