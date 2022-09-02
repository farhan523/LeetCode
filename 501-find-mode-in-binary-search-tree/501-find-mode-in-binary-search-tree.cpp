class Solution {
	unordered_map<int,int> a;
	void chk(TreeNode* root){
		if(!root) return;
		a[root->val]++;
		chk(root->left);
		chk(root->right);
	}

public:
	vector<int> findMode(TreeNode* root) {
		if(!root) return {};

		chk(root);

		priority_queue<pair<int,int>> q;
		for(auto i : a) q.push({i.second,i.first});

		vector<int> ans;
		int aa = q.top().first;
		while(!q.empty() && aa == q.top().first) {
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};