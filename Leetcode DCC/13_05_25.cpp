#include <iostream>
#include <vector>
using namespace std;

int lengthAfterTransformations(string s, int t)
{
    while (t)
    {
        string next = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'z')
            {
                next += "ab";
            }
            else
                next += s[i] + 1;
        }
        s = next;
        t--;
    }
    return s.size();

    // TLE
}

// optimal -> dp

int main()
{
    string s = "bcdzz";
    int t = 1;
    cout << lengthAfterTransformations(s, t) << endl;
    return 0;
}