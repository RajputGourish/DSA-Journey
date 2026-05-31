#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31
*/


// Wrong
bool asteroidsDestroyed1(int mass, vector<int> &asteroids)
{
    for (int i = 0; i < asteroids.size(); i++)
    {
        mass = (mass >= asteroids[i]) ? (mass + asteroids[i]) : (mass - asteroids[i]);
    }

    return (mass >= 0) ? true : false;
}


// Right
bool asteroidsDestroyed(int mass, vector<int> &asteroids)
{
    sort(asteroids.begin(), asteroids.end());

    long long curMass = mass;

    for (int asteroid : asteroids)
    {
        if (curMass < asteroid)
        {
            return false;
        }
        curMass += asteroid;
    }

    return true;
}

int main()

{
    vector<int> arr = {4, 9, 23, 4};

    if (asteroidsDestroyed1(5, arr) == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}