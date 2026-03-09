#include <iostream>
#include <vector>
using namespace std;

int minOperations(string s)
{
    int cnt = 0;
    if (s.size() < 2)
        return 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            (s[i] == 0) ? s[i] = 1 : s[i] = 0;
        }
    }
    return cnt;
}
int main()
{
    string s = "10010100";
    
    cout << minOperations(s) << endl;

    return 0;
}