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
    vector<int> res;

    public:
        vector<int> rightSideView(TreeNode *root) {
             if(root == NULL)
                return res;
             queue<TreeNode*> q;
            vector<vector < int>> result;
           
            q.push(root);
            while (!q.empty())
            {
                vector<int> temp;
                int k = q.size();
                for (int i = 0; i < k; i++)
                {
                    temp.push_back(q.front()->val);
                    if (q.front()->left != NULL)
                        q.push(q.front()->left);
                    if (q.front()->right != NULL)
                        q.push(q.front()->right);
                    q.pop();
                }

                result.push_back(temp);
            }
            for(int i=0;i<result.size();i++){
                res.push_back(result[i][result[i].size() - 1]);
            }
            return res;
        }
};