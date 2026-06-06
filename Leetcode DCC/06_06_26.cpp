#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> leftRightDifference(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int totalsum = 0;
    int leftsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalsum += nums[i];
    }
    int rightsum = totalsum;

    for (int i = 0; i < nums.size(); i++)
    {
        rightsum -= nums[i];
        ans[i] = abs(leftsum - rightsum);
        leftsum += nums[i];
    }

    display(ans);
    return ans;
}


// Time Complexity = O(2N)
// Space Complexity = O(N => for returning the ans)


int main()
{
    vector<int> arr = {1};
    vector<int> ans = leftRightDifference(arr);

    display(arr);

    return 0;
}