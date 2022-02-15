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
class Solution {
public:
    int num = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
             return head;
        }
       ListNode* setNode = removeNthFromEnd(head->next,n);
           ++num;
        if(num == n){
            ListNode* next = head->next;
            delete head;
            return next;
        }
        if(num == n + 1)
            head->next = setNode;
        
        return head;
            
    }
};