#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26
*/

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int numberOfSpecialChars(string w)
{
    int ans = 0;
    vector<int> small(26, 0);
    vector<int> big(26, 0);

    // display(small);
    // display(big);

    cout << int('A') - 65 << endl;
    cout << int('Z') - 65 << endl;
    cout << int('a') << endl;
    cout << int('z') << endl;

    for (int i = 0; i < w.size(); i++)
    {
        int c = w[i];
        if (65 <= c && c <= 90)
        {
            // big
            big[c - 65]++;
        }
        else
        {
            // small
            small[c - 97]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (small[i] != 0 && big[i] != 0)
            ans++;
    }
``
    return ans;
}

int main()
{
    cout << numberOfSpecialChars("aabcdADVZz") << endl;
    return 0;
}