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
    vector<int>res;
    bool inorderTraversal(TreeNode* root){
         if(root == NULL)
            return true;
        bool r1,r2;
        if(root->left != NULL && root->left->val >= root->val)
            return false;
        else
            r1 = inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right != NULL && root->right->val <= root->val)
            return false;
        else
            r2 = inorderTraversal(root->right);
        return r1&&r2;
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(!inorderTraversal(root))
            return false;
        for(int i=1;i<res.size();i++){
            cout<<res[i];
            if(res[i] <= res[i-1])
                return false;
        }
        return true;
    }
};