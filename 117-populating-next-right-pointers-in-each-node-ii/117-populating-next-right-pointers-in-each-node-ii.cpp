/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return {};
        vector<Node*>res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                if(q.front()->left)
                    q.push(q.front()->left);
                 if(q.front()->right)
                    q.push(q.front()->right);
                res.push_back(q.front());
                q.pop();
                size--;
            }
            res.push_back(NULL);
        }
        
        for(int i=0;i<res.size()-1;i++){
            if(res[i] != NULL)
                res[i]->next = res[i+1];
           
        }
        return res[0];
    }
};