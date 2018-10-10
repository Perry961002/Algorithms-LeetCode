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
    /********************************
    //递归法
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        //根节点
        res.push_back(root->val);
        if(!root->children.empty()){
            //依次访问子节点
            for(auto chil : root->children){
                vector<int> tmp = preorder(chil);
                for(int i=0;i<tmp.size();i++)
                    res.push_back(tmp[i]);
            }
        }
        return res;
    }
    ********************************/
    //迭代法
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* curNode = s.top();
            s.pop();
            res.push_back(curNode->val);
            int len = curNode->children.size();
            for(int i=len-1;i>=0;i--)
                s.push(curNode->children[i]);
        }
        return res;
    }
};