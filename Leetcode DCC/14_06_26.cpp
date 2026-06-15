#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Problem Link ->
              https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int value, ListNode *nextptr)
    {
        this->val = value;
        this->next = nextptr;
    }
};

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pairSum(ListNode *head)
{
    int maxsum = INT_MIN;
    vector<int> copy;
    ListNode *curr = head;
    
    while (curr != nullptr)
    {
        copy.push_back(curr->val);
        curr = curr->next;
    }
    int n = copy.size();

    for (int i = 0; i <= n / 2; i++)
    {
        maxsum = max(maxsum, copy[i] + copy[n - 1 - i]);
    }

    // display(copy);
    // cout << "maxsum is = " << maxsum << endl;

    return maxsum;
    
    // Time Complexity = O(N)
    // Space Complexity = O(N) -< we have to optimize it
}

int main()
{
    ListNode *N = new ListNode(5, nullptr);
    N->next = new ListNode(4, nullptr);
    N->next->next = new ListNode(2, nullptr);
    N->next->next->next = new ListNode(1, nullptr);

    pairSum(N);

    return 0;
}