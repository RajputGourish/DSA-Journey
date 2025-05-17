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
/*
    Problem link ->
                https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
*/
void sortColors(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
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