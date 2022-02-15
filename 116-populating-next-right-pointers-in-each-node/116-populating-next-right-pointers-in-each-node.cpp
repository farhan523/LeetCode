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
        queue<Node*>tmp;
        vector<Node*>aux;
        if(root == NULL)
            return root;
        tmp.push(root);
        while(!tmp.empty()){
            
                if(tmp.front()->left != NULL)
                    tmp.push(tmp.front()->left);
                 if(tmp.front()->right != NULL)
                    tmp.push(tmp.front()->right);
               aux.push_back(tmp.front());
                tmp.pop();
            
        }
        int level = 0;
        for(int i=0;i<aux.size()-1 ;i++){
            int j = 0;
            while(j < pow(2,level)){
                if(j+1 == pow(2,level)){
                    aux[i]->next = NULL;
                    
                    break;
                }
                aux[i]->next = aux[i + 1];
                j++;
                i++;
            }
            level++;
        }
        aux[aux.size() - 1]->next = NULL;
      
        return root;
    }
};