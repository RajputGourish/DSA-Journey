#include <iostream>
#include <vector>
using namespace std;
/*
    Problem link ->
                https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
*/

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// rotate array by one place clockwise
void rotate_Clockwise(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

// rotate array by one place anticlockwise
void rotate_AntiClockwise(vector<int> &arr)
{
    int temp = arr[0];
    int n = arr.size();

    for (int i = 0; i <= n - 2; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    display(arr);
    rotate_Clockwise(arr);
    display(arr);
    rotate_AntiClockwise(arr);
    display(arr);

    return 0;
}