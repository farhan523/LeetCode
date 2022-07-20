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
    int maxHeight = 0;
    int max = 0;
    void depthFirstSearch(Node *root)
    {
        max++;
        for (int i = 0; i < root->children.size(); i++)
        {
            depthFirstSearch(root->children[i]);
        }
        if (max > maxHeight)
            maxHeight = max;
        max--;
    }
    public:
        int maxDepth(Node *root)
        {
            if (root == NULL)
                return 0;
            depthFirstSearch(root);
            return maxHeight;
        }
};