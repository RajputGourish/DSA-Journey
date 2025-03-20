#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link ->
            https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
*/
void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> Temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            Temp.push_back(arr[left]);
            left++;
        }
        else
        {
            Temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        Temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        Temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = Temp[i - low];
    }
}
void Merge_Sort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    Merge_Sort(arr, low, mid);
    Merge_Sort(arr, mid + 1, high);
    Merge(arr, low, mid, high);

    // Time Complexity = O(NlogN) ->
    // Space Complexity = O(N) -> storing element in temp
    // Auxiliary Space Complexity: O(n)
}

void Display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = v.size();
    Display(v);
    Merge_Sort(v, 0, n - 1);
    Display(v);
    return 0;
}