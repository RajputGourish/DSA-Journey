#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem =>
            https://leetcode.com/problems/special-binary-string/submissions/1925491493/?envType=daily-question&envId=2026-02-20

*/

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        vector<string> subs;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                count++;
            else
                count--;

            // Found a special substring
            if (count == 0)
            {
                // Remove outer 1 and 0, recurse inside
                string inner = s.substr(start + 1, i - start - 1);
                subs.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort descending
        sort(subs.begin(), subs.end(), greater<string>());

        // Combine
        string result;
        for (auto &str : subs)
            result += str;

        return result;
    }
};

int main()
{

    return 0;
}