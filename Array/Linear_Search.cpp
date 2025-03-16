#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchInSorted(vector<int> &arr, int k)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == k)
                return true;
        }
        return false;
    }
};
int main()
{
    vector<int> arr = {1, 2, 4, 5, 45, 32, 56, 3};
    Solution s;
    cout << s.searchInSorted(arr, 3) << endl;

    return 0;
}