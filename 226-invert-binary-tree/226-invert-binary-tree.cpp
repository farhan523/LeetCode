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
     void isSym(TreeNode*&root){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
                return;
         TreeNode* temp;
         if(root->left != NULL && root->right != NULL){
             temp = root->left;
             root->left = root->right;
             root->right = temp;
             isSym(root->left);
             isSym(root->right);
         }else if(root->left == NULL){
             root->left = root->right;
             root->right = NULL;
             isSym(root->left);
         }else if(root->right == NULL){
             root->right = root->left;
             root->left = NULL;
             isSym(root->right);           

         }
       
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL )
            return root;
         isSym(root);
        return root;
    }
};