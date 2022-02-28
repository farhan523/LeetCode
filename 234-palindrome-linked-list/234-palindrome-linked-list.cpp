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

#include<vector>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
                return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow;
        ListNode* prev = NULL;
        while(slow != NULL){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while(true){
            if(head->val != prev->val)
                return false;
            head = head->next;
            if(head == prev && head->val == prev->val)
                return true;
            else if(head == prev){
                return false;
            }
            prev = prev->next;
             if(head == prev && head->val == prev->val)
                return true;
             else if(head == prev){
                return false;
            }
        }
        return true;
    }
};