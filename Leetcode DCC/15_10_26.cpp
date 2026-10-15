#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Brute
int Brute_sumCounts(vector<int> &n)
{
    // generate all subarray
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = i; j < n.size(); j++)
        {
            unordered_set<int> st;
            for (int k = i; k <= j; k++)
            {
                st.insert(n[k]);
            }
            sum += st.size() * st.size();
        }
    }
    return sum;

    // Time Complexity = O(N^3)
    // Space Complexity = O(1)
}

// Better
int Better_sumCounts(vector<int> &n)
{
    // generate all subarray
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        unordered_set<int> st;
        for (int j = i; j < n.size(); j++)
        {
            st.insert(n[j]);
            sum += st.size() * st.size();
        }
    }
    return sum;

    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
}

int main()
{
    vector<int> arr = {1, 2, 1};
    // vector<int> arr = {1, 1};
    cout << Better_sumCounts(arr) << endl;

    return 0;
}