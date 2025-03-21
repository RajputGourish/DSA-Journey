#include <iostream>
#include <vector>
using namespace std;
void Display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void recursion_Insert(vector<int> &arr, int index, int n)
{
    // base case
    if (index == n)
        return;
    int i = index;
    while (i > 0 && arr[i] < arr[i - 1])
    {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;

        i--;
    }
    // recursion call
    recursion_Insert(arr, index + 1, n);
    
    // Time Complexity = O(N^2)
    // Auxillary Space Complexity = O(N)
}

int main()
{
    vector<int> arr = {4, 1, 0, 8, 5, 9};
    Display(arr);
    recursion_Insert(arr, 1, arr.size());
    Display(arr);

    return 0;
}