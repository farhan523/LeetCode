/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> largestValues(TreeNode *root)
        {
            if(root == NULL)
                return {};
            vector<int> res;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int size = q.size();
                int largest = INT_MIN;
                while (size > 0)
                {
                    if (q.front()->left)
                        q.push(q.front()->left);
                    if (q.front()->right)
                        q.push(q.front()->right);
                    if (q.front()->val > largest)
                        largest = q.front()->val;
                    q.pop();
                    size--;
                }
                res.push_back(largest);
            }
            return res;
        }
};