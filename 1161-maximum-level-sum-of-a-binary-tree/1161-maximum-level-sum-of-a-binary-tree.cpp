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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>tmp;
        tmp.push(root);
        int num = 1;
        int maxLevel = 1;
        int soFarSum = root->val;
        int levelSum = 0;
        int nowLevel = 0;
        while(tmp.size() != 0){
            int tempNum = num;
            nowLevel++;
             levelSum = 0;
            while(tempNum > 0){
               
                levelSum += (tmp.front()->val);
                if(tmp.front()->left != NULL){
                    num++;
                    tmp.push(tmp.front() ->left);
                }
                if(tmp.front() ->right != NULL){
                    num++;
                    tmp.push(tmp.front() ->right);
                }
                tmp.pop();
                num--;
                tempNum--;
            }
            if(levelSum > soFarSum){
                soFarSum = levelSum;
                maxLevel = nowLevel;
            }
        }
        return maxLevel;
    }
};