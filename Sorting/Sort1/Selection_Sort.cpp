#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
    Problem link ->
            https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort
*/
// Printing the array
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Sorting the aaray
void Selection_Sort(vector<int> &arr)
{
    int n = arr.size();
    // range start with whole array and increase by 1
    for (int i = 0; i < n - 1; i++)
    {
        int minind = i;
        for (int j = i; j < n; j++) // inner loop find the minimum value
        {
            if (arr[minind] > arr[j])
                minind = j;
        }
        int temp = arr[minind];
        arr[minind] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    vector<int> arr = {4, 6, 3, 7, 2, 9, 8, 14, 12, 15, 1};
    // vector<int> arr = {4, 6, 3, 7,15,14,15, 2, 9, 8,2,3,4, 14, 12, 15, 1};
    print(arr);
    Selection_Sort(arr);
    print(arr);
    return 0;
}