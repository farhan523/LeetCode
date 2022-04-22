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
    vector<vector<int>> res;
    vector<int>temp;
    int sum = 0;
    int target = 0;
    void search(TreeNode* root){
        if(root == NULL )
            return;
        if(root->left == NULL and root->right == NULL){
            sum += root->val;
            temp.push_back(root->val);
            if(sum == target)
                res.push_back(temp);
            sum -= root->val;
            temp.pop_back();
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        search(root->left);
         search(root -> right);
        sum -= root->val;
        temp.pop_back();
       
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        
        search(root);
        return res;
    }
};