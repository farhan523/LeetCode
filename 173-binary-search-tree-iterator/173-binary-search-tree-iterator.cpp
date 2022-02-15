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
class BSTIterator {
    vector<int>nodes;
    int index = -1;
    void inorderTraversal(TreeNode* root){
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        nodes.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
    }
    
    int next() {
        return nodes[++index];
    }
    
    bool hasNext() {
        return index + 1 <= nodes.size()-1 ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */