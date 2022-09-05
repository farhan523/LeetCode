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
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)
                return {};
            queue<TreeNode*> q;
            q.push(root);
            int Sum;

            while (!q.empty())
            {
                int size = q.size();
                bool isFirst = true;
                int levelSum = 0;
                while (size > 0)
                {
                    if (q.front()->left)
                        q.push(q.front()->left);
                    if (q.front()->right)
                        q.push(q.front()->right);
                   
                    levelSum += q.front()->val;
                    q.pop();
                    size--;
                }
                Sum = levelSum;
            }
            return Sum;
    }
};