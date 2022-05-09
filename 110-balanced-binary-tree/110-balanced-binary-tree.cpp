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
    int check(TreeNode* root){
        if(root == NULL)
            return 0;
        int r1 =   check(root->left);
        int r2 =  check(root->right);
        if(r1 == -1 || r2 == -1)
            return -1;
        
         return abs(r1 - r2) > 1 ? -1 : 1 + max(r1,r2); 
    }
public:
    bool isBalanced(TreeNode* root) {
       int res = check(root);
        if(res == -1)
            return false;
        return true;
    }
};