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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* newNode = new TreeNode;
        newNode->val = val;
        if(root == NULL){
           root = newNode;
        }else{
            TreeNode* tempRoot = root;
            while(tempRoot != NULL){
                if(tempRoot->val > val){
                    if(tempRoot->left == NULL){
                         tempRoot->left = newNode;
                        break;
                    }
                    tempRoot = tempRoot->left;   
                }else{
                    if(tempRoot->right == NULL){
                         tempRoot->right = newNode;
                        break;
                    }
                    tempRoot = tempRoot->right; 
                }
            }
        }
        return root;
    }
};