#include<iostream>
#include<vector>
using namespace std;

/*
Problem Link =>
              https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/2033337911/?envType=daily-question&envId=2026-06-15
*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast != nullptr&& fast->next != nullptr ){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* delnode = slow->next;
        slow->next = slow->next->next;
        delete delnode;
        return head;
    }
};


int main(){
    
    return 0;
}