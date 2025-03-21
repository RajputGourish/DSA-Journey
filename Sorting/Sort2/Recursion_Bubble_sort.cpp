#include <iostream>
#include <vector>
using namespace std;
void recursion_Bubble(vector<int> &arr, int range)
{
    // base case
    if (range == 1)
        return;

    for (int i = 0; i < range; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    // recursion call
    recursion_Bubble(arr, range - 1);

    // Time Complexity = O(N^2)
    // Auxillary Space Complexity = O(N)
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
    vector<int> arr = {4, 1, 0, 8, 5, 9};
    Display(arr);
    recursion_Bubble(arr, arr.size());
    Display(arr);

    return 0;
}