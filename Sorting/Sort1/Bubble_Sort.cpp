#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
            https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
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

// Sorting the array
void Bubble_Sort(vector<int> &arr)
{
    int n = arr.size(); // size of the array

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1]) // swap the value if left is greater than right
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {4, 6, 3, 7, 2, 9, 8, 14, 12, 15, 1};
    print(arr);
    Bubble_Sort(arr);
    print(arr);
    return 0;
}