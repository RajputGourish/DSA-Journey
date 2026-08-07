#include<iostream>
#include<vector>
#include <array>
#include <algorithm>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/smallest-divisible-digit-product-ii/submissions/2098207417/?envType=daily-question&envId=2026-08-07
*/


class Solution {
public:

    // factors[d] = {count of 2, 3, 5, 7}
    int f[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    // Build the smallest number whose digit product
    // contains at least the required prime factors.
    string build(vector<long long> need) {

        long long c2 = need[0];
        long long c3 = need[1];

        string ans;

        // 5 and 7 cannot be combined with other primes.
        ans += string(need[2], '5');
        ans += string(need[3], '7');

        /*
            For 2 and 3:

            8 = 2^3
            9 = 3^2
            6 = 2 * 3
            4 = 2^2
        */

        // Use as many 8's as possible.
        ans += string(c2 / 3, '8');
        c2 %= 3;

        // Use as many 9's as possible.
        ans += string(c3 / 2, '9');
        c3 %= 2;

        // Pair remaining 2 and 3 into 6.
        long long six = min(c2, c3);

        ans += string(six, '6');

        c2 -= six;
        c3 -= six;

        // Remaining 2^2 -> 4
        ans += string(c2 / 2, '4');
        c2 %= 2;

        // Remaining 2
        ans += string(c2, '2');

        // Remaining 3
        ans += string(c3, '3');

        // To obtain the smallest number, sort digits.
        sort(ans.begin(), ans.end());

        return ans;
    }


    string smallestNumber(string num, long long t) {

        int n = num.size();

        // ------------------------------------------------
        // 1. Factorize t
        // ------------------------------------------------

        vector<long long> need(4, 0);

        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        // If t contains another prime factor,
        // no digit 1..9 can provide it.
        if (t != 1)
            return "-1";


        // ------------------------------------------------
        // 2. Get the minimum possible digit string
        // ------------------------------------------------

        string minimum = build(need);


        // ------------------------------------------------
        // IMPORTANT:
        //
        // If minimum already has MORE digits than num,
        // it is automatically greater than num.
        //
        // Example:
        // num = "12"
        // minimum = "255555579"
        //
        // Answer is simply minimum.
        // ------------------------------------------------

        if (minimum.size() > num.size())
            return minimum;


        // ------------------------------------------------
        // 3. Check whether num itself works
        // ------------------------------------------------

        vector<long long> total(4, 0);

        bool zero = false;

        for (char ch : num) {

            int d = ch - '0';

            if (d == 0)
                zero = true;

            for (int j = 0; j < 4; j++)
                total[j] += f[d][j];
        }

        bool valid = !zero;

        if (valid) {
            for (int j = 0; j < 4; j++) {
                if (total[j] < need[j]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
            return num;


        // ------------------------------------------------
        // 4. Prefix factor counts
        // ------------------------------------------------

        vector<array<long long, 4>> pref(n + 1);

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i];

            int d = num[i] - '0';

            for (int j = 0; j < 4; j++)
                pref[i + 1][j] += f[d][j];
        }


        // ------------------------------------------------
        // 5. Try changing a digit.
        //
        // RIGHT -> LEFT
        // ------------------------------------------------

        for (int i = n - 1; i >= 0; i--) {

            // Prefix must be zero-free.
            bool okPrefix = true;

            for (int j = 0; j < i; j++) {
                if (num[j] == '0') {
                    okPrefix = false;
                    break;
                }
            }

            if (!okPrefix)
                continue;


            int current = num[i] - '0';


            // Try the smallest digit greater than current.
            for (int d = current + 1; d <= 9; d++) {

                vector<long long> remaining(4);

                for (int j = 0; j < 4; j++) {

                    remaining[j] =
                        need[j]
                        - pref[i][j]
                        - f[d][j];

                    remaining[j] =
                        max(0LL, remaining[j]);
                }


                // Number of positions after i.
                int slots = n - i - 1;

                string suffix = build(remaining);


                // Remaining positions can be filled
                // with 1's.
                if ((int)suffix.size() <= slots) {

                    string ans;

                    // Original prefix
                    ans += num.substr(0, i);

                    // Increased digit
                    ans += char('0' + d);

                    // Fill unused places with 1.
                    ans += string(
                        slots - suffix.size(),
                        '1'
                    );

                    // Required factors
                    ans += suffix;

                    return ans;
                }
            }
        }


        // ------------------------------------------------
        // 6. No same-length answer.
        //
        // Since minimum.size() <= n here, we need
        // an n+1 digit answer.
        // ------------------------------------------------

        string suffix = build(need);

        return string(
            n + 1 - suffix.size(),
            '1'
        ) + suffix;
    }
};


int main(){
    
    return 0;
}