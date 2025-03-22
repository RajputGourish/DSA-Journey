
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
    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (arr[i] <= pivot && i <= high - 1)
            {
                i++;
            }
            while (arr[j] > pivot && j >= low + 1)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }

public:
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int partitionindex = partition(arr, low, high);
            quickSort(arr, low, partitionindex - 1);
            quickSort(arr, partitionindex + 1, high);
        }

        // Time Complexity = O(NlogN)
        // Space Complexity = O(1)
        // Auxillary stack space = O(N)
    }
};

int main()
{
    vector<int> arr = {4, 1, 3, 9, 7};
    print(arr);
    Solution s;
    s.quickSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}