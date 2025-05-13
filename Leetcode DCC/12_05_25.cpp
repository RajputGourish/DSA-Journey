#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

*/
vector<int> findEvenNumbers(vector<int> &digits)
{
    set<int> uniqueNumbers;

    int n = digits.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j == i)
                continue;
            for (int k = 0; k < n; ++k)
            {
                if (k == i || k == j)
                    continue;

                int d1 = digits[i];
                int d2 = digits[j];
                int d3 = digits[k];

                if (d1 == 0)
                    continue; // leading zero not allowed
                if (d3 % 2 != 0)
                    continue; // must be even

                int number = d1 * 100 + d2 * 10 + d3;
                uniqueNumbers.insert(number);
            }
        }
    }

    return vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());
}

int main()
{
    vector<int> arr = {2, 1, 3, 0};
    vector<int> ans = findEvenNumbers(arr);

    return 0;
}