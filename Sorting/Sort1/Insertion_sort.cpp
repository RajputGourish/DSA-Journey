#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
            https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort
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
void insertion_Sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    // Time Complexity = O(N^2) -> worst case
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {4, 6, 3, 7, 2, 9, 8, 14, 12, 15, 1};
    print(arr);
    insertion_Sort(arr);
    print(arr);
    return 0;
}