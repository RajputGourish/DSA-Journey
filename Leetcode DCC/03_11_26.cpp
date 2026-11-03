#include <iostream>
#include <vector>
using namespace std;

int minMoves(vector<int> &nums)
{
    int ans = 0;
    if (nums.size() == 0)
        return ans;
    int maxiel = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxiel = max(maxiel, nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        ans += maxiel - nums[i];
    }

    return ans;

    // Time Complexity = O(2N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {2, 1, 3};

    return 0;
}