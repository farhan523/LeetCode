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
    vector<TreeNode*>nodesList;
    void preOrderTraversal(TreeNode* &root){
        if(root == NULL)
            return;
        nodesList.push_back(root);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    
public:
    void flatten(TreeNode* root) {
        if(root== NULL || (root->left == NULL && root->right == NULL))
            return;
        preOrderTraversal(root);
        for(int i=0;i<=nodesList.size() - 2;i++){
            nodesList[i]->right = nodesList[i+1];
            nodesList[i]->left = NULL;
        }
        nodesList[nodesList.size() - 1]->left = NULL;
        nodesList[nodesList.size() - 1]->right = NULL;
    }
};