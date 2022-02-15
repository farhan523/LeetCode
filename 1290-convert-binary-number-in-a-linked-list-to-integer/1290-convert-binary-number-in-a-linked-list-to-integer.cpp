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

#include <cmath>


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int>stk;
        while(head != NULL){
            stk.push_back(head->val);
            cout<<head->val;
            head = head->next;
        }
        int j =0;
        int sum = 0;
        for(int i=stk.size() - 1;i>=0;i--){
            sum += (stk[i] * pow(2,j));
            j++;
            
           
            
        }
        return sum;
    }
};