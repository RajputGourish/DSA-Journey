#include <iostream>
#include <vector>
using namespace std;

/*
    Problem link -> https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14
*/

class node
{
public:
    int value;
    node *next;
    node(int val)
    {
        this->value = val;
        next = nullptr;
    }
    node(int val, node *next)
    {
        this->value = val;
        this->next = next;
    }
};

node *convertvecToLL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

class Solution
{
public:
    //  Brute
    int BrutegetDecimalValue(node *head)
    {
        int ans = 0;
        string bn = "";
        node *temp = head;
        while (temp != nullptr)
        {
            bn += to_string(temp->value);
            temp = temp->next;
        }

        int size = bn.size();
        for (int i = size - 1; i >= 0; i--)
        {
            int index = size - i - 1;

            if (bn[i] == '1')
            {
                ans = ans + (1 << index);
            }
        }

        return ans;

        // Time Complexity = O(2n)
        // Space Complexity = O(n)
    }

    // OPTIMAL
    int OptimalgetDecimalValue(node *head)
    {
        int ans = 0;
        node *temp = head;
        node *back = nullptr;
        node *front = nullptr;

        while (temp != nullptr)
        {
            front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }

        temp = back;
        int ind = 0;
        while (temp != nullptr)
        {
            if (temp->value == 1)
            {
                ans = ans + (1 << ind);
            }
            ind++;
            temp = temp->next;
        }
        return ans;

        // Time Complexity = O(2n)
        // Space Complexity = O(1)
    }
};
int main()
{
    vector<int> arr = {1, 0, 1};
    node *head = convertvecToLL(arr);

    Solution s;
    cout << "The decimal number = "
         << s.BrutegetDecimalValue(head) << endl;
    cout << "The decimal number = "
         << s.OptimalgetDecimalValue(head) << endl;

    return 0;
}