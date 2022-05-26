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
    public:
        vector<double> averageOfLevels(TreeNode *root)
        {
            queue<TreeNode*> q;
            vector<double> result;
            if (root == NULL)
                return result;
            q.push(root);
            while (!q.empty())
            {
                double sum = 0.0;
                int k = q.size();
                for (int i = 0; i < k; i++)
                {
                    sum += q.front()->val;
                    if (q.front()->left != NULL)
                        q.push(q.front()->left);
                    if (q.front()->right != NULL)
                        q.push(q.front()->right);
                    q.pop();
                }
                double avg = sum / k;
                result.push_back(avg);
            }

            return result;
        }
};