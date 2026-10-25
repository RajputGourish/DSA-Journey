#include <iostream>
#include <vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/valid-palindrome/description/
*/

bool checkpalindrome(string filter)
{
    int i = 0;
    int j = filter.size() - 1;
    while (i < j)
    {
        if (filter[i] != filter[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool isPalindrome1(string s)
{
    // filter the string and store in another
    string filter = "";
    for (int c : s)
    {
        if (c >= 65 && c <= 90)
        {
            filter += char(c + 32);
        }
        else if (c >= 97 && c <= 122)
        {
            filter += c;
        }
        else if (c >= 48 && c <= 57)
        {
            filter += c;
        }
    }
    return checkpalindrome(filter);
}

// Optimizesation

bool isalphanum(char c)
{
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57));
}

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(!isalphanum(s[i])){
            i++;
        }
        else if(!isalphanum(s[j])){
            j--;
        }
        else{
            if(tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s = "ab_a";
    cout << isPalindrome(s) << endl;
    // cout<<isalphanum('l')<<endl;
    

    return 0;
}