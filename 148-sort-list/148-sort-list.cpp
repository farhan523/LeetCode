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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
                return head;
        ListNode *tempHead = head;
        vector<int>arr;
        while(tempHead != NULL){
            arr.push_back(tempHead->val);
            tempHead = tempHead->next;
        }
         sort(arr.begin(), arr.end());
        tempHead = head;
        int i =0;
       
        while(tempHead != NULL){
            tempHead->val = arr[i++];
            tempHead = tempHead->next;
        }
        
        return head;
    }
};