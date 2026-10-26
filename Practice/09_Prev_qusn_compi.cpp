#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/sort-colors/description/
*/

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Dutch flag algorithm
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return;
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 2)
        {
            swap(nums[high], nums[mid]);
            high--;
        }
        else if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else
            mid++;
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    display(arr);
    sortColors(arr);
    display(arr);
    return 0;
}