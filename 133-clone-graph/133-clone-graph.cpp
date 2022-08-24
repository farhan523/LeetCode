/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{

    vector<Node*> visited;
    void depthFirstSearch(Node *node, Node *newNode)
    {
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (visited[node->neighbors[i]->val - 1] == NULL)
            {
                Node *newNode2 = new Node(node->neighbors[i]->val);
                visited[node->neighbors[i]->val - 1] = newNode2;
                newNode->neighbors.push_back(newNode2);
                depthFirstSearch(node->neighbors[i], newNode2);
            }
            else
            {
                newNode->neighbors.push_back(visited[node->neighbors[i]->val - 1]);
            }
        }
    }

    public:
        Node* cloneGraph(Node *node)
        {
            if (node == NULL)
                return NULL;
            vector<Node*> temp(100, NULL);
            visited = temp;
            Node *copyNode = new Node(node->val);
            visited[node->val - 1] = copyNode;
            depthFirstSearch(node, copyNode);

            return copyNode;
        }
};