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
    string s;
    vector<string> res;
    void postOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            string str = to_string(root->val);
            for (auto x: str)
                s.push_back(x);
            res.push_back(s);
            for (auto x: str)
                s.pop_back();
            return;
        }
        string str = to_string(root->val);
        for (auto x: str)
            s.push_back(x);
        s.push_back('-');
        s.push_back('>');
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        for (auto x: str)
            s.pop_back();
        s.pop_back();
        s.pop_back();
    }
    public:

        vector<string> binaryTreePaths(TreeNode *root)
        {
            postOrderTraversal(root);
            return res;
        }
};