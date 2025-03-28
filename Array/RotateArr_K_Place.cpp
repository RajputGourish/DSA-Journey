#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
                https://leetcode.com/problems/rotate-array/description/
*/

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void k_Right_Rotate_Brute(vector<int> &arr, int n, int k)
{
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i]; // 3 4 5
    }

    // shifting
    for (int j = k; j < n; j++)
    {
        arr[j] = arr[j - k];
    }
    // put temp to arr
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
    // Time Complexity = O(2N)
    // Space Complexity = O(N)
}

void Reverse(vector<int> &arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void k_Right_Rotate_Optimal(vector<int> &arr, int n, int k)
{
    k = k % n;
    Reverse(arr, 0, n - k - 1);
    Reverse(arr, n - k, n - 1);
    Reverse(arr, 0, n - 1);

    // Time Complexity = O(2N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = arr.size();
    k_Right_Rotate_Brute(arr, n, k);
    k_Right_Rotate_Optimal(arr, n, k);

    display(arr);

    return 0;
}