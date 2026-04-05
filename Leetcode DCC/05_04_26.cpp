#include <iostream>
#include <vector>
using namespace std;

/*
    Problem Link=>
                    https://leetcode.com/problems/robot-return-to-origin/submissions/1969856157/?envType=daily-question&envId=2026-04-05
*/
bool judgeCircle(string s)
{
    int Y = 0, X = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'U')
            Y++;
        else if (s[i] == 'L')
            X++;
        else if (s[i] == 'R')
            X--;
        else
            Y--;
    }
    return (X == 0 && Y == 0);
}

int main()
{
    string moves = "UURRLLLRDRD";
    cout << judgeCircle(moves)<< endl;

    return 0;
}