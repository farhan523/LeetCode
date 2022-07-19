/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
     stringstream ss;
    string s = "";
    int sum = 0;
    int num;
    
    void preOrderTraversal(TreeNode* root){
        if(root == NULL)
            return;
        s += to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            ss << s;  
            ss >> num; 
            cout<<num<<" ";
            sum += num;
            ss.clear();
            s.pop_back();
            return;
        }
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
        s.pop_back();
            
    }
public:
    int sumNumbers(TreeNode* root) {
        preOrderTraversal(root);
        return sum;
    }
};