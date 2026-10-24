#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/count-days-spent-together/description/?envType=daily-question&envId=2026-10-24
*/

int convertToDays(string date)
{
    vector<int> days = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));

    int totalDays = day;

    for (int i = 0; i < month - 1; i++)
    {
        totalDays += days[i];
    }

    return totalDays;
}

int countDaysTogether(string arriveAlice, string leaveAlice,
                      string arriveBob, string leaveBob)
{

    int a1 = convertToDays(arriveAlice);
    int a2 = convertToDays(leaveAlice);

    int b1 = convertToDays(arriveBob);
    int b2 = convertToDays(leaveBob);

    int start = max(a1, b1);
    int end = min(a2, b2);

    return max(0, end - start + 1);
}
int main()
{
    string arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19";

    cout << countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob) << endl;

    return 0;
}