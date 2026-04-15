#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    Problem Link = >
                https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/?envType=daily-question&envId=2026-04-15
*/

void display(vector<string> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int closestTarget(vector<string> &words, string target, int startIndex)
{
    vector<string> my;
    my.insert(my.end(), words.begin(), words.end());
    my.insert(my.end(), words.begin(), words.end());
    my.insert(my.end(), words.begin(), words.end());
    display(my);
    int minindleft = -1;
    startIndex = startIndex + words.size();
    for (int i = startIndex - 1; i >= 0; i--)
    {
        if (target == my[i])
        {
            minindleft = i;
            break;
        }
    }
    int minindright = -1;
    for (int i = startIndex; i < my.size(); i++)
    {
        if (target == my[i])
        {
            minindright = i;
            break;
        }
    }
    if (minindleft == -1 || minindright == -1)
        return -1;
    int a = min(startIndex - minindleft, minindright - startIndex);

    return a;
}


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
    // vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    // vector<string> words = {"a", "b", "leetcode"};
    vector<string> words = {"i","eat","leetcode"};
    string target = "ate";
    int startIndex = 0;
    cout << closestTarget(words, target, startIndex) << endl;

    return 0;
}