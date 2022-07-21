/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* result = NULL;
    void inorderTraversal(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return;
        if(root->val == p->val || root->val == q->val){
            if(result == NULL)
                result = root;
            return;
        }
        if(root->val > p->val and root->val < q->val || root->val < p->val and root->val > q->val){
             if(result == NULL)
                result = root;
            return;
        }
        if(root->val > p->val){
            inorderTraversal(root->left,p,q);
            return;
        }
        inorderTraversal(root->right,p,q);
            
            
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       inorderTraversal(root,p,q);
        return result;
    }
};