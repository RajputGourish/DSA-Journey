#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countnoofPairs(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int remaining = target - arr[i];
        if (mpp.find(remaining) != mpp.end())
        {
            ans += mpp[remaining];
        }

        mpp[arr[i]]++;
    }

    return ans;
}

int main()
{
    vector<int> vowel_vector = {2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 3, 2, 3, 4, 3, 3, 4, 4, 4, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 5};
    vector<std::string> words_vector = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty",
        "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty",
        "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty",
        "fifty-one", "fifty-two", "fifty-three", "fifty-four", "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine", "sixty",
        "sixty-one", "sixty-two", "sixty-three", "sixty-four", "sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine", "seventy",
        "seventy-one", "seventy-two", "seventy-three", "seventy-four", "seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine", "eighty",
        "eighty-one", "eighty-two", "eighty-three", "eighty-four", "eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine", "ninety",
        "ninety-one", "ninety-two", "ninety-three", "ninety-four", "ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine", "one hundred"};
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vowel_vector[arr[i]];
    }

    int pairs = countnoofPairs(arr, sum);
    if (pairs > 100)
    {
        cout << "greater 100" << endl;
    }
    else
    {
        cout << words_vector[pairs] << endl;
    }

    return 0;
}