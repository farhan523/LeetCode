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
    int sum = 0;
    void leftNode(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            sum += root->val;
            return;
        }
        leftNode(root->left);
        rightNode(root->right);
    }

    void rightNode(TreeNode *root)
    {
        if (root == NULL)
            return;
        leftNode(root->left);
        rightNode(root->right);
    }

    public:
        int sumOfLeftLeaves(TreeNode *root)
        {
            if (root->left == NULL and root->right == NULL)
                return 0;
            leftNode(root->left);
            rightNode(root->right);
            return sum;
        }
};