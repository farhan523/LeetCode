/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

// return 1 if found p 
// return 2 if found q
// return 0 if found both
// return -1 if none
class Solution
{

    TreeNode *result = NULL;

    int depthFirstSearch(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return -1;
    int leftFound, rightFound;
    leftFound = depthFirstSearch(root->left, p, q);
    rightFound = depthFirstSearch(root->right, p, q);

    if (leftFound == -1 && rightFound == -1 && root->val != p->val && root->val != q->val)
        return -1;
    if ((leftFound == 1 && rightFound == 2) || (leftFound == 2 && rightFound == 1))
    {
        if (result == NULL)
            result = root;
        return 0;
    }

    if (leftFound == -1 && rightFound == -1)
    {
        if (root->val == p->val)
            return 1;
        return 2;
    }

    if (leftFound == -1)
    {
        if (root->val == q->val && rightFound == 1)
        {
            if (result == NULL)
                result = root;
            return 0;
        }
        if (root->val == p->val && rightFound == 2)
        {
            if (result == NULL)
                result = root;
            return 0;
        }
        return rightFound;
    }

    if (rightFound == -1)
    {
        if (root->val == q->val && leftFound == 1)
        {
            if (result == NULL)
                result = root;
            return 0;
        }
        if (root->val == p->val && leftFound == 2)
        {
            if (result == NULL)
                result = root;
            return 0;
        }
        return leftFound;
    }
        return 22;
}
    public:
        TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            depthFirstSearch(root, p, q);
            return result;
        }
};