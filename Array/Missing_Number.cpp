#include <iostream>
#include <vector>
using namespace std;
/*
    Problem Link -> hhttps://leetcode.com/problems/missing-number
*/
int Missing_Number(vector<int> &arr)
{
    int n = arr.size();
    int Xor1 = 0, Xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        Xor1 = Xor1 ^ i;
        Xor2 = Xor2 ^ arr[i];
    }
    Xor1 = Xor1 ^ n;
    return Xor1 ^ Xor2;

    // Time Complexity = O(N)
    // Space Complexity = O(1)
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << Missing_Number(arr) << endl;

    return 0;
}