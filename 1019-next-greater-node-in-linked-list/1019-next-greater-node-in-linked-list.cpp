/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    int count = 0;
    ListNode *head = NULL;
    ListNode* reverse(ListNode *node)
    {
        count++;
        if (node == NULL)
            return NULL;
        if (node->next == NULL)
        {
            head = node;
            return node;
        }

        ListNode *node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }
    public:
        vector<int> nextLargerNodes(ListNode *head)
        {
            reverse(head);
            vector<int> res;
            stack<int> st;

            head = this->head;
            while (head)
            {
                while (st.size() && st.top() <= head->val) st.pop();
                if (st.empty()) res.push_back(0);
                else
                    res.push_back(st.top());

                st.push(head->val);
                head = head->next;
            }
             ::reverse(res.begin(),res.end());
            return res;
        }
};