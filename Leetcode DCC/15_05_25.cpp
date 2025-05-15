#include <iostream>
#include <vector>
using namespace std;
void display(vector<string> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*
        Problem link ->
                    https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=daily-question&envId=2025-05-15

*/

vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
{
    vector<string> ans;
    int flag = -1;
    for (int i = 0; i < groups.size(); i++)
    {
        if (groups.size() - i - 1 < ans.size())
            return ans;
        vector<string> temp;
        for (int j = i; j < groups.size(); j++)
        {
            if (flag != groups[j])
            {
                flag = groups[j];
                temp.push_back(words[j]);
            }
        }
        if (temp.size() >= ans.size())
        {
            ans = temp;
        }
    }
    return ans;

    // Time Complexity = O(N^2)
    // Space Complexity = O(N)
}
vector<string> Optimal_getLongestSubsequence(vector<string> &words, vector<int> &groups)
{
    vector<string> temp;
    int flag = -1;
    for (int j = 0; j < groups.size(); j++)
    {
        if (flag != groups[j])
        {
            flag = groups[j];
            temp.push_back(words[j]);
        }
    }
    return temp;

    // Time Complexity = O(N)
    // Space Complexity = O(N)
}
int main()
{
    vector<string> words = {"a", "b", "c", "d"};
    // vector<string> words = {"e", "a", "b"};
    vector<int> groups = {1, 0, 1, 1};
    // vector<int> groups = {0, 0, 1};
    // vector<string> ans = getLongestSubsequence(words, groups);
    vector<string> ans = Optimal_getLongestSubsequence(words, groups);
    display(ans);
    return 0;
}