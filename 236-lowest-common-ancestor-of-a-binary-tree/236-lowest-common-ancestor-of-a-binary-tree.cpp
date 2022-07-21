/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    vector<int>ancestor1;
    vector<int>ancestor2;
    bool found = false;
    unordered_map<int,TreeNode*>mp;
    void depthFirstSearch(TreeNode* root,TreeNode* p,vector<int>&ancestor){
        if(root == NULL)
            return;
         ancestor.push_back(root->val);
        if(mp.find(root->val) == mp.end())
                mp.insert({root->val,root});
        if(root->val == p->val){
           
            found = true;
            return;
        }
         depthFirstSearch(root->left,p,ancestor);
        if(found)
            return;
       
        depthFirstSearch(root->right,p,ancestor);
        if(found)
            return;
        ancestor.pop_back();
        
            
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        depthFirstSearch(root,p,ancestor1);
        found = false;
        depthFirstSearch(root,q,ancestor2);
        set<int>st(ancestor1.begin(),ancestor1.end());
        for(int i=ancestor2.size()-1;i>-1;i--){
            if(st.find(ancestor2[i]) != st.end()){
                return mp.find(ancestor2[i])->second;
                break;
            }
                
        }
        return root;
    }
};