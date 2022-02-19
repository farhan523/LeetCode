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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>tem;
        ListNode* temp = head;
        while(temp != NULL){
            tem.push_back(temp->val);
            temp = temp->next;
        }
        // k = k -1;
        int count = 0;
        int sec ;
        for(int i = tem.size() - 1;i>=0;i--){
            count++;
            if(count == k){
                sec = i + 1;
                int temp = tem[i];
                tem[i] = tem[k -1];
                tem[k -1] = temp;
            }
        }
        temp = head;
        int i = 0;
        while(temp != NULL){
            if(temp->val != tem[i])
                temp->val = tem[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};