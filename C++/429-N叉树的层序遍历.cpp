/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> nowFloor;//装当前层
            int len = que.size();
            for(int i=0;i<len;i++)
            {
                Node* node = que.front();
                que.pop();
                nowFloor.push_back(node->val);
                for(int j=0;j<node->children.size();j++)
                    que.push(node->children[j]);
            }
            result.push_back(nowFloor);
        }
        return result;
    }
};