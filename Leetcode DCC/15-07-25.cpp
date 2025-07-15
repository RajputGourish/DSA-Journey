#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link =>
                https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15
*/
class Solution
{
public:
    bool isValid(string word)
    {
        bool vowel = false;
        bool consonent = false;
        if (word.size() < 3)
            return false;
        for (char c : word)
        {
            if ((48 > c || 57 < c) && (65 > c || 122 < c))
            {
                return false;
            }
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowel = true;
            else if ((65 <= c && 122 >= c))
                consonent = true;
        }
        if (consonent && vowel)
            return true;
        return false;

        // Time Complexity = O(N)
        // Space Complexity = O(1)
    }
};

int main()
{
    // string word = "234Ads";
    // string word = "a3$e";
    string word = "$Ya";
    Solution s;
    (s.isValid(word) == 1) ? cout << "True" : cout << "False";
    cout << endl;

    return 0;
}