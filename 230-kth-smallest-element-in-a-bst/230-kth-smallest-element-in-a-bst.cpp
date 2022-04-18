/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    vector<int> res;
    void inOrderTraversal(TreeNode *root)
    {

        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        res.push_back(root->val);
        inOrderTraversal(root->right);
    }
    public:
        int kthSmallest(TreeNode *root, int k)
        {
            inOrderTraversal(root);
            int temp = res[k - 1];
            return temp;
        }
};