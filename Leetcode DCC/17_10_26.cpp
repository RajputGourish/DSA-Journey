#include <iostream>
#include <vector>
using namespace std;
int digitsum(int num)
{
    int sum = 0;

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    vector<int> sortedNums = nums;

    sort(sortedNums.begin(), sortedNums.end(),
         [&](int a, int b)
         {
             if (digitsum(a) == digitsum(b))
                 return a < b;

             return digitsum(a) < digitsum(b);
         });

    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++)
    {
        pos[sortedNums[i]] = i;
    }

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        int j = i;
        int cycleSize = 0;

        while (!visited[j])
        {
            visited[j] = true;

            j = pos[nums[j]];

            cycleSize++;
        }

        if (cycleSize > 1)
            swaps += cycleSize - 1;
    }

    return swaps;
}

int main()
{

    return 0;
}