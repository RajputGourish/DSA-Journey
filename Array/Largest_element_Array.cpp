#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr)
    {
        int maxi = INT_MIN;
        for (auto it : arr)
        {
            maxi = max(maxi, it);
        }
        return maxi;
    }
};
int main()
{
    vector<int> arr = {2, 4, 5, 6, 74, 23, 45, 6};
    Solution s;
    cout << s.largest(arr) << endl;
    return 0;
}