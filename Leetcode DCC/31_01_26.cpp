#include <iostream>
#include <vector>
using namespace std;

/*

    Problem link:-
                    https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/1903411062/?envType=daily-question&envId=2026-01-31

*/

class Solution
{
public:
    char nextGreatestLetter(vector<char> &l, char t)
    {
        int low = 0, high = l.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (l[mid] <= t)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // wrap around
        return l[low % l.size()];
    }
};

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';

    return 0;
}