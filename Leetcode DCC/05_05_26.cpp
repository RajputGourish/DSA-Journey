#include<iostream>
#include<vector>
using namespace std;
/*
Problem Link =>
              https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05
*/

class Solution {
public:
    ListNode* findlasTnode(ListNode* temp, int k){
        int cnt = 1;
        while(temp!= nullptr){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k  = k % len;
        tail->next = head;
        ListNode* lastnode = findlasTnode(head, len-k);
        head = lastnode->next;
        lastnode->next = nullptr;

        return head;
    }
};

int main(){
    
    return 0;
}