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
public:
    
    TreeNode* findNode(TreeNode* root,int val){
        if(root == NULL)
            return NULL;
        if(root->val == val)
            return root;
        if(root->val > val)
            return findNode(root->left,val);
        return findNode(root->right,val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* newTree = findNode(root,val);
        return newTree;
    }
};