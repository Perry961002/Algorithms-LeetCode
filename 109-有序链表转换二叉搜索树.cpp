/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
public:
    /*
    TreeNode* treebuild(ListNode* start, ListNode* end)
    {
        if(start == end)
            return NULL;
        ListNode* fast = start;
        ListNode* slow = start;
        while(fast!=end && fast->next!=end)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = treebuild(start, slow);
        node->right = treebuild(slow->next, end);
        return node;   
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return treebuild(head, NULL);
    }
    */
    TreeNode* build(vector<int>& num, int start, int end)
    {
        if(start==end)
            return new TreeNode(num[start]);
        if(start>end)
        {
            return NULL;
        }
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = build(num, start,mid-1);
        root->right = build(num,mid+1,end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* node = head;
        vector<int> vec;
        while(node != NULL){
            vec.push_back(node->val);
            node = node->next;
        }
        return build(vec,0,(int)vec.size()-1);
    }

};