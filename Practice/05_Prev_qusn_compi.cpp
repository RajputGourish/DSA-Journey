#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/remove-duplicates-from-sorted-array/description
*/

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int i = 1; // Points to the next position to write a unique element

    for (int j = 1; j < nums.size(); j++)
    {
        // If the current element is different from the previous one, it's unique
        if (nums[j] != nums[j - 1])
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main()
{

    return 0;
}