#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int last = -1;
        int slast = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (last < arr[i])
            {
                slast = last;
                last = arr[i];
            }
            else
            {
                if (slast < arr[i] && arr[i] != last)
                {
                    slast = arr[i];
                }
            }
        }
        return slast;
    }
};
int main()
{
    vector<int> arr = {2, 3, 4, 565, 23, 234, 54, 66};
    Solution s;
    cout << s.getSecondLargest(arr) << endl;

    return 0;
}