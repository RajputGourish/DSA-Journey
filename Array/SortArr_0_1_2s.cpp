#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    Problem link->
                https://leetcode.com/problems/sort-colors
*/
void Brute_sortColors(vector<int> &arr)
{
    int n = arr.size();
    int countzero = 0;
    int countone = 0;
    int counttwo = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            countzero++;
        }
        else if (arr[i] == 1)
        {
            countone++;
        }
        else
        {
            counttwo++;
        }
    }
    int index = 0;
    while (countzero > 0)
    {
        arr[index] = 0;
        countzero--;
        index++;
    }
    while (countone > 0)
    {
        arr[index] = 1;
        countone--;
        index++;
    }
    while (counttwo > 0)
    {
        arr[index] = 2;
        counttwo--;
        index++;
    }

    // Time Complexity = O(2N)
    // Space Complexity = O(1)
}

void Optimal_sortColors(vector<int> &arr)
{
    //  Three pointer --->   Dutch National Flag algorithm

    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}


int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    display(arr);

    Brute_sortColors(arr);
    display(arr);

    Optimal_sortColors(arr);
    display(arr);

    return 0;
}