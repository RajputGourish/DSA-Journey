#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link ->
            https://leetcode.com/problems/move-zeroes
*/

void Display(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Brute_ZeroEnd_array(vector<int> &a)
{
    int n = a.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++)
    {
        a[i] = temp[i];
    }
    for (int i = nz; i < n; i++)
    {
        a[i] = 0;
    }

    // Time Complexity = O(2*N)
    // Space Complexity = O(N)
}

void Optimal_ZeroEnd_Array(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr{1, 0, 2, 3, 2, 0, 0, 4, 3, 1};
    // vector<int> arr{1,1,1,1,1,1,1,2,22,12,2,3};
    Display(arr, arr.size());
    // Brute_ZeroEnd_array(arr);
    Optimal_ZeroEnd_Array(arr);
    Display(arr, arr.size());

    return 0;
}