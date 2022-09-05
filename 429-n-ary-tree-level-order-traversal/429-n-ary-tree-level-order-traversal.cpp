/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {
            if(root == NULL)
                return {};
            vector<vector < int>> res;
            queue<Node*> q;
            q.push(root);
            while (!q.empty())
            {
                int size = q.size();
                vector<int> temp;
                while (size > 0)
                {
                    temp.push_back(q.front()->val);
                    for (int i = 0; i < q.front()->children.size(); i++)
                    {
                        q.push(q.front()->children[i]);
                    }
                    q.pop();
                    size--;
                }
                res.push_back(temp);
            }
            return res;
        }
};