/*
// Definition for a Node.
class Node {
public:
    int val;
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
    int maxDepth(Node* root) {
        //广度搜索
        if(root == NULL)
            return 0;
        int depth = 0;
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            depth ++;
            int size = que.size();
            while(size--)
            {
                Node* node = que.front();
                que.pop();
                for(auto it : node->children)
                    que.push(it);
            }
        }
        return depth;
    }
};