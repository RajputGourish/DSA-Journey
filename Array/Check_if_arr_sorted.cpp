#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int cnt = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int right = arr[(i + 1) % n];
            if (arr[i] > right)
                cnt++;
            if (cnt > 1)
                return false;
        }
        return cnt <= 1 ? true : false;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution s;
    cout << s.check(arr) << endl;

    return 0;
}