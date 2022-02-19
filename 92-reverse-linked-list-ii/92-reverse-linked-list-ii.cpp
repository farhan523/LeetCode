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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> arr;
        left = left - 1;
        right = right - 1;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int l = left;
        int r = right;
        while(l <= r){
            int tem = arr[r];
            arr[r] = arr[l];
            arr[l] = tem;
            l++;
            r--;
        }
        temp = head;
       for(int i=0;i<arr.size();i++){
           if(i >=left && i<=right){
               temp->val = arr[i];
           }
           temp = temp->next;
       }
        return head;
    }
};