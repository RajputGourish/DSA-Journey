#include <iostream>
#include <vector>
using namespace std;
// Printing the array
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Bubble_Sort(vector<int> &arr)
{
}
int main()
{
    vector<int> arr = {4, 6, 3, 7, 2, 9, 8, 14, 12, 15, 1};
    print(arr);
    Bubble_Sort(arr);
    print(arr);
    return 0;
}