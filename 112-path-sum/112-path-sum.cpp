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
    bool depthFirstSearch(TreeNode* root, int targetSum,int &soFarSum){
        soFarSum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(soFarSum == targetSum)
                return true;
            return false;
        }
        bool r1 = false,r2 = false;
        if(root->left != NULL){
           r1 =  depthFirstSearch(root->left,targetSum,soFarSum);
            soFarSum -= root->left->val;
        }
         if(root->right != NULL){
           r2 =  depthFirstSearch(root->right,targetSum,soFarSum);
            soFarSum -= root->right->val;
        }
        return r1 || r2 ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL )
            return false;
         
        int soFarSum = 0;
        return depthFirstSearch(root,targetSum,soFarSum);
    }
};