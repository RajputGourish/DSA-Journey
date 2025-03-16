#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // Two pointer
        vector<int> ans;
        int n = a.size(),
            m = b.size(),
            i = 0,
            j = 0;

        while (i < n && j < m)
        {
            if (i != 0 && a[i] == a[i - 1])
            {
                i++;
                continue;
            }
            if (j != 0 && b[j] == b[j - 1])
            {
                j++;
                continue;
            }
            if (a[i] <= b[j])
            {
                if (a[i] == b[j])
                {
                    j++;
                }
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        while (i < n)
        {
            if (i != 0 && a[i] == a[i - 1])
            {
                i++;
                continue;
            }
            ans.push_back(a[i]);
            i++;
        }
        while (j < m)
        {
            if (j != 0 && b[j] == b[j - 1])
            {
                j++;
                continue;
            }
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};
    Solution s;
    vector<int> ans = s.findUnion(a, b);
    print(ans);
    return 0;
}